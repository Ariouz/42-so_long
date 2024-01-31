NAME= so_long
FLAGS= -Wall -Werror -Wextra -O

SRCS_DIR= srcs/
SRCS= $(addprefix $(SRCS_DIR), \
	so_long.c \
	hooks_manager.c \
	environment_events.c \
	map_reader.c \
	renderer.c \
	assets_utils.c \
	player.c \
	collision_manager.c \
	game_utils.c \
	enemy.c \
	image_manager.c \
	sprite_manager.c \
	coin.c \
	map_checker.c \
	move_utils.c)

GNL_SRCS= libs/gnl/get_next_line.c libs/gnl/get_next_line_utils.c

OBJS= $(SRCS:.c=.o)
GNL_OBJS= $(GNL_SRCS:.c=.o)

LIBFT_DIR= libs/libft
LIBFT= $(LIBFT_DIR)/libft.a

MLX_DIR= libs/mlx
LIBS= -lm -L$(MLX_DIR) -lmlx -I$(MLX_DIR) -lXext -lX11

$(NAME): libft $(OBJS) $(GNL_OBJS)
	@gcc -g $(FLAGS) $(OBJS) $(GNL_OBJS) $(LIBFT) $(LIBS) -o $(NAME)

%.o: %.c
	gcc $(FLAGS) -c $< -o $@ $(LIBS)

all:
	@make $(NAME)

test:
	@make $(NAME)
	@./$(NAME) maps/valids/valid_map.ber

leaks:
	@make $(NAME)
	@valgrind -s --leak-check=full --show-leak-kinds=all ./$(NAME) maps/valids/map.ber

install:
	@cd libs/mlx && ./configure && cd ../../../

libft:
	@make -C $(LIBFT_DIR) bonus

clean:
	@make -C $(LIBFT_DIR) clean BONUS=1
	@rm -rf $(OBJS) $(GNL_OBJS)

fclean:
	make -C $(LIBFT_DIR) fclean BONUS=1
	@rm -rf $(OBJS) $(GNL_OBJS)
	@rm -rf $(NAME)

re:
	@make clean
	@make fclean
	@make all

.PHONY: all clean fclean re