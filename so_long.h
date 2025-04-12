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

# include <X11/keysym.h>
# include <X11/X.h>
# include <stdlib.h>
# include <fcntl.h>

# include "minilibx-linux/mlx.h"
# include "libft/libft.h"
# include "so_long_defs.h"
# include "so_long_structs.h"

//args_parser
void	check_input(int argc, char **argv);

//map_parser
void	read_map(const char *path, t_game *game);

//map validation
int		validate_map(t_game *game, t_map *map);

//error_handler
int		cleanup_and_exit(t_game *game, int exit_code);
int		map_error(t_map *map, int cause);
void	free_textures(t_var *var, t_textures *tex);
void	print_validation_errors(int err);

//map_checker

//map_utils
int		row_len(char *line);
void	free_map(t_map *map);
void	free_map_matrix(char **matrix, int rows);

//map_to_matrix.c
void	map_lines_to_matrix(t_map *map);

//path_validation
void	validate_paths(t_map *map);

//map_render.c
void	render_tile(t_game *game, int row, int col);
void	render_map_tex(t_game *game);

//mlx_textures.c
void	load_textures(t_game *game, t_var *env, t_textures *tex);

//mlx_events.c
int		handle_key_input(int keysym, t_game *game);

//mlx_window,c
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
void	render_window(t_game *game);

//player_movements
void	move_player(t_game *game, t_map *map, int x, int y);

#endif
