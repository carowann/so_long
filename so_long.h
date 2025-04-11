/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 14:27:09 by cwannhed          #+#    #+#             */
/*   Updated: 2025/04/11 14:15:38 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "usage.h"
# include "minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <X11/X.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

# define MALLOC_ERROR	0
# define MAP_ERROR		1

# define TILE_WALL		'1'
# define TILE_FLOOR		'0'
# define TILE_PLAYER	'P'
# define TILE_EXIT		'E'
# define TILE_COLLECT	'C'
# define TILE_P_ON_EXIT	'B'

# define ERR_RECT    0x01
# define ERR_WALLS   0x02
# define ERR_INVALID 0x04
# define ERR_TOKEN   0x08
# define ERR_EXTRA   0x10
# define ERR_INITIAL 0x20
# define ERR_UNREACH_COLLECT 0x40
# define ERR_UNREACH_EXIT    0x80

# define WIDTH	400
# define HEIGHT 400

#define TILE_SIZE 64

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
	int moves;
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
	t_var		vars;
	t_textures	tex;
	t_token		token;
}				t_game;

//args_parser
void	check_input(int argc, char **argv);

//map_parser
void	read_map(const char *path, t_map *map);

//map validation
int		validate_map(t_game *game, t_map *map);

//error_handler
void	cleanup_and_exit(t_game *game, int exit_code);
int		map_error(t_map *map, int cause);
void	free_textures(t_var *var, t_textures *tex);

//map_checker
void	update_token_counts(t_token *token, char *line);
int		valid_chars(t_map *map, char *line, int row);

//map_utils
int		row_len(char *line);
void	free_map(t_map *map);
void	free_map_matrix(char **matrix, int rows);

//map_to_matrix.c
void	map_lines_to_matrix(t_map *map);

//path_validation
void	validate_paths(t_map *map);

//map_render.c
void	render_tile(t_map *map, t_var *vars, t_textures *tex, int row, int col);
void	render_map_tex(t_map *map, t_var *vars, t_textures *tex);

//mlx_textures.c
void	load_textures(t_var *vars, t_textures *tex);
void	load_textures(t_var *vars, t_textures *tex);

//mlx_events.c
int		handle_key_input(int keysym, t_game *game);

//mlx_utils.c
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);

//mlx_window,c
void	render_window(t_game *game);

//player_movements
void	move_player(t_game *game, t_map *map, int x, int y);


#endif
