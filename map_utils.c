/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 14:49:30 by cwannhed          #+#    #+#             */
/*   Updated: 2025/04/01 18:05:44 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	row_len(char *line)
{
	int	len;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		return  (len - 1);
	return (len);
}

int	no_extra_lines(t_list *map_lines)
{
    int blank_found;

	blank_found = 0;
    while (map_lines)
    {
        if (row_len((char *)map_lines->content) == 0)
            blank_found = 1;
        else if (blank_found)
            return (0);
        map_lines = map_lines->next;
    }
    return (1);
}

void	free_map_matrix(t_map *map)
{
	int	i;
	
	i = 0;
	while (i < map->rows)
	{
		free(map->matrix[i]);
		i++;
	}
	free(map->matrix);
	map->matrix = NULL;
}

void	free_map(t_map *map)
{
	free_map_lines(map);
	free_map_matrix(map);
}

