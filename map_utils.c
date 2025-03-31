/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 14:49:30 by cwannhed          #+#    #+#             */
/*   Updated: 2025/03/31 15:38:48 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	line_len(char *line)
{
	size_t	len;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		return  (len - 1);
	return (len);
}

int	no_extra_lines(t_list *map_lines)
{
    int blank_found;

	blank_found = 0;
    while (map_lines)
    {
        if (line_len((char *)map_lines->content) == 0)
            blank_found = 1;
        else if (blank_found)
            return (0);
        map_lines = map_lines->next;
    }
    return (1);
}

