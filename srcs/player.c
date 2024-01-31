/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <vicalvez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:09:43 by vicalvez          #+#    #+#             */
/*   Updated: 2024/01/31 14:47:29 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_player(t_game **game)
{
	(*game)->player = malloc(sizeof(t_player));
	(*game)->player->sprite = IDLE_RIGHT;
}

void	render_player(t_game **game, t_img *frame_img)
{
	t_player	*player;
	char		sprite;
	t_asset		*asset;

	player = (*game)->player;
	sprite = (*game)->player->sprite;
	asset = get_asset(sprite, game);
	if (!asset)
	{
		ft_printf("No asset found");
		return ;
	}
	put_img_to_img(*frame_img, *(t_img *)asset->mlx_img,
		player->pos_x, player->pos_y);
}
