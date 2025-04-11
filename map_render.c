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

void	render_map_tex(t_map *map, t_var *vars, t_textures *tex)
{
	char	tile;
	int		i;
	int		j;

	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			tile = map->matrix[i][j];
			if (tile == TILE_COLLECT)
				mlx_put_image_to_window(vars->mlx, vars->win, tex->collect, j * TILE_SIZE, i * TILE_SIZE);
			else if (tile == TILE_FLOOR)
				mlx_put_image_to_window(vars->mlx, vars->win, tex->floor, j * TILE_SIZE, i * TILE_SIZE);
			else if (tile == TILE_EXIT)
				mlx_put_image_to_window(vars->mlx, vars->win, tex->exit, j * TILE_SIZE, i * TILE_SIZE);
			else if (tile == TILE_PLAYER)
				mlx_put_image_to_window(vars->mlx, vars->win, tex->player, j * TILE_SIZE, i * TILE_SIZE);
			else if (tile == TILE_WALL)
				mlx_put_image_to_window(vars->mlx, vars->win, tex->wall, j * TILE_SIZE, i * TILE_SIZE);
			else if (tile == TILE_P_ON_EXIT)
				mlx_put_image_to_window(vars->mlx, vars->win, tex->p_on_exit, j * TILE_SIZE, i * TILE_SIZE);
			j++;
		}
		i++;
	}
}

