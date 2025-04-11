/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 14:26:54 by cwannhed          #+#    #+#             */
/*   Updated: 2025/04/07 17:43:24 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	game.map = (t_map){0};
	check_input(argc, argv);
	read_map(argv[1], &game.map);
	if (!game.map.lines)
		map_error(&game.map, MALLOC_ERROR);
	map_lines_to_matrix(&game.map);
	if (!game.map.matrix)
		map_error(&game.map, MALLOC_ERROR);
	validate_map(&game, &game.map);
	if (!game.map.matrix_copy)
		map_error(&game.map, MALLOC_ERROR);
	if (game.map.err > 0)
		map_error(&game.map, MAP_ERROR);
	render_window(&game);
	return (0);
}
