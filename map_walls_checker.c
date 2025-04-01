/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_walls_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 14:48:53 by cwannhed          #+#    #+#             */
/*   Updated: 2025/04/01 19:02:54 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	valid_walls(t_map *map)
{
	int i;
	int	j;

	j = 0;
	while (map->matrix[0][j] && map->matrix[map->rows - 1][j])
	{
		if (map->matrix[0][j] != '1' || map->matrix[map->rows - 1][j] != '1')
			return (0);
	}
	i = 1;
	while (i < map->rows - 2)
	{
		if (map->matrix[i][0] != '1' || map->matrix[i][map->cols] != '1')
			return (0);
		i++;
	}
	return (1);
}
