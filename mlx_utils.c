/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 16:44:23 by cwannhed          #+#    #+#             */
/*   Updated: 2025/04/03 15:04:06 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->pxls_ptr + (y * img->line_len + x * (img->bpp / 8));
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

int	render_window(t_var *v)
{
	v->mlx = mlx_init();
	if (!v->mlx)
		exit(EXIT_FAILURE);
	v->win = mlx_new_window(v->mlx, WIDTH, HEIGHT, "so_long");
	if (!v->win)
	{
		mlx_destroy_display(v->mlx);
		free(v->mlx);
		exit(EXIT_FAILURE);
	}
	v->img.img = mlx_new_image(v->mlx, WIDTH, HEIGHT);
	if (!v->img.img)
	{
		mlx_destroy_window(v->mlx, v->win);
		mlx_destroy_display(v->mlx);
		free(v->mlx);
		exit(EXIT_FAILURE);
	}
	v->img.pxls_ptr = mlx_get_data_addr(v->img.img, &v->img.bpp, &v->img.line_len, &v->img.endian);
	my_mlx_pixel_put(&v->img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(v->mlx, v->win, v->img.img, 0, 0);
	mlx_hook(v->win, DestroyNotify, SubstructureNotifyMask, close_win, v);
	mlx_key_hook(v->win, handle_key_input, v);
	mlx_loop(v->mlx);
	return (0);
}
