/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 18:06:22 by cwannhed          #+#    #+#             */
/*   Updated: 2024/11/24 18:06:29 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*last_ptr;
	unsigned char	chr;

	last_ptr = NULL;
	chr = (unsigned char)c;
	while (*s)
	{
		if (*s == chr)
			last_ptr = (char *)s;
		s++;
	}
	if (chr == '\0')
		return ((char *)s);
	return (last_ptr);
}
