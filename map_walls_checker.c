/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_walls_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 14:48:53 by cwannhed          #+#    #+#             */
/*   Updated: 2025/03/31 16:41:54 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int has_valid_side_walls(char *line)
{
	size_t len;

	len = line_len(line);
	if (len < 2)
		return (0);
	return (line[0] == TILE_WALL && line[len - 1] == TILE_WALL);
}

int	has_only_wall_chars(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] != TILE_WALL)
			return (0);
		i++;
	}
	return (1);
}

int	has_valid_walls(char *line, int is_mid_row)
{
	if (is_mid_row)
		return (has_valid_side_walls(line));
	else
		return (has_only_wall_chars(line));
}
