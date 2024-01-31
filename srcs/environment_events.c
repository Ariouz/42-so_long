/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment_events.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <vicalvez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 15:30:48 by vicalvez          #+#    #+#             */
/*   Updated: 2024/01/31 15:16:03 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move(t_game **game, t_player *player)
{
	t_coord	*tile;

	(*game)->moves++;
	ft_printf("You moved %d times\n", (*game)->moves);
	check_lose(*game);
	tile = collide(*game, player, COIN);
	if (tile)
		pick_coin(game, tile);
	if (collide(*game, player, EXIT) != NULL
		&& (*game)->player_coins == (*game)->map->total_coins)
		win_game(game);
}

void	move_up(t_game **game)
{
	t_player	*player;

	player = (*game)->player;
	(*game)->player->sprite = IDLE_TOP;
	if (move_y(game, player, UP_DIRECTION))
		move(game, player);
}

void	move_down(t_game **game)
{
	t_player	*player;

	player = (*game)->player;
	(*game)->player->sprite = IDLE_BOTTOM;
	if (move_y(game, player, DOWN_DIRECTION))
		move(game, player);
}

void	move_left(t_game **game)
{
	t_player	*player;

	player = (*game)->player;
	(*game)->player->sprite = IDLE_LEFT;
	if (move_x(game, player, LEFT_DIRECTION))
		move(game, player);
}

void	move_right(t_game **game)
{
	t_player	*player;

	player = (*game)->player;
	(*game)->player->sprite = IDLE_RIGHT;
	if (move_x(game, player, RIGHT_DIRECTION))
		move(game, player);
}
