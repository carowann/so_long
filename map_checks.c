/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 14:46:56 by cwannhed          #+#    #+#             */
/*   Updated: 2025/04/03 17:31:50 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	valid_map_char(t_map *map, char c, int row, int col)
{
	if (c == TILE_PLAYER)
	{
		map->p_x = col;
		map->p_y = row;
	}
	return (c == TILE_EMPTY || c == TILE_WALL || c == TILE_COLLECT
		|| c == TILE_PLAYER || c == TILE_EXIT || c == '\0');
}

int	valid_chars(t_map *map, char *line, int row)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!valid_map_char(map, line[i], row, i))
			return (0);
		i++;
	}
	return (1);
}

void	update_token_counts(t_token *token, char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == TILE_EXIT)
			token->e_counter++;
		else if (line[i] == TILE_PLAYER)
			token->p_counter++;
		else if (line[i] == TILE_COLLECT)
			token->c_counter++;
		i++;
	}
}
