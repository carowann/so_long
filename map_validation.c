/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:58:08 by cwannhed          #+#    #+#             */
/*   Updated: 2025/03/28 18:51:45 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static size_t	line_len(char *line)
{
	size_t	len;

	len = ft_strlen(line);
	if (line > 0 && line[len - 1] == '\n')
		return  (len - 1);
	return (len);
}

static int	check_walls(char *line, int mid_row)
{
	int	i;
	int	len;
	
	i = 0;
	if (mid_row)
	{
		len = ft_strlen(line);
		if (line[0] != '1' || line[len - 1] != '1')
			return (0);
	}
	else
	{
		while (line[i] && line[i] != '\n')
		{
			if (line[i] != '1')
				return (0);
			i++;
		}
	}
	return (1);
}

static int	valid_chars(char *line)
{
	int		i;

	i = 0;
	while(line[i])
	{
		if (!(line[i] == '0' || line[i] == '1' || line[i] == 'C'
			|| line[i] == 'P'|| line[i] == 'E' || line[i] == '\n'))
			return (0);
		i++;
	}
	return (1);
}

static int	no_extra_lines(t_list *map_lines)
{
    int blank_found;

	blank_found = 0;
    while (map_lines)
    {
        if (effective_length((char *)map_lines->content) == 0)
            blank_found = 1;
        else if (blank_found)
            return (0);
        map_lines = map_lines->next;
    }
    return (1);
}

void	count_tokens(t_token *token, char *line)
{
	while(*line)
	{
		if (*line == 'E')
			token->e_counter++;
		else if (*line == 'P')
			token->p_counter++;
		else if (*line == 'C')
			token->c_counter++;
		line++;
	}
}

int	validate_map_lines(t_list *map_lines)
{
	t_list	*curr;
	char	*line;
	size_t	width;
	t_token	token;
	int		err;

	err = 0;
	token = (t_token){0};
	curr = map_lines;
	if (!curr)
		return (ERR_RECT | ERR_WALLS | ERR_INVALID | ERR_TOKEN);
	width = line_len((char *)curr->content);
	while (curr)
	{
		line = (char *)curr->content;
		if (line_len(line) != width)
			err |= ERR_RECT;
		if (curr == map_lines || curr->next == NULL) 
		{
			if (!check_walls(line, 0))
				err |= ERR_WALLS;
		}
		else
		{
			if (!check_walls(line, 1))
				err |= ERR_WALLS;
		}
		if (!valid_chars(line))
			err |= ERR_INVALID;
		count_tokens(&token, line);
		curr = curr->next;
	}
	if (token.c_counter < 1 || token.e_counter != 1 || token.p_counter != 1)
		err |= ERR_TOKEN;
	return (err);
}
