/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 14:27:09 by cwannhed          #+#    #+#             */
/*   Updated: 2025/03/19 15:54:23 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
#include <X11/keysym.h>
# include <stdlib.h>

# define WIDTH	400
# define HEIGHT 400

typedef struct	s_img {
	void	*img;
	char	*pixels_ptr;
	int		bpp;
	int		line_len;
	int		endian;
}				t_img;

typedef	struct	s_var
{
	void	*mlx;
	void	*win;
	t_img	img;
}				t_var;

#endif