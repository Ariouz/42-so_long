/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <vicalvez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 21:28:11 by vicalvez          #+#    #+#             */
/*   Updated: 2024/01/31 15:38:05 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_map(char *filename, t_game **game)
{
	t_list	*tiles;
	t_map	*map;
	int		fd;
	int		y;

	map = malloc(sizeof(t_map));
	map->total_coins = 0;
	map->tiles = NULL;
	map->x_tiles = 0;
	tiles = malloc(sizeof(t_list));
	tiles->content = NULL;
	tiles->next = NULL;
	(*game)->map = map;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		(*game)->map->tiles = tiles;
		cleanup(*game);
		ft_printf("Error: Map not found\n");
		exit(1);
	}
	loop_map(game, tiles, &y, fd);
	close(fd);
	(*game)->map->tiles = tiles;
	(*game)->map->y_tiles = y;
}

void	loop_map(t_game	**game, t_list	*tiles, int *y, int fd)
{
	char	*line;

	line = get_next_line(fd);
	*y = 0;
	while (line != NULL)
	{
		if (process_map_line(line, *y, &tiles, game) != 0)
		{
			free(line);
			close(fd);
			(*game)->map->tiles = tiles;
			cleanup(*game);
			ft_printf("Error\n Map must be rectangular\n");
			exit(3);
		}
		free(line);
		line = get_next_line(fd);
		(*y)++;
	}
}

int	process_map_line(char *line, int y, t_list **tiles, t_game **game)
{
	int		x;
	int		i;
	t_list	*tile;

	x = 0;
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		tile = create_tile(tiles, x, y, line[i]);
		ft_lstadd_back(tiles, tile);
		if (((t_coord *)tile->content)->type == COIN)
			(*game)->map->total_coins++;
		if (((t_coord *)tile->content)->type == PLAYER_SPAWN)
		{
			(*game)->player->pos_x = x * 32 + 8;
			(*game)->player->pos_y = y * 32 + 8;
		}
		x++;
		i++;
	}
	if ((*game)->map->x_tiles == 0)
		(*game)->map->x_tiles = x;
	else if ((*game)->map->x_tiles != x)
		return (1);
	return (0);
}

t_list	*create_tile(t_list	**tiles, int x, int y, char type)
{
	t_coord	*coord;
	t_list	*new;	

	coord = malloc(sizeof(t_coord));
	coord->x = x;
	coord->y = y;
	coord->type = type;
	new = ft_lstnew(tiles);
	new->content = coord;
	new->next = NULL;
	return (new);
}

void	free_lst_content(void *content)
{
	free(content);
}
