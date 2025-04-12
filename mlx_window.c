/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 18:09:44 by cwannhed          #+#    #+#             */
/*   Updated: 2025/04/07 18:19:49 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_mlx(t_game *game)
{
	int	screen_width;
	int	screen_height;

	game->env.mlx = mlx_init();
	if (!game->env.mlx)
		cleanup_and_exit(game, EXIT_FAILURE);
	mlx_get_screen_size(game->env.mlx,
		&screen_width,
		&screen_height);
	game->env.wind_width = game->map.cols * TILE_SIZE;
	game->env.wind_height = game->map.rows * TILE_SIZE;
	if (game->env.wind_width > screen_width
		|| game->env.wind_height > screen_height)
	{
		game->map.err |= ERR_TOO_BIG;
		print_validation_errors(game->map.err);
		cleanup_and_exit(game, EXIT_FAILURE);
	}
}

static void	init_window(t_game *game)
{
	game->env.win = mlx_new_window(game->env.mlx,
			game->env.wind_width,
			game->env.wind_height,
			"so_long");
	if (!game->env.win)
		cleanup_and_exit(game, EXIT_FAILURE);
}

static void	init_image(t_game *game)
{
	game->env.img.img = mlx_new_image(game->env.mlx,
			game->env.wind_width,
			game->env.wind_height);
	if (!game->env.img.img)
		cleanup_and_exit(game, EXIT_FAILURE);
	game->env.img.pxls_ptr = mlx_get_data_addr(game->env.img.img,
			&game->env.img.bpp,
			&game->env.img.line_len,
			&game->env.img.endian);
}

void	render_window(t_game *game)
{
	init_mlx(game);
	load_textures(game, &game->env, &game->tex);
	init_window(game);
	init_image(game);
	render_map_tex(game);
	mlx_hook(game->env.win,
		KeyPress,
		KeyPressMask,
		handle_key_input,
		game);
	mlx_hook(game->env.win,
		DestroyNotify,
		SubstructureNotifyMask,
		cleanup_and_exit,
		game);
	mlx_loop(game->env.mlx);
}
