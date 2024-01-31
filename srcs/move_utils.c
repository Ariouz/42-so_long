/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <vicalvez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:15:41 by vicalvez          #+#    #+#             */
/*   Updated: 2024/01/31 15:16:22 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_x(t_game **game, t_player *player, int direction)
{
	int	moved;

	moved = 0;
	while (moved < MOVEMENT_SPEED)
	{
		player->pos_x += direction;
		if (collide(*game, player, WALL))
		{
			player->pos_x -= direction;
			break ;
		}
		moved++;
	}
	return (moved > 0);
}

int	move_y(t_game **game, t_player *player, int direction)
{
	int	moved;

	moved = 0;
	while (moved < MOVEMENT_SPEED)
	{
		player->pos_y += direction;
		if (collide(*game, player, WALL))
		{
			player->pos_y -= direction;
			break ;
		}
		moved++;
	}
	return (moved > 0);
}
