/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 14:26:54 by cwannhed          #+#    #+#             */
/*   Updated: 2025/04/03 13:16:06 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	// t_var	vars;
	t_map	map;

	map = (t_map){0};
	check_input(argc, argv);
	read_map(argv[1], &map);
	if (!map.lines)
		map_error(&map);
	map_lines_to_matrix(&map);
	if (!map.matrix)
		map_error(&map);
	validate_map(&map);
	if (map.err > 0)
		map_error(&map);
	// render_window(&vars);
	free_map(&map);
	return (0);
}
