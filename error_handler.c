/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 17:44:23 by cwannhed          #+#    #+#             */
/*   Updated: 2025/04/01 16:20:50 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_error(t_map	*map)
{
	ft_putstr_fd("Error\nError while reading map", 2);
	free_map(map);	
	exit(EXIT_FAILURE);
}

void print_validation_errors(int err)
{
	ft_putstr_fd("Error\n", 2);
	if (err & ERR_RECT)
		ft_putstr_fd("Map is not rectangular.\n", 2);
	if (err & ERR_WALLS)
		ft_putstr_fd("Map borders are not properly closed.\n", 2);
	if (err & ERR_INVALID)
		ft_putstr_fd("Map contains invalid characters.\n", 2);
	if (err & ERR_TOKEN)
		ft_putstr_fd("Map must have 1 P, 1 E and at least 1 C.\n", 2);
	if (err & ERR_EXTRA)
		ft_putstr_fd("No extra lines are allowed after the map.\n", 2);
	if (err & ERR_INITIAL)
		ft_putstr_fd("Map file must not start with blank lines.\n", 2);
	ft_putstr_fd("\n", 2);
	print_usage();
}
