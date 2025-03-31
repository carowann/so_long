/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 14:46:56 by cwannhed          #+#    #+#             */
/*   Updated: 2025/03/31 15:57:52 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int valid_map_char(char c)
{
	return (c == TILE_EMPTY || c == TILE_WALL || c == TILE_COLLECT
		|| c == TILE_PLAYER || c == TILE_EXIT || c == '\n');
}

static int	has_only_valid_chars(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!valid_map_char(line[i]))
			return (0);
		i++;
	}
	return (1);
}

static void increment_token_count(t_token *token, char c)
{
	if (c == TILE_EXIT)
		token->e_counter++;
	else if (c == TILE_PLAYER)
		token->p_counter++;
	else if (c == TILE_COLLECT)
		token->c_counter++;
}

static void	update_token_cunts(t_token *token, char *line)
{
	while(*line)
	{
		increment_token_count(token, *line);
		line++;
	}
}

int	check_line_errors(t_list *curr, t_list *head, size_t width, t_token *token)
{
	int		err;
	char	*line;

	err = 0;
	line = (char *)curr->content;
	if (line_len(line) != width)
		err |= ERR_RECT;
	if (!has_valid_walls(line, (curr != head && curr->next != NULL)))
		err |= ERR_WALLS;
	if (!has_only_valid_chars(line))
		err |= ERR_INVALID;
	update_token_cunts(token, line);
	return (err);
}
