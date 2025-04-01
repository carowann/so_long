/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 14:47:01 by cwannhed          #+#    #+#             */
/*   Updated: 2025/04/01 18:04:12 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**alloc_matrix(int rows, int cols)
{
	char	**matrix;
	int		i;

	matrix = ft_calloc(rows, sizeof(char *));
	if (!matrix)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		matrix[i] = ft_calloc(cols + 1, sizeof(char));
		if (!matrix[i])
		{
			while (i >= 0)
			{
				free(matrix[i]);
				i--;
			}
			free(matrix);
			matrix = NULL;
			return (NULL);
		}
		i++;
	}
	return (matrix);
}

void	populate_matrix(t_map *map)
{
	int		i;
	t_list	*curr;

	i = 0;
	curr = map->lines;
	while (i < map->rows && curr)
	{
		ft_strlcpy(map->matrix[i], (char *)curr->content, map->cols + 1);
		curr = curr->next;
		i++;
	}
}

void	free_map_lines(t_map *map)
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

char	**map_lines_to_matrix(t_map	*map)
{
	char	**matrix;

	map->cols = row_len((char *)map->lines->content);
	map->rows = ft_lstsize(map->lines);
	matrix = alloc_matrix(map->rows, map->cols);
	map->matrix = matrix;
	populate_matrix(map);
	return (matrix);
}
