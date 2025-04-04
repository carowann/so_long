/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 14:47:01 by cwannhed          #+#    #+#             */
/*   Updated: 2025/04/04 18:47:25 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_list	*skip_initial_invalid_lines(t_map *map)
{
	t_list	*curr;

	curr = map->lines;
	while (curr && row_len((char *)curr->content) == 0)
	{
		map->err |= ERR_INITIAL;
		curr = curr->next;
	}
	return (curr);
}

static int	count_valid_rows(t_list *start)
{
	int	count;
	int	len;

	if (!start)
		return (0);
	count = 0;
	while (start)
	{
		len = row_len((char *)start->content);
		if (len == 0)
			break ;
		count++;
		start = start->next;
	}
	return (count);
}

static void	check_extra_rows_after_map(t_map *map, int n_rows, t_list *start)
{
	while (n_rows > 0 && start)
	{
		start = start->next;
		n_rows--;
	}
	if (start && start->next)
		map->err |= ERR_EXTRA;
}

static void	populate_matrix(t_map *map, t_list *start)
{
	int		i;

	i = 0;
	while (start && i < map->rows)
	{
		map->matrix[i] = ft_strtrim((char *)start->content, "\n");
		if (!map->matrix[i])
		{
			while (i--)
				free(map->matrix[i]);
			free(map->matrix);
			map->matrix = NULL;
			return ;
		}
		start = start->next;
		i++;
	}
}

void	map_lines_to_matrix(t_map *map)
{
	t_list	*start;
	t_list	*tmp;
	int		n_valid_rows;

	start = skip_initial_invalid_lines(map);
	if (!start)
		return ;
	n_valid_rows = count_valid_rows(start);
	tmp = start;
	check_extra_rows_after_map(map, n_valid_rows, tmp);
	map->rows = n_valid_rows;
	map->cols = row_len((char *)start->content);
	map->matrix = ft_calloc(map->rows, sizeof(char *));
	if (!map->matrix)
		return ;
	populate_matrix(map, start);
}
