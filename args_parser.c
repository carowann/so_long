/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 14:48:39 by cwannhed          #+#    #+#             */
/*   Updated: 2025/03/28 11:55:48 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_input(int argc, char **argv)
{
	if (argc !=2 || !check_ber(argv[1]) || !check_path(argv[1]))
	{
		ft_putstr_fd("Error\n", 2);
		print_usage();
		exit(EXIT_FAILURE);
	}
}

int	check_ber(char *arg)
{
	int	arg_len;
	int	ext_idx;

	arg_len = ft_strlen(arg);
	ext_idx = arg_len - 4;
	if (ft_strncmp(&arg[ext_idx], ".ber", 4) == 0)
		return (1);
	return (0);
}

int	check_path(char *path)
{
	int	fd;
	
	if (ft_strncmp(path, "maps/", 5) != 0)
		return (0);
	fd = open(path, O_RDONLY | __O_DIRECTORY);
	if (fd >= 0)
	{
		if (close(fd) < 0)
		{
			ft_putstr_fd("Warning: Failed to close file descriptor properly.\n", 2);
			exit(EXIT_FAILURE);
		}
		return (0);
	}
	return (1);
}

void	print_usage()
{
	ft_putstr_fd("Usage: ./so_long <maps/map_file.ber>\n", 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("  <maps/map_file.ber> : A game map file with a .ber extension.\n", 2);
	ft_putstr_fd("                        The map file must be located in the \"maps\" directory.\n", 2);
	ft_putstr_fd("                        Requirements for the map:\n", 2);
	ft_putstr_fd("                          - It must be rectangular.\n", 2);
	ft_putstr_fd("                          - Allowed characters:\n", 2);
	ft_putstr_fd("                              • '0' for empty spaces.\n", 2);
	ft_putstr_fd("                              • '1' for walls.\n", 2);
	ft_putstr_fd("                              • 'P' for the player (exactly one).\n", 2);
	ft_putstr_fd("                              • 'E' for the exit (exactly one).\n", 2);
	ft_putstr_fd("                              • 'C' for collectibles (at least one).\n", 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("Game Controls:\n", 2);
	ft_putstr_fd("  - Use W/A/S/D or the arrow keys to move.\n", 2);
	ft_putstr_fd("  - Press ESC to exit.\n", 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("Example:\n", 2);
	ft_putstr_fd("  ./so_long maps/level1.ber\n", 2);
}
