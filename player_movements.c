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

void	move_player(t_game *game, t_map *map, int x, int y)
{
	int	new_x;
	int new_y;

	new_x = map->player.x + x;
	new_y = map->player.y + y;
	if (new_x < 0 || new_y < 0 || new_x >= map->cols || new_y >= map->rows)
		return ;
	if (map->matrix[new_y][new_x] == TILE_WALL)
		return;
	if (map->matrix[new_y][new_x] == TILE_EXIT && game->token.c_counter == 0)
	{
		map->player.moves++;
		ft_printf("You won in %d moves!\n", map->player.moves);
		close_win(game);
	}
	else if (map->matrix[map->player.y][map->player.x] == TILE_P_ON_EXIT)
	{
		if (map->matrix[new_y][new_x] == TILE_COLLECT)
			game->token.c_counter--;
		map->matrix[map->player.y][map->player.x] = TILE_EXIT;
		map->matrix[new_y][new_x] = TILE_PLAYER;
		map->player.y = new_y;
		map->player.x = new_x;
	}
	else if (map->matrix[new_y][new_x] == TILE_EXIT)
	{
		map->matrix[new_y][new_x] = TILE_P_ON_EXIT;
		map->matrix[map->player.y][map->player.x] = TILE_FLOOR;
		map->player.y = new_y;
		map->player.x = new_x;
	}
	else
	{
		if (map->matrix[new_y][new_x] == TILE_COLLECT)
			game->token.c_counter--;
		map->matrix[map->player.y][map->player.x] = TILE_FLOOR;
		map->matrix[new_y][new_x] = TILE_PLAYER;
		map->player.x = new_x;
		map->player.y = new_y;	
	}
	map->player.moves++;
	ft_printf("Movement counter: %d\n", map->player.moves);
	render_map_tex(&game->map, &game->vars, &game->tex);
}
