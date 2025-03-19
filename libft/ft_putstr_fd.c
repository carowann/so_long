/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 17:47:53 by cwannhed          #+#    #+#             */
/*   Updated: 2025/02/13 17:18:47 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	len;

	if (s == NULL)
		return (ft_putstr_fd("(null)", fd));
	len = ft_strlen(s);
	while (*s)
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
	return (len);
}
