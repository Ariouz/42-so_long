/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <vicalvez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:00:34 by vicalvez          #+#    #+#             */
/*   Updated: 2024/01/31 15:22:12 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	add_assets(t_game **game)
{
	add_asset(WALL, "assets/wall.xpm", game);
	add_asset(AIR, "assets/grass.xpm", game);
	add_asset(EXIT, "assets/exit.xpm", game);
	add_asset(PLAYER_SPAWN, "assets/player_spawn.xpm", game);
	add_asset(IDLE_TOP, "assets/player/idle/idle_top.xpm", game);
	add_asset(IDLE_BOTTOM, "assets/player/idle/idle_bottom.xpm", game);
	add_asset(IDLE_LEFT, "assets/player/idle/idle_left.xpm", game);
	add_asset(IDLE_RIGHT, "assets/player/idle/idle_right.xpm", game);
}

void	add_asset(char type, char *path, t_game **game)
{
	t_list	*new;
	t_asset	*asset;

	asset = malloc(sizeof(t_asset));
	asset->type = type;
	asset->path = path;
	asset->width = 32;
	asset->height = 32;
	asset->mlx_img = mlx_xpm_file_to_image((*game)->mlx, path,
			&asset->width, &asset->height);
	new = ft_lstnew((*game)->assets);
	new->next = NULL;
	new->content = asset;
	ft_lstadd_back(&(*game)->assets, new);
}

void	load_assets(t_game **game)
{
	(*game)->assets = malloc(sizeof(t_list));
	(*game)->assets->content = NULL;
	(*game)->assets->next = NULL;
	add_assets(game);
	load_enemy_assets(game);
	load_coin_assets(game);
}

t_asset	*get_asset(char type, t_game **game)
{
	t_list	*next;
	t_list	*assets;
	t_asset	*asset;

	assets = (*game)->assets;
	if (!assets)
		return (NULL);
	next = assets->next;
	while (next != NULL)
	{
		asset = (t_asset *) next->content;
		if (asset->type == type)
			return (asset);
		next = next->next;
	}
	return (NULL);
}

void	free_images(t_game **game)
{
	t_list	*next;
	t_asset	*asset;

	if (!(*game)->assets)
		return ;
	next = (*game)->assets->next;
	while (next != NULL)
	{
		asset = (t_asset *) next->content;
		mlx_destroy_image((*game)->mlx, asset->mlx_img);
		next = next->next;
	}
}
