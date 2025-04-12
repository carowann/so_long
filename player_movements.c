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

static void	update_tile(t_token *token, t_map *map, int new_tile, int prev_tile)
{
	if (map->matrix[map->player.dest_y][map->player.dest_x] == TILE_COLLECT)
		token->c_counter--;
	map->matrix[map->player.y][map->player.x] = prev_tile;
	map->matrix[map->player.dest_y][map->player.dest_x] = new_tile;
	map->player.y = map->player.dest_y;
	map->player.x = map->player.dest_x;
	ft_printf("Movement counter: %d\n", ++map->player.moves);
}

void	move_player(t_game *game, t_map *map, int x, int y)
{
	int	old_x;
	int	old_y;

	old_x = map->player.x;
	old_y = map->player.y;
	map->player.dest_x = map->player.x + x;
	map->player.dest_y = map->player.y + y;
	if (map->player.dest_x < 0 || map->player.dest_y < 0
		|| map->player.dest_x >= map->cols || map->player.dest_y >= map->rows
		|| map->matrix[map->player.dest_y][map->player.dest_x] == TILE_WALL)
		return ;
	if (map->matrix[map->player.dest_y][map->player.dest_x] == TILE_EXIT
		&& game->token.c_counter == 0)
	{
		ft_printf("You won in %d moves!\n", map->player.moves + 1);
		cleanup_and_exit(game, EXIT_SUCCESS);
	}
	else if (map->matrix[old_y][old_x] == TILE_P_ON_EXIT)
		update_tile(&game->token, map, TILE_PLAYER, TILE_EXIT);
	else if (map->matrix[map->player.dest_y][map->player.dest_x] == TILE_EXIT)
		update_tile(&game->token, map, TILE_P_ON_EXIT, TILE_FLOOR);
	else
		update_tile(&game->token, map, TILE_PLAYER, TILE_FLOOR);
	render_tile(game, old_y, old_x);
	render_tile(game, map->player.dest_y, map->player.dest_x);
}
