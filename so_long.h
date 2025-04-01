/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 14:27:09 by cwannhed          #+#    #+#             */
/*   Updated: 2025/04/01 19:01:25 by cwannhed         ###   ########.fr       */
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


# define TILE_WALL       '1'
# define TILE_EMPTY      '0'
# define TILE_PLAYER     'P'
# define TILE_EXIT       'E'
# define TILE_COLLECT    'C'

# define ERR_RECT    0x01
# define ERR_WALLS   0x02
# define ERR_INVALID 0x04
# define ERR_TOKEN   0x08
# define ERR_EXTRA   0x10
# define ERR_INITIAL 0x20


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

typedef	struct	s_token
{
	int	e_counter;
	int	p_counter;
	int	c_counter;
}				t_token;

typedef	struct s_map
{
	t_list	*lines;
	char	**matrix;
	int		rows;
	int		cols;
}				t_map;

//mlx utils
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
int		handle_key_input(int keysym, t_var	*data);
int		close_win(t_var *data);
int		render_window(t_var *vars);

//args_parser
void	check_input(int argc, char **argv);
int		check_ber(char *arg);
int		check_path(char *path);
void	print_usage();

//map_parser
t_list	*read_map(const char *path);

//map validation
int		validate_map(t_map *map);

//error_handler
int		map_error();
void	print_validation_errors(int err);

//map_checker
int		check_line_errors(char *row,t_map *map, t_token *token);

//map_utils
int		row_len(char *line);
int		no_extra_lines(t_list *map_lines);

//map_walls_checker
int		valid_walls(t_map **map);
// int	has_only_wall_chars(char *line);

//map_to_matrix.c
char	**map_lines_to_matrix(t_map *map);

void	free_map(t_map *map);
void	free_map_matrix(t_map *map);
void	free_map_lines(t_map *map);

#endif