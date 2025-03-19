/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:38:00 by cwannhed          #+#    #+#             */
/*   Updated: 2025/03/12 16:20:03 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long double	ft_atof(const char *str)
{
	long double	result;
	long double	dec;
	int			fract;
	int			sign;

	result = 0.0;
	sign = 1;
	fract = 1;
	while (ft_isspace((unsigned char)*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
	}
	while (*str && ft_isdigit((unsigned char)*str))
	{
		result = result * 10.0 + (*str - '0');
		str++;
	}
	if (*str == '.')
	{
		str++;
		while (*str && ft_isdigit((unsigned char)*str))
		{
			dec = dec * 10.0 + (*str - '0');
			fract *= 10;
			str++;
		}
		result += dec / fract;
	}
	return (sign * result);
}