/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <vicalvez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 19:05:36 by vicalvez          #+#    #+#             */
/*   Updated: 2024/01/31 15:26:38 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_enemy_assets(t_game **game)
{
	(*game)->enemy_data = malloc(sizeof(t_animation_data));
	(*game)->enemy_data->frame_index = 0;
	(*game)->enemy_data->current_delay = 0;
	(*game)->enemy_data->delay = 50;
	(*game)->enemy_data->sprite = create_sprite("assets/flam/flam",
			3, ENEMY, *game);
}

char	get_enemy_animation(t_game *game)
{
	return (game->enemy_data->frame_index);
}

void	increment_enemy_animation(t_game *game)
{
	t_animation_data	*data;

	data = game->enemy_data;
	if (data->current_delay >= data->delay)
	{
		if (data->frame_index >= data->sprite->total_frames - 1)
			data->frame_index = 0;
		else
			data->frame_index++;
		data->current_delay = 0;
	}
	else
		data->current_delay++;
}

void	check_lose(t_game *game)
{
	t_player	*player;

	player = game->player;
	if (collide(game, player, ENEMY) != NULL)
		lose_game(game);
}
