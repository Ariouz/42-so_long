/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <vicalvez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:46:59 by vicalvez          #+#    #+#             */
/*   Updated: 2024/01/31 15:40:37 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
	{
		ft_printf("Error\n A map filename is required\n");
		exit(1);
	}
	game = malloc(sizeof(t_game));
	game->moves = 0;
	game->player_coins = 0;
	game->mlx_window = NULL;
	game->render_img = NULL;
	init_mlx(&game, argc, argv);
	game->render_img = mlx_new_image(game->mlx, game->map->x_tiles * 32,
			game->map->y_tiles * 32);
	if (check_map(game, argv[1]) != 0)
	{
		cleanup(game);
		exit(2);
	}
	ft_printf("Total coins: %d\n", game->map->total_coins);
	mlx_loop(game->mlx);
	cleanup(game);
	return (0);
}

void	init_mlx(t_game **game, int argc, char **argv)
{
	(*game)->mlx = mlx_init();
	if ((*game)->mlx == NULL)
		exit(1);
	if (argc != 2)
		exit(1);
	init_player(game);
	load_assets(game);
	read_map(argv[1], game);
	(*game)->mlx_window = mlx_new_window((*game)->mlx,
			(*game)->map->x_tiles * 32, (*game)->map->y_tiles * 32, "so_long");
	if ((*game)->mlx_window == NULL)
	{
		free((*game)->mlx_window);
		exit(1);
	}
	register_hooks(game);
}

void	cleanup(t_game *game)
{
	ft_lstclear(&(game->map->tiles), free_lst_content);
	free(game->map->tiles);
	free(game->map);
	free_images(&game);
	ft_lstclear(&(game->assets), free_lst_content);
	free(game->assets);
	free_sprite(game, game->coin_animation_data);
	free_sprite(game, game->enemy_data);
	if (game->render_img)
		mlx_destroy_image(game->mlx, game->render_img);
	if (game->mlx_window)
		mlx_destroy_window(game->mlx, game->mlx_window);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free(game->player);
	free(game);
}
