/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:33:30 by cwannhed          #+#    #+#             */
/*   Updated: 2025/04/01 17:51:42 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	int	add_line(char *line, t_list **head)
{
	t_list	*new_node;
	
	new_node = ft_lstnew(line);
	if (!new_node)
		return (0);
	ft_lstadd_back(head, new_node);
	return (1);
}

static	t_list *handle_error(t_list **head, int fd, char *error_msg)
{
	ft_putstr_fd("Error\n", 2);
	if (fd >= 0 && close(fd) < 0)
		ft_putstr_fd("Warning: Failed to close file descriptor properly.\n", 2);
	if (head && *head)
		ft_lstclear(head, free);
	ft_putstr_fd(error_msg, 2);
	return (NULL);
}

t_list	*read_map(const char *path)
{
	int		fd;
	char	*line;
	t_list	*head; 

	head = NULL;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (handle_error(&head, fd, "Unable to open file"));
	while ((line = get_next_line(fd)) != NULL)
	{
		if (!add_line(line, &head))
			return (handle_error(&head, fd, "Memory allocation failed in add_line"));
	}
	if (close(fd) < 0)
		return (handle_error(&head, -1, "Failed to close the file descriptor"));
	return (head);
}

