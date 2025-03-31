/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:58:08 by cwannhed          #+#    #+#             */
/*   Updated: 2025/03/31 17:00:05 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	validate_map_lines(t_list *map_lines)
{
	t_list	*curr;
	size_t	width;
	t_token	token;
	int		err;
	int		map_closed;

	if (!map_lines)
		return (ERR_RECT | ERR_WALLS | ERR_INVALID | ERR_TOKEN);
	curr = map_lines;
	width = line_len((char *)curr->content);
	err = 0;
	token = (t_token){0};
	map_closed = -1;
	while (curr)
	{
		if (!map_closed)
		{
			err |= check_line_errors(curr, map_lines, width, &token);
			if (has_only_wall_chars((char *)curr->content))
				map_closed ++;
		}
		else if (line_len((char *)curr->content))
			err |= ERR_EXTRA;
		curr = curr->next;
	}
	if (token.c_counter < 1 || token.e_counter != 1 || token.p_counter != 1)
		err |= ERR_TOKEN;
	return (err);
}
