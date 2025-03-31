/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 17:44:23 by cwannhed          #+#    #+#             */
/*   Updated: 2025/03/31 16:44:19 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_error()
{
	ft_putstr_fd("Error\nError while reading map", 2);		
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
	ft_putstr_fd("\n", 2);
	print_usage();
}
