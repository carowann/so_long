/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 18:11:48 by cwannhed          #+#    #+#             */
/*   Updated: 2025/04/07 18:12:20 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_key_input(int keysym, t_game	*game)
{
	if (keysym == XK_Escape)
		cleanup_and_exit(game, EXIT_SUCCESS);
	else if (keysym == XK_Up || keysym == XK_w)
		move_player(game, &game->map, 0, -1);
	else if (keysym == XK_Left || keysym == XK_a)
		move_player(game, &game->map, -1, 0);
	else if (keysym == XK_Down || keysym == XK_s)
		move_player(game, &game->map, 0, 1);
	else if (keysym == XK_Right || keysym == XK_d)
		move_player(game, &game->map, 1, 0);
	return (0);
}
              