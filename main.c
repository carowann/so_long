/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 14:26:54 by cwannhed          #+#    #+#             */
/*   Updated: 2025/04/01 18:55:15 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	// t_var	vars;
	t_map	map;
	int		err;

	map = (t_map){0};
	check_input(argc, argv);
	map.lines = read_map(argv[1]);
	if (!map.lines)
		map_error(&map);
	map.matrix = map_lines_to_matrix(&map);
	if (!map.matrix)
		map_error(&map);
	err = validate_map(&map);
	// if (err > 0)
	// 	print_validation_errors(err);
	// render_window(&vars);
	free_map(&map);
	return (0);
}
