/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <vicalvez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 19:00:19 by vicalvez          #+#    #+#             */
/*   Updated: 2024/01/31 15:08:23 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map(t_game *game, char *name)
{
	int				res;
	t_map_checking	*map_check;

	res = check_map_filename(name);
	if (res != 0)
		return (ft_printf("Error\n Invalid map name / extension\n"));
	map_check = malloc(sizeof(t_map_checking));
	map_check->collectible = 0;
	map_check->player_spawn = 0;
	map_check->enemy = 0;
	map_check->exit = 0;
	map_check->air = 0;
	map_check->filename = name;
	map_check->line_size = 0;
	if (check_map_components(game, map_check) != 0)
	{
		free(map_check);
		return (ft_printf("Invalid map content\n"));
	}
	free(map_check);
	return (0);
}

int	check_map_components(t_game *game, t_map_checking *map_check)
{
	t_list	*tiles;
	t_coord	*tile;

	tiles = game->map->tiles;
	while (tiles->next != NULL)
	{
		tiles = tiles->next;
		tile = (t_coord *) tiles->content;
		map_check->line_size++;
		if (!is_valid_map_char(tile->type))
			return (ft_printf("Error\n '%c' is invalid char: ", tile->type));
		if ((tile->y == 0 || tile->y == game->map->y_tiles - 1 || tile->x == 0
				|| tile->x == game->map->x_tiles - 1) && tile->type != WALL)
			return (ft_printf("Error\n Map isn't bordered by walls: "));
		if (tile->type == EXIT)
			map_check->exit++;
		if (tile->type == PLAYER_SPAWN)
			map_check->player_spawn++;
		if (tile->type == COIN)
			map_check->collectible++;
		if (tile->type == AIR)
			map_check->air++;
	}
	return (check_map_content(map_check));
}

int	check_map_content(t_map_checking *map_check)
{
	if (map_check->exit != 1)
		return (ft_printf("Error \nMap must contain 1 exit: "));
	if (map_check->player_spawn != 1)
		return (ft_printf("Error \nMap must contain 1 player spawn: "));
	if (map_check->collectible == 0)
		return (ft_printf("Error\n Map must contain at least 1 collectible: "));
	if (map_check->air == 0)
		return (ft_printf("Error \nMap must contain at least 1 air tile: "));
	return (0);
}

int	check_map_filename(char *name)
{
	char	*ex;
	int		res;

	ex = ft_substr(name, ft_strlen(name) - 4, 4);
	res = 1;
	if (ft_strncmp(ex, ".ber", 4) == 0)
		res = 0;
	free(ex);
	return (res);
}

int	is_valid_map_char(char c)
{
	return (c == WALL || c == PLAYER_SPAWN || c == AIR || c == COIN
		|| c == ENEMY || c == EXIT);
}
