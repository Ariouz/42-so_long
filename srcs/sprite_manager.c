/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <vicalvez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:37:00 by vicalvez          #+#    #+#             */
/*   Updated: 2024/01/31 14:50:03 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_sprite	*create_sprite(char *basePath, int n, char type, t_game *game)
{
	int			i;
	t_asset		*asset;
	t_asset		**assets;
	t_sprite	*sprite;

	i = 0;
	assets = malloc(sizeof(t_asset *) * n);
	while (i < n)
	{
		asset = malloc(sizeof(t_asset));
		asset->type = type;
		asset->path = get_sprite_path(basePath, ".xpm", i);
		asset->width = 32;
		asset->height = 32;
		asset->mlx_img = mlx_xpm_file_to_image(game->mlx, asset->path,
				&asset->width, &asset->height);
		if (!asset->mlx_img)
			ft_printf("Image not loaded for path %s\n", asset->path);
		assets[i] = asset;
		i++;
	}
	sprite = malloc(sizeof(t_sprite));
	sprite->total_frames = n;
	sprite->sprites = assets;
	return (sprite);
}

t_asset	*get_sprite_asset_by_type(t_game *game, char type)
{
	if (type == COIN)
		return (get_sprite_asset(game->coin_animation_data->sprite,
				game->coin_animation_data->frame_index));
	else if (type == ENEMY)
		return (get_sprite_asset(game->enemy_data->sprite,
				game->enemy_data->frame_index));
	return (NULL);
}

t_asset	*get_sprite_asset(t_sprite *sprite, int index)
{
	return (sprite->sprites[index]);
}

char	*get_sprite_path(char *basepath, char *extension, int index)
{
	char	*itoa;
	char	*name;
	char	*path;

	itoa = ft_itoa(index);
	name = ft_strjoin(basepath, itoa);
	path = ft_strjoin(name, extension);
	free(itoa);
	free(name);
	return (path);
}

void	free_sprite(t_game *game, t_animation_data *data)
{
	int			i;
	t_sprite	*sprite;

	i = 0;
	sprite = data->sprite;
	while (i < sprite->total_frames)
	{
		mlx_destroy_image(game->mlx, sprite->sprites[i]->mlx_img);
		free(sprite->sprites[i]->path);
		free(sprite->sprites[i]);
		i++;
	}
	free(sprite->sprites);
	free(data->sprite);
	free(data);
}
