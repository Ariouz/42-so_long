/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_manager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <vicalvez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 20:53:24 by vicalvez          #+#    #+#             */
/*   Updated: 2024/01/31 15:20:04 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_coord	*get_tile_at(t_game **game, int x, int y)
{
	t_map	*map;
	t_list	*tiles;
	t_list	*next;
	t_coord	*tile;

	map = (*game)->map;
	tiles = map->tiles;
	next = tiles->next;
	while (next != NULL)
	{
		tile = (t_coord *) next->content;
		if (tile->x == x && tile->y == y)
			return (tile);
		next = next->next;
	}
	return (NULL);
}

int	collide_tile(t_coord *tile, t_player *player)
{
	int	tile_x;
	int	tile_y;
	int	tile_size;

	tile_x = tile->x * 32;
	tile_y = tile->y * 32;
	tile_size = 32;
	return (player->pos_x < tile_x + tile_size
		&& player->pos_x + PLAYER_SIZE > tile_x
		&& player->pos_y < tile_y + tile_size
		&& player->pos_y + PLAYER_SIZE > tile_y);
}

t_coord	*collide(t_game *game, t_player *player, char type)
{
	t_coord	*tile;
	t_coord	player_tile;
	int		i;
	int		j;

	player_tile.x = (player->pos_x) / 32;
	player_tile.y = (player->pos_y) / 32;
	player_tile.type = get_tile_at(&game, player_tile.x, player_tile.y)->type;
	i = player_tile.x - 1;
	while (i <= player_tile.x + 1)
	{
		j = player_tile.y - 1;
		while (j <= player_tile.y + 1)
		{
			tile = get_tile_at(&game, i, j);
			if (tile)
				if (collide_tile(tile, player) && tile->type == type)
					return (tile);
			j++;
		}
		i++;
	}
	return (NULL);
}
