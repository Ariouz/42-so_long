/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <vicalvez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 15:33:45 by vicalvez          #+#    #+#             */
/*   Updated: 2024/01/31 15:10:11 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	register_hooks(t_game **game)
{
	mlx_hook((*game)->mlx_window, DESTROY_HOOK, 0, close_window, *game);
	mlx_hook((*game)->mlx_window, KEY_PRESSED_HOOK,
		1L << 0, process_key_hook, *game);
	mlx_loop_hook((*game)->mlx, render_all, game);
}

int	process_key_hook(int keycode, t_game *game)
{
	if (keycode == ESC_KEYCODE)
		close_window(game);
	else if (keycode == W_KEYCODE)
		move_up(&game);
	else if (keycode == A_KEYCODE)
		move_left(&game);
	else if (keycode == S_KEYCODE)
		move_down(&game);
	else if (keycode == D_KEYCODE)
		move_right(&game);
	return (0);
}
