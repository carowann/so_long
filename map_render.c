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

void	render_tile(t_map *map, t_var *vars, t_textures *tex, int row, int col)
{
	char	tile;
	int		x;
	int		y;

	tile = map->matrix[row][col];
	x = col * TILE_SIZE;
	y = row * TILE_SIZE;
	if (tile == TILE_COLLECT)
		mlx_put_image_to_window(vars->mlx, vars->win, tex->collect, x, y);
	else if (tile == TILE_FLOOR)
		mlx_put_image_to_window(vars->mlx, vars->win, tex->floor, x, y);
	else if (tile == TILE_EXIT)
		mlx_put_image_to_window(vars->mlx, vars->win, tex->exit, x, y);
	else if (tile == TILE_PLAYER)
		mlx_put_image_to_window(vars->mlx, vars->win, tex->player, x, y);
	else if (tile == TILE_WALL)
		mlx_put_image_to_window(vars->mlx, vars->win, tex->wall, x, y);
	else if (tile == TILE_P_ON_EXIT)
		mlx_put_image_to_window(vars->mlx, vars->win, tex->p_on_exit, x, y);
}

void	render_map_tex(t_map *map, t_var *vars, t_textures *tex)
{
	int		i;
	int		j;

	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			render_tile(map, vars, tex, i, j);
			j++;
		}
		i++;
	}
}

