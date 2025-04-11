/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 17:38:54 by cwannhed          #+#    #+#             */
/*   Updated: 2025/04/10 17:39:20 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	update_tile(t_game *game, int new_tile, int prev_tile, int new_x, int new_y)
{
	if (game->map.matrix[new_y][new_x] == TILE_COLLECT)
		game->token.c_counter--;
	game->map.matrix[game->map.player.y][game->map.player.x] = prev_tile;
	game->map.matrix[new_y][new_x] = new_tile;
	game->map.player.y = new_y;
	game->map.player.x = new_x;
	game->map.player.moves++;
	ft_printf("Movement counter: %d\n", game->map.player.moves);
}

void	move_player(t_game *game, t_map *map, int x, int y)
{
	int	old_x;
	int old_y;
	int	new_x;
	int new_y;

	old_x = map->player.x;
	old_y = map->player.y;
	new_x = map->player.x + x;
	new_y = map->player.y + y;
	if (new_x < 0 || new_y < 0 || new_x >= map->cols || new_y >= map->rows || map->matrix[new_y][new_x] == TILE_WALL)
		return ;
	if (map->matrix[new_y][new_x] == TILE_EXIT && game->token.c_counter == 0)
	{
		ft_printf("You won in %d moves!\n", map->player.moves + 1);
		cleanup_and_exit(game, EXIT_SUCCESS);
	}
	else if (map->matrix[old_y][old_x] == TILE_P_ON_EXIT)
		update_tile(game, TILE_PLAYER, TILE_EXIT, new_x, new_y);
	else if (map->matrix[new_y][new_x] == TILE_EXIT)
		update_tile(game, TILE_P_ON_EXIT, TILE_FLOOR, new_x, new_y);
	else
		update_tile(game, TILE_PLAYER, TILE_FLOOR, new_x, new_y);
	render_tile(map, &game->vars, &game->tex, old_y, old_x);
	render_tile(map, &game->vars, &game->tex, new_y, new_x);
}
