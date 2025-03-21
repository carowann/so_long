/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 14:26:54 by cwannhed          #+#    #+#             */
/*   Updated: 2025/03/21 14:54:25 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_var	vars;
	t_list	*map_lines;

	check_input(argc, argv);
	map_lines = read_map(argv[1]);
	if (!map_lines)
		{
			ft_putstr_fd("Error\n", 2);
			ft_putstr_fd("Error while reading map\n", 2);			
			exit(EXIT_FAILURE);
		}
	validate_map_lines(map_lines);
	render_window(&vars);
	return (0);
}
