/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:58:08 by cwannhed          #+#    #+#             */
/*   Updated: 2025/04/01 18:56:58 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	validate_map(t_map *map)
{
	t_token	token;
	int		err;
	int		i;

	if (!map)
		return (ERR_RECT | ERR_WALLS | ERR_INVALID | ERR_TOKEN);
	err = 0;
	token = (t_token){0};
	if (!valid_walls(&map))
		err |= ERR_WALLS;
	i = 0;
	while (i < map->rows)
	{
		err |= check_line_errors(map->matrix[i], &map, &token);
		i++;
	}
	if (token.c_counter < 1 || token.e_counter != 1 || token.p_counter != 1)
		err |= ERR_TOKEN;
	return (err);
}

