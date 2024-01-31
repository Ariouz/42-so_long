/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coin.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <vicalvez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:33:30 by vicalvez          #+#    #+#             */
/*   Updated: 2024/01/31 15:22:38 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_coin_assets(t_game **game)
{
	(*game)->coin_animation_data = malloc(sizeof(t_animation_data));
	(*game)->coin_animation_data->frame_index = 0;
	(*game)->coin_animation_data->current_delay = 0;
	(*game)->coin_animation_data->delay = 10;
	(*game)->coin_animation_data->sprite = create_sprite("assets/coin/tile",
			14, COIN, *game);
}

char	get_coin_animation(t_game *game)
{
	return (game->coin_animation_data->frame_index);
}

void	increment_coin_animation(t_game *game)
{
	t_animation_data	*data;

	data = game->coin_animation_data;
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
