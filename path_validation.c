/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 15:20:49 by cwannhed          #+#    #+#             */
/*   Updated: 2025/04/03 17:32:51 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	flood_fill(char **matrix, int rows, int cols, int x, int y, char target, char replacement)
{
	if (x < 0 || x >= cols || y < 0 || y >= rows)
		return ;
	if (matrix[y][x] != target)
		return ;
	matrix[y][x] = replacement;
	flood_fill(matrix, rows, cols, x + 1, y, target, replacement);
	flood_fill(matrix, rows, cols, x - 1, y, target, replacement);
	flood_fill(matrix, rows, cols, x, y + 1, target, replacement);
	flood_fill(matrix, rows, cols, x, y - 1, target, replacement);
}

static int	path_to_collectibles(t_map *map, char **matrix)
{
	flood_fill(matrix, map->rows, map->cols, map->p_x, map->p_y, TILE_COLLECT, 'F');
	return (1);
}

char	**copy_matrix(t_map *map)
{
	char	**copy;
	int		i;
	
	copy = ft_calloc(map->rows, sizeof(char *));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < map->rows)
	{
		copy[i] = ft_strdup(map->matrix[i]);
		if (!copy[i])
		{
			while (i--)
				free(copy[i]);
			free(copy);
			copy = NULL;
			return (NULL);
		}
		i++;
	}
	return (copy);
}

void	validate_paths(t_map *map)
{
	char	**matrix;

	matrix = copy_matrix(map);
	if (!path_to_collectibles(map, matrix))
		map->err |= ERR_UNREACH_COLLECT;
	if (!path_to_exit(map, matrix))
		map->err |= ERR_UNREACH_EXIT;
}
