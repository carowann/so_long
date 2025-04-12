/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_structs.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 14:28:05 by cwannhed          #+#    #+#             */
/*   Updated: 2025/04/12 14:28:10 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_STRUCTS_H
# define SO_LONG_STRUCTS_H

# include "libft/libft.h"

typedef struct s_img
{
	void	*img;
	char	*pxls_ptr;
	int		bpp;
	int		line_len;
	int		endian;
}				t_img;

typedef struct s_var
{
	void	*mlx;
	void	*win;
	t_img	img;
	int		wind_width;
	int		wind_height;
}				t_var;

typedef struct s_token
{
	int	e_counter;
	int	p_counter;
	int	c_counter;
}				t_token;

typedef struct s_player
{
	int	x;
	int	y;
	int	dest_x;
	int	dest_y;
	int	moves;
}				t_player;

typedef struct s_map
{
	t_list		*lines;
	char		**matrix;
	char		**matrix_copy;
	int			rows;
	int			cols;
	int			err;
	t_player	player;
}				t_map;

typedef struct s_textures
{
	void	*wall;
	void	*floor;
	void	*player;
	void	*exit;
	void	*collect;
	void	*p_on_exit;
}				t_textures;

typedef struct s_game
{
	t_map		map;
	t_var		env;
	t_textures	tex;
	t_token		token;
}				t_game;

#endif