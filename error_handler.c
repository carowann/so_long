/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 17:44:23 by cwannhed          #+#    #+#             */
/*   Updated: 2025/04/11 16:47:02 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	cleanup_and_exit(t_game *game, int exit_code)
{
	free_textures(&game->env, &game->tex);
	if (game->env.img.img)
		mlx_destroy_image(game->env.mlx, game->env.img.img);
	if (game->env.win)
		mlx_destroy_window(game->env.mlx, game->env.win);
	if (game->env.mlx)
	{
		mlx_destroy_display(game->env.mlx);
		free(game->env.mlx);
	}
	free_map(&game->map);
	exit(exit_code);
}

void	print_validation_errors(int err)
{
	ft_putstr_fd("Error\n", 2);
	if (err & ERR_INITIAL)
		ft_putstr_fd("Map file must not start with invalid lines\n", 2);
	if (err & ERR_RECT)
		ft_putstr_fd("Map is not rectangular\n", 2);
	if (err & ERR_WALLS)
		ft_putstr_fd("Map borders are not properly closed\n", 2);
	if (err & ERR_INVALID)
		ft_putstr_fd("Map is invalid\n", 2);
	if (err & ERR_TOKEN)
		ft_putstr_fd("Map must have 1 P, 1 E and at least 1 C\n", 2);
	if (err & ERR_EXTRA)
		ft_putstr_fd("No extra lines are allowed after the map\n", 2);
	if (err & ERR_UNREACH_COLLECT)
		ft_putstr_fd("One or more collectibles are unreachable\n", 2);
	if (err & ERR_UNREACH_EXIT)
		ft_putstr_fd("Exit is unreachable\n", 2);
	if (err & ERR_TOO_BIG)
		ft_putstr_fd("Map too big to render on this screen\n", 2);
}

int	map_error(t_map	*map, int cause)
{
	if (cause == MALLOC_ERROR)
		ft_putstr_fd("Error while reading map\n", 2);
	else if (cause == MAP_ERROR)
		print_validation_errors(map->err);
	free_map(map);
	exit(EXIT_FAILURE);
}
