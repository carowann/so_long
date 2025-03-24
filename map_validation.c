/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:58:08 by cwannhed          #+#    #+#             */
/*   Updated: 2025/03/24 18:28:48 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_walls(char *line, int mid_row)
{
	int	i;
	int	last_idx;
	
	i = 0;
	if (mid_row)
	{
		last_idx = ft_strlen(line) - 1;
		if (line[0] != '1' || line[last_idx] != '1')
			return (0);
	}
	else
	{
		while (line[i])
		{
			if (line[i] != '1')
				return (0);
			i++;
		}
	}
	return (1);
}

int	validate_map_lines(t_list *map_lines)
{
	t_list	*curr;
	char	*line;
	int		width;

	width = ft_strlen(map_lines->content);
	curr = map_lines->next;
	if (!check_walls(line, 0))
		//wall error
	while (curr->next)
	{
		line = (char *)curr->content;
		if (ft_strlen(line) != width)
			//not rectangular
		if (!check_walls(line, 1))
			//invalid walls
		curr = curr->next;
	}
	line = (char *)curr->content;
	if (!check_walls(line, 0));
		//wall error
}

// int	validate_map_lines(t_list *map_lines)
// {
// 	t_list	*head;
// 	int		width;
// 	int		errors;
	
// 	errors = 0;
// 	head = map_lines;
// 	width = check_width(&head);
// 	if (!width)
// 	{
// 		//TODO: print error mess
// 		errors++;
// 	}
// 	if (!check_chars(&head))
// 		errors++;
// 	if (!check_walls(&head))
// 		errors++;
// 	if (!count_tokens(&head))
// 		errors++;
// 	ft_lstclear(&head, free);
// 	if (errors)
// 	{
// 		//TODO: error messages
// 		return (0);
// 	}
// 	return (1);
// }

int	check_width(t_list *map_lines)
{
	int	width;
	int	new_width;
	
	if (!map_lines)
		return (0);
	width = ft_strlen(map_lines->content);
	while (map_lines)
	{
		new_width = ft_strlen(map_lines->content);
		if (new_width != width)
			return (0);
		map_lines = map_lines->next;
	}
	return (1);
}

int	check_chars(t_list	*map_lines)
{
	int		i;
	char	*line;
	
	if (!map_lines)
	return (0);
	while (map_lines)
	{
		i = 0;
		line = (char *)map_lines->content;
		while(line[i])
		{
			if (!(line[i] == '0' || line[i] == '1' || line[i] == 'C'|| line[i] == 'P'|| line[i] == 'E' || line[i] == '\n'))
				return (0);
			i++;
		}
		map_lines = map_lines->next;
	}
	return (1);
}

int	check_walls(t_list	*map_lines)
{
	char	*line;
	int		i;
	int		last_i;
	
	if (!map_lines)
		return (0);
	i = 0;
	line = (char *)map_lines->content;
	while (line[i])
	{
		if (line[i] != '1')
			return (0);
		i++;
	}
	while (map_lines->next)
	{
		line = (char *)map_lines->content;
		last_i = ft_strlen(line) - 1;
		if (line[0] != '1' && line[last_i] != '1')
			return (0);
		map_lines = map_lines->next;
	}
	line = (char *)map_lines->content;
	i = 0;
	while (line[i])
	{
		if (line[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	count_tokens(t_list	*map_lines)
{
	char	*line;
	int		e_counter;
	int		p_counter;
	int		c_counter;
	
	if (!map_lines)
		return (0);
	e_counter = 0;
	p_counter = 0;
	c_counter = 0;
	while (map_lines)
	{
		line = (char *)map_lines->content;
		while(*line)
		{
			if (*line == 'E')
				e_counter++;
			else if (*line == 'P')
				p_counter++;
			else if (*line == 'C')
				c_counter++;
			line++;
		}
		map_lines = map_lines->next;
	}
	if (e_counter == 1 && p_counter == 1 && c_counter >= 1)
		return (1);
	return (0);
}
