/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 14:27:09 by cwannhed          #+#    #+#             */
/*   Updated: 2025/03/24 17:48:56 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <X11/X.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

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

//mlx utils
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
int		handle_key_input(int keysym, t_var	*data);
int		close_win(t_var *data);
int		render_window(t_var *vars);

//args_parser
void	check_input(int argc, char **argv);
int		check_ber(char *arg);
int		check_path(char *path);
int		print_usage();

//map_parser
t_list	*read_map(const char *path);

//map validation
int	validate_map_lines(t_list *map_lines);
int	check_width(t_list *map_lines);
int	check_chars(t_list	*map_lines);
int	check_walls(t_list	*map_lines);
int	count_tokens(t_list	*map_lines);

//error_handler
int	map_error();

#endif