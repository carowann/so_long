/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 16:44:23 by cwannhed          #+#    #+#             */
/*   Updated: 2025/04/07 18:14:13 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_textures(t_var *vars, t_textures *tex)
{
	int	size;

	size = TILE_SIZE;
	tex->wall = mlx_xpm_file_to_image(vars->mlx, "textures/wall.xpm", &size, &size);
	tex->floor = mlx_xpm_file_to_image(vars->mlx, "textures/floor.xpm", &size, &size);
	tex->player = mlx_xpm_file_to_image(vars->mlx, "textures/player.xpm", &size, &size);
	tex->exit = mlx_xpm_file_to_image(vars->mlx, "textures/exit.xpm", &size, &size);
	tex->collect = mlx_xpm_file_to_image(vars->mlx, "textures/collect.xpm", &size, &size);
	tex->p_on_exit = mlx_xpm_file_to_image(vars->mlx, "textures/player_exit.xpm", &size, &size);
	if (!tex->wall || !tex->floor || !tex->player || !tex->exit || !tex->collect)
	{
		ft_putstr_fd("Error loading textures\n", 2);
		exit(EXIT_FAILURE);
	}
}

void free_textures(t_var *var, t_textures *tex)
{
	if (tex->wall)
		mlx_destroy_image(var->mlx, tex->wall);
	if (tex->floor)
		mlx_destroy_image(var->mlx, tex->floor);
	if (tex->player)
		mlx_destroy_image(var->mlx, tex->player);
	if (tex->exit)
		mlx_destroy_image(var->mlx, tex->exit);
	if (tex->collect)
		mlx_destroy_image(var->mlx, tex->collect);
	if (tex->p_on_exit)
		mlx_destroy_image(var->mlx, tex->p_on_exit);
}
