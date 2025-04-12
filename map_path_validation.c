/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path_validation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 15:20:49 by cwannhed          #+#    #+#             */
/*   Updated: 2025/04/11 16:46:25 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(t_map *map, int x, int y, char full)
{
	if (x < 0 || x >= map->cols || y < 0 || y >= map->rows)
		return ;
	if (map->matrix_copy[y][x] == TILE_WALL)
		return ;
	if (map->matrix_copy[y][x] == full)
		return ;
	map->matrix_copy[y][x] = full;
	flood_fill(map, x + 1, y, full);
	flood_fill(map, x - 1, y, full);
	flood_fill(map, x, y + 1, full);
	flood_fill(map, x, y - 1, full);
}

static int	tile_target_left(t_map *map, char **matrix, char tile)
{
	int	y;
	int	x;

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

static int	path_to_target_tile(t_map *map, char **matrix, char tile)
{
	flood_fill(map, map->player.x, map->player.y, 'F');
	if (tile_target_left(map, matrix, tile))
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
	if (!path_to_target_tile(map, map->matrix_copy, TILE_COLLECT))
		map->err |= ERR_UNREACH_COLLECT;
	free_map_matrix(map->matrix_copy, map->rows);
	map->matrix_copy = copy_matrix(map);
	if (!map->matrix_copy)
		return ;
	if (!path_to_target_tile(map, map->matrix_copy, TILE_EXIT))
		map->err |= ERR_UNREACH_EXIT;
}
