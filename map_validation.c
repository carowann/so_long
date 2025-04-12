/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:58:08 by cwannhed          #+#    #+#             */
/*   Updated: 2025/04/04 12:37:45 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	valid_walls(t_map *map)
{
	int	i;
	int	j;

	j = 0;
	while (map->matrix[0][j] && map->matrix[map->rows - 1][j])
	{
		if (map->matrix[0][j] != TILE_WALL ||
			map->matrix[map->rows - 1][j] != TILE_WALL)
			return (0);
		j++;
	}
	i = 1;
	while (i < map->rows - 1)
	{
		if (map->matrix[i][0] != TILE_WALL ||
			map->matrix[i][map->cols - 1] != TILE_WALL)
			return (0);
		i++;
	}
	return (1);
}

int	validate_map(t_game *game, t_map *map)
{
	int		i;

	if (!map)
		return (ERR_RECT | ERR_WALLS | ERR_INVALID | ERR_TOKEN);
	game->token = (t_token){0};
	if (!valid_walls(map))
		map->err |= ERR_WALLS;
	i = 0;
	while (i < map->rows)
	{
		if (row_len(map->matrix[i]) != map->cols)
			map->err |= ERR_RECT;
		if (!valid_chars(map, map->matrix[i], i))
			map->err |= ERR_INVALID;
		update_token_counts(&game->token, map->matrix[i]);
		i++;
	}
	if (game->token.c_counter < 1
		|| game->token.e_counter != 1
		|| game->token.p_counter != 1)
		map->err |= ERR_TOKEN;
	validate_paths(map);
	return (map->err);
}
