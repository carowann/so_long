/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 18:09:44 by cwannhed          #+#    #+#             */
/*   Updated: 2025/04/07 18:19:49 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_mlx(t_game *game)
{
	game->vars.wind_height = game->map.rows * TILE_SIZE;
	game->vars.wind_width = game->map.cols * TILE_SIZE;
	game->vars.mlx = mlx_init();
	if (!game->vars.mlx)
		exit(EXIT_FAILURE);
}

static void init_window(t_game *game)
{
	game->vars.win = mlx_new_window(game->vars.mlx, game->vars.wind_width, game->vars.wind_height, "so_long");
	if (!game->vars.win)
	{
		free_textures(&game->vars, &game->tex);
		mlx_destroy_display(game->vars.mlx);
		free(game->vars.mlx);
		exit(EXIT_FAILURE);
	}
}

static void	init_image(t_game *g)
{
	g->vars.img.img = mlx_new_image(g->vars.mlx, g->vars.wind_width, g->vars.wind_height);
	if (!g->vars.img.img)
	{
		free_textures(&g->vars, &g->tex);
		mlx_destroy_window(g->vars.mlx, g->vars.win);
		mlx_destroy_display(g->vars.mlx);
		free(g->vars.mlx);
		exit(EXIT_FAILURE);
	}
	g->vars.img.pxls_ptr = mlx_get_data_addr(g->vars.img.img, &g->vars.img.bpp, &g->vars.img.line_len, &g->vars.img.endian);
}

int	close_win(t_game *g)
{
	free_textures(&g->vars, &g->tex);
	mlx_destroy_image(g->vars.mlx, g->vars.img.img);
	mlx_destroy_window(g->vars.mlx, g->vars.win);
	mlx_destroy_display(g->vars.mlx);
	free(g->vars.mlx);
	free_map(&g->map);
	exit(EXIT_SUCCESS);
}

void	render_window(t_game *game)
{
	init_mlx(game);
	load_textures(&game->vars, &game->tex);
	init_window(game);
	init_image(game);
	render_map_tex(&game->map, &game->vars, &game->tex);
	mlx_hook(game->vars.win, KeyPress, KeyPressMask, handle_key_input, game);
	mlx_hook(game->vars.win, DestroyNotify, SubstructureNotifyMask, close_win, game);
	//mlx_key_hook(game->vars.win, handle_key_input, game);
	mlx_loop(game->vars.mlx);
}
