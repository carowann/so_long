/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 14:48:39 by cwannhed          #+#    #+#             */
/*   Updated: 2025/04/11 16:46:52 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_ber(char *arg)
{
	int	arg_len;
	int	ext_idx;

	arg_len = ft_strlen(arg);
	ext_idx = arg_len - 4;
	if (ft_strncmp(&arg[ext_idx], ".ber", 4) == 0)
		return (1);
	return (0);
}

static int	check_path(char *path)
{
	int	fd;

	if (ft_strncmp(path, "maps/", 5) != 0)
		return (0);
	fd = open(path, O_RDONLY | __O_DIRECTORY);
	if (fd >= 0)
	{
		if (close(fd) < 0)
		{
			ft_putstr_fd("Failed to close file descriptor properly.\n", 2);
			exit(EXIT_FAILURE);
		}
		return (0);
	}
	return (1);
}

void	check_input(int argc, char **argv)
{
	if (argc != 2 || !check_ber(argv[1]) || !check_path(argv[1]))
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd(USAGE_MSG, 2);
		exit(EXIT_FAILURE);
	}
}
