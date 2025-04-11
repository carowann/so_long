/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path_validation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 15:20:49 by cwannhed          #+#    #+#             */
/*   Updated: 2025/04/07 18:27:18 by cwannhed         ###   ########.fr       */
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
	int	y;
	int x;

	y = 0;
	while (y < map->rows)
	{
		x = 0;
		while (x < map->cols)
		{
			if (matrix[y][x] == tile)
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

static int	path_to_collectibles(t_map *map, char **matrix)
{
	flood_fill(matrix, map->rows, map->cols, map->player.x, map->player.y, TILE_FLOOR, 'F');
	flood_fill(matrix, map->rows, map->cols, map->player.x, map->player.y, TILE_COLLECT, 'F');
	if (tile_target_left(map, matrix, TILE_COLLECT))
		return (0);
	return (1);
}

static int	path_to_exit(t_map *map, char **matrix)
{
	flood_fill(matrix, map->rows, map->cols, map->player.x, map->player.y, TILE_FLOOR, 'F');
	flood_fill(matrix, map->rows, map->cols, map->player.x, map->player.y, TILE_EXIT, 'F');
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
	map->matrix_copy = copy_matrix(map);
	if (!map->matrix_copy)
		return ;
	if (!path_to_collectibles(map, map->matrix_copy))
		map->err |= ERR_UNREACH_COLLECT;
	free_map_matrix(map->matrix_copy, map->rows);
	map->matrix_copy = copy_matrix(map);
	if (!map->matrix_copy)
		return ;
	if (!path_to_exit(map, map->matrix_copy))
		map->err |= ERR_UNREACH_EXIT;
}
