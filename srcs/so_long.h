/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <vicalvez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:46:27 by vicalvez          #+#    #+#             */
/*   Updated: 2024/01/31 15:14:39 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libs/libft/libft.h"
# include "../libs/mlx/mlx.h"
# include "../libs/mlx/mlx_int.h"
# include "../libs/gnl/get_next_line.h"
# include <stdlib.h>
# include <fcntl.h>
# include <sys/time.h>
# include <stdint.h>

# define DESTROY_HOOK 17
# define KEY_PRESSED_HOOK 2

# define MOVEMENT_SPEED 8
# define PLAYER_SIZE 16

# define ESC_KEYCODE 65307
# define W_KEYCODE 119
# define A_KEYCODE 97
# define S_KEYCODE 115
# define D_KEYCODE 100

# define WALL '1'
# define AIR '0'
# define PLAYER_SPAWN 'P'
# define COIN 'C'
# define EXIT 'E'
# define ENEMY 'F'

# define IDLE_TOP ','
# define IDLE_BOTTOM ';'
# define IDLE_LEFT ':'
# define IDLE_RIGHT '!'

# define RIGHT_DIRECTION 1
# define LEFT_DIRECTION -1
# define DOWN_DIRECTION 1
# define UP_DIRECTION -1

typedef struct s_asset
{
	char	type;
	char	*path;
	int		width;
	int		height;
	void	*mlx_img;
}	t_asset;

typedef struct s_player
{
	int		pos_x;
	int		pos_y;
	char	sprite;
}	t_player;

typedef struct s_sprite
{
	t_asset	**sprites;
	int		total_frames;
}	t_sprite;

typedef struct s_animation_data
{
	int			frame_index;
	int			delay;
	int			current_delay;
	t_sprite	*sprite;
}	t_animation_data;

typedef struct s_coord
{
	int		x;
	int		y;
	char	type;
}	t_coord;

typedef struct s_map
{
	int		x_tiles;
	int		y_tiles;
	int		total_coins;
	t_list	*tiles;
}	t_map;

typedef struct s_game
{
	void				*mlx;
	void				*mlx_window;
	int					player_coins;
	int					moves;
	t_animation_data	*enemy_data;
	t_animation_data	*coin_animation_data;
	t_player			*player;
	t_map				*map;
	t_list				*assets;
	t_img				*render_img;
}	t_game;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_map_checking
{
	int		player_spawn;
	int		exit;
	int		collectible;
	int		enemy;
	int		air;
	int		line_size;
	char	*filename;
}	t_map_checking;

void			render_test(t_game *game);
void			init_mlx(t_game **game, int argc, char **argv);
void			cleanup(t_game *game);
void			register_hooks(t_game **game);
void			loop_map(t_game	**game, t_list	*tiles, int *y, int fd);
int				process_map_line(char *line, int y, t_list **tiles,
					t_game **game);
t_list			*create_tile(t_list	**tiles, int x, int y, char type);
void			print_coord(t_list *tiles);
void			render_map(t_game **game, t_img *render_img);
void			render(t_coord *coord, t_game **game, t_img *render_img);
void			render_texts(t_game *game);
void			free_lst_content(void *content);
void			add_asset(char type, char *path, t_game **game);
void			add_assets(t_game **game);
void			free_images(t_game **game);
void			init_player(t_game **game);
void			render_player(t_game **game, t_img *render_image);
void			move_up(t_game **game);
void			move_down(t_game **game);
void			move_left(t_game **game);
void			move_right(t_game **game);
void			move(t_game **game, t_player *player);
int				move_x(t_game **game, t_player *player, int direction);
int				move_y(t_game **game, t_player *player, int direction);
int				close_window(t_game *game);
int				process_key_hook(int keycode, t_game *game);
int				render_all(void **ptr);
int				collide_tile(t_coord *tile, t_player *player);
t_coord			*collide(t_game *game, t_player *player, char type);
void			read_map(char *filename, t_game **game);
void			load_assets(t_game **game);
void			pick_coin(t_game **game, t_coord *tile);
void			win_game(t_game **game);
void			check_lose(t_game *game);
void			lose_game(t_game *game);
unsigned int	get_pixel_img(t_img img, int x, int y);
void			put_pixel_img(t_img img, int x, int y, int color);
void			put_img_to_img(t_img dst, t_img src, int x, int y);
t_asset			*get_sprite_asset(t_sprite *sprite, int index);
t_sprite		*create_sprite(char *basePath, int n, char type, t_game *game);
t_asset			*get_sprite_asset_by_type(t_game *game, char type);
char			*get_sprite_path(char *basepath, char *extension, int index);
char			get_enemy_animation(t_game *game);
void			load_enemy_assets(t_game **game);
void			increment_coin_animation(t_game *game);
char			get_coin_animation(t_game *game);
void			load_coin_assets(t_game **game);
void			increment_enemy_animation(t_game *game);
void			free_sprite(t_game *game, t_animation_data *data);
t_asset			*get_asset(char type, t_game **game);
t_coord			*get_tile_at(t_game **game, int x, int y);
int				check_map_filename(char *name);
int				check_map(t_game *game, char *name);
int				check_map_components(t_game *game, t_map_checking *map_check);
int				is_valid_map_char(char c);
int				check_map_content(t_map_checking *map_check);

#endif