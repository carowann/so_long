/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 16:44:23 by cwannhed          #+#    #+#             */
/*   Updated: 2025/03/20 14:40:20 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;
	
	dst = img->pixels_ptr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

int	handle_key_input(int keysym, t_var *data)
{
	if (keysym == XK_Escape)
		close_win(data);
	return (0);
}

int	close_win(t_var *data)
{
	mlx_destroy_image(data->mlx, data->img.img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(EXIT_SUCCESS);
}

int	render_window(t_var *vars)
{
	vars->mlx = mlx_init();
	if (!vars->mlx)
		exit(EXIT_FAILURE);
	vars->win = mlx_new_window(vars->mlx, WIDTH, HEIGHT, "so_long");
	if (!vars->win)
	{
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
		exit(EXIT_FAILURE);
	}
	vars->img.img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	if (!vars->img.img)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
		exit(EXIT_FAILURE);
	}
	vars->img.pixels_ptr = mlx_get_data_addr(vars->img.img, &vars->img.bpp, &vars->img.line_len, &vars->img.endian);
	my_mlx_pixel_put(&vars->img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	mlx_hook(vars->win, DestroyNotify, SubstructureNotifyMask, close_win, vars);
	mlx_key_hook(vars->win, handle_key_input, vars);
	mlx_loop(vars->mlx);
	return (0);
}
