/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:33:30 by cwannhed          #+#    #+#             */
/*   Updated: 2025/03/20 19:21:02 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_map(const char *path)
{
	int		fd;
	t_list	*line;
	t_list	temp; 

	fd = open(path, O_RDONLY);
	line = ft_lstnew(get_next_line(fd));
	while (line)
	{
		
		line = ft_lstnew(get_next_line(fd));
	}
	if (close(fd))
	{
		ft_putstr_fd("Error\n", 2);
		perror("Error while closing fd in is_directory");
		exit(EXIT_FAILURE);
	}
}
