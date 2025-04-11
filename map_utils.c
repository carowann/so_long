/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 14:49:30 by cwannhed          #+#    #+#             */
/*   Updated: 2025/04/04 18:48:47 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	row_len(char *line)
{
	int	len;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		return (len - 1);
	return (len);
}

void	free_map_matrix(char **matrix, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
	matrix = NULL;
}

static void	free_map_lines(t_map *map)
{
	t_list	*current;
	t_list	*temp;
	int		count;

	if (!map->lines)
	{
		free(map->lines);
		return ;
	}
	current = map->lines;
	count = ft_lstsize(map->lines);
	while (current)
	{
		temp = current->next;
		free(current->content);
		free(current);
		current = temp;
	}
	map->lines = NULL;
}

void	free_map(t_map *map)
{
	free_map_lines(map);
	free_map_matrix(map->matrix, map->rows);
	free_map_matrix(map->matrix_copy, map->rows);
	map = NULL;
}
