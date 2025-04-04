/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path_validation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 15:20:49 by cwannhed          #+#    #+#             */
/*   Updated: 2025/04/04 18:43:55 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	flood_fill(char **matrix, int rows, int cols, int x, int y, char target, char replacement)
{
	if (x < 0 || x >= cols || y < 0 || y >= rows)
		return ;
	if (matrix[y][x] == TILE_WALL)
		return ;
	if (matrix[y][x] == replacement)
		return ;
	matrix[y][x] = replacement;
	flood_fill(matrix, rows, cols, x + 1, y, target, replacement);
	flood_fill(matrix, rows, cols, x - 1, y, target, replacement);
	flood_fill(matrix, rows, cols, x, y + 1, target, replacement);
	flood_fill(matrix, rows, cols, x, y - 1, target, replacement);
}

static int	tile_target_left(t_map *map, char **matrix, char tile)
{
	int	i;
	int j;

	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			if (matrix[i][j] == tile)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	path_to_collectibles(t_map *map, char **matrix)
{
	int	i;

	i = 0;
	flood_fill(matrix, map->rows, map->cols, map->p_x, map->p_y, TILE_EMPTY, 'F');
	flood_fill(matrix, map->rows, map->cols, map->p_x, map->p_y, TILE_COLLECT, 'F');
	if (tile_target_left(map, matrix, TILE_COLLECT))
		return (0);
	return (1);
}

static int	path_to_exit(t_map *map, char **matrix)
{
	flood_fill(matrix, map->rows, map->cols, map->p_x, map->p_y, TILE_EMPTY, 'F');
	flood_fill(matrix, map->rows, map->cols, map->p_x, map->p_y, TILE_EXIT, 'F');
	if (tile_target_left(map, matrix, TILE_EXIT))
		return (0);
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
	int		i = 0;

	map->matrix_copy = copy_matrix(map);
	if (!map->matrix_copy)
		return ;
	if (!path_to_collectibles(map, map->matrix_copy))
		map->err |= ERR_UNREACH_COLLECT;
	free_map_matrix(map->matrix_copy, map->rows);
	map->matrix_copy = copy_matrix(map);
	if (!map->matrix_copy)
		return ;
	i = 0;
	if (!path_to_exit(map, map->matrix_copy))
		map->err |= ERR_UNREACH_EXIT;
}
