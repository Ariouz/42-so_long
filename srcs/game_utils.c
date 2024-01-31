/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <vicalvez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:00:44 by vicalvez          #+#    #+#             */
/*   Updated: 2024/01/31 15:15:24 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	pick_coin(t_game **game, t_coord *tile)
{
	tile->type = AIR;
	(*game)->player_coins++;
}

void	win_game(t_game **game)
{
	mlx_loop_end((*game)->mlx);
	ft_printf("----------------\n\n     YOU WON 	!\n\n----------------\n");
}

void	lose_game(t_game *game)
{
	mlx_loop_end(game->mlx);
	ft_printf("----------------\n\n     YOU LOST 	!\n\n----------------\n");
}

int	close_window(t_game *game)
{
	mlx_loop_end(game->mlx);
	return (0);
}
