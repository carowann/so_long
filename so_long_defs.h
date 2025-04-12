/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_defs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 14:25:38 by cwannhed          #+#    #+#             */
/*   Updated: 2025/04/12 14:25:42 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_DEFS_H
# define SO_LONG_DEFS_H

# define USAGE_MSG "Usage: ./so_long <maps/map_file.ber>\n"

# define MALLOC_ERROR	0
# define MAP_ERROR		1

# define TILE_WALL		'1'
# define TILE_FLOOR		'0'
# define TILE_PLAYER	'P'
# define TILE_EXIT		'E'
# define TILE_COLLECT	'C'
# define TILE_P_ON_EXIT	'B'

# define ERR_RECT				0x01
# define ERR_WALLS				0x02
# define ERR_INVALID			0x04
# define ERR_TOKEN				0x08
# define ERR_EXTRA				0x10
# define ERR_INITIAL			0x20
# define ERR_UNREACH_COLLECT	0x40
# define ERR_UNREACH_EXIT		0x80
# define ERR_TOO_BIG			0x100

# define TILE_SIZE 64

#endif