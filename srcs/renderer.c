/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <vicalvez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:40:47 by vicalvez          #+#    #+#             */
/*   Updated: 2024/01/31 14:44:55 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	render_all(void **ptr)
{
	t_game	**game;
	t_img	*frame_img;

	game = (t_game **) ptr;
	frame_img = mlx_new_image((*game)->mlx, (*game)->map->x_tiles * 32,
			(*game)->map->y_tiles * 32);
	render_map(game, (*game)->render_img);
	put_img_to_img(*frame_img, *(*game)->render_img, 0, 0);
	render_player(game, frame_img);
	mlx_put_image_to_window((*game)->mlx, (*game)->mlx_window, frame_img, 0, 0);
	render_texts(*game);
	increment_enemy_animation(*game);
	increment_coin_animation(*game);
	mlx_destroy_image((*game)->mlx, frame_img);
	return (1);
}

void	render_test(t_game *game)
{
	t_img	*img;
	t_img	wall;

	img = mlx_new_image(game->mlx, game->map->x_tiles * 32,
			game->map->y_tiles * 32);
	wall = *(t_img *)get_asset(WALL, &game)->mlx_img;
	put_img_to_img(*img, wall, 0, 0);
	mlx_put_image_to_window(game->mlx, game->mlx_window, img, 0, 0);
}

void	render_map(t_game **game, t_img *render_img)
{
	t_coord	*coord;
	t_list	*next;

	if (!(*game)->map || !(*game)->map->tiles)
	{
		ft_printf("Error while rendering map");
		return ;
	}
	next = (*game)->map->tiles->next;
	while (next != NULL)
	{
		coord = (t_coord *) next->content;
		render(coord, game, render_img);
		next = next->next;
	}
}

void	render(t_coord *coord, t_game **game, t_img *render_img)
{
	t_asset	*asset;
	t_img	asset_img;

	asset = get_asset(coord->type, game);
	if (coord->type == EXIT)
	{
		if ((*game)->player_coins == (*game)->map->total_coins)
			asset = get_asset(EXIT, game);
		else
			asset = get_asset(AIR, game);
	}
	if (coord->type == COIN || coord->type == ENEMY)
	{
		asset_img = *(t_img *)get_asset(AIR, game)->mlx_img;
		put_img_to_img(*render_img, asset_img, coord->x * 32, coord->y * 32);
		asset = get_sprite_asset_by_type(*game, coord->type);
		if (!asset)
			return ;
		put_img_to_img(*render_img, *(t_img *)asset->mlx_img, coord->x * 32 + 8,
			coord->y * 32 + 8);
		return ;
	}
	asset_img = *(t_img *)asset->mlx_img;
	put_img_to_img(*render_img, asset_img, coord->x * 32, coord->y * 32);
}

void	render_texts(t_game *game)
{
	char	*display;
	char	*count;

	count = ft_itoa(game->player_coins);
	display = ft_strjoin("Coins: ", count);
	mlx_string_put(game->mlx, game->mlx_window, 5, 20, 0xFFFFFF, display);
	free(count);
	free(display);
	count = ft_itoa(game->moves);
	display = ft_strjoin("Moves: ", count);
	mlx_string_put(game->mlx, game->mlx_window, 70, 20, 0xFFFFFF, display);
	free(count);
	free(display);
}
