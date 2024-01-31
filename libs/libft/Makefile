NAME= libft.a

SRCS= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_putstr_fd.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
ft_printf/ftprintf.c ft_printf/printf_utils.c ft_printf/printf_printer.c \
ft_printf/printf_flags.c ft_printf/printf_pointer.c ft_printf/printf_decimal.c \
ft_printf/printf_unsigned.c ft_printf/printf_hex.c ft_printf/printf_free.c ft_printf/printf_global.c
OBJS= $(SRCS:.c=.o)

BONUS_SRCS= ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

ifdef BONUS
ALL_OBJS= $(OBJS) $(BONUS_OBJS)
else
ALL_OBJS= $(OBJS)
endif

CC= gcc -Wall -Wextra -Werror

$(NAME): $(ALL_OBJS)
	ar -rcs $(NAME) $(ALL_OBJS)

bonus:
	$(MAKE) BONUS=1

all: $(NAME)

%.o: %.c
	$(CC) -c $< -o $@ -I.

clean:
	rm -rf $(ALL_OBJS)

fclean: clean
	rm -rf $(NAME)
	@rm -rf $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re bonus
