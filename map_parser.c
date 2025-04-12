/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:33:30 by cwannhed          #+#    #+#             */
/*   Updated: 2025/04/03 14:58:28 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	int	add_line(char *line, t_map *map)
{
	t_list	*new_node;

	new_node = ft_lstnew(line);
	if (!new_node)
		return (0);
	ft_lstadd_back(&map->lines, new_node);
	return (1);
}

static void	handle_error(t_map *map, int fd, char *error_msg)
{
	ft_putstr_fd("Error\n", 2);
	if (fd >= 0 && close(fd) < 0)
		ft_putstr_fd("Warning: Failed to close file descriptor properly.\n", 2);
	if (map->lines)
		ft_lstclear(&map->lines, free);
	ft_putstr_fd(error_msg, 2);
	write(2, "\n", 1);
	return ;
}

void	read_map(const char *path, t_map *map)
{
	int		fd;
	char	*line;

	//map = &((t_map){0});
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		handle_error(map, fd, "Unable to open file");
		return ;
	}
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (!add_line(line, map))
		{
			handle_error(map, fd, "Memory allocation failed in add_line");
			break ;
		}
	}
	if (close(fd) < 0)
		handle_error(map, -1, "Failed to close the file descriptor");
	return ;
}
