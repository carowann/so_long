/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 14:26:54 by cwannhed          #+#    #+#             */
/*   Updated: 2025/03/28 14:17:02 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	// t_var	vars;
	t_list	*map_lines;
	int		err;

	check_input(argc, argv);
	map_lines = read_map(argv[1]);
	if (!map_lines)
		map_error();
	err = validate_map_lines(map_lines);
	if (err > 0)
		print_validation_errors(err);
	// render_window(&vars);
	return (0);
}
