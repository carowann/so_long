/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 09:23:32 by cwannhed          #+#    #+#             */
/*   Updated: 2025/04/10 17:44:03 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_tile(t_game *g, int row, int col)
{
	char	tile;
	int		x;
	int		y;

	tile = g->map.matrix[row][col];
	x = col * TILE_SIZE;
	y = row * TILE_SIZE;
	if (tile == TILE_COLLECT)
		mlx_put_image_to_window(g->env.mlx, g->env.win, g->tex.collect, x, y);
	else if (tile == TILE_FLOOR)
		mlx_put_image_to_window(g->env.mlx, g->env.win, g->tex.floor, x, y);
	else if (tile == TILE_EXIT)
		mlx_put_image_to_window(g->env.mlx, g->env.win, g->tex.exit, x, y);
	else if (tile == TILE_PLAYER)
		mlx_put_image_to_window(g->env.mlx, g->env.win, g->tex.player, x, y);
	else if (tile == TILE_WALL)
		mlx_put_image_to_window(g->env.mlx, g->env.win, g->tex.wall, x, y);
	else if (tile == TILE_P_ON_EXIT)
		mlx_put_image_to_window(g->env.mlx, g->env.win, g->tex.p_on_exit, x, y);
}

void	render_map_tex(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (i < game->map.rows)
	{
		j = 0;
		while (j < game->map.cols)
		{
			render_tile(game, i, j);
			j++;
		}
		i++;
	}
}
