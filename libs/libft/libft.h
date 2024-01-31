/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <vicalvez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:17:59 by vicalvez          #+#    #+#             */
/*   Updated: 2024/01/14 17:17:28 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <stdarg.h>

typedef struct s_list
{
	void				*content;
	struct s_list		*next;
}	t_list;

int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
int				ft_atoi(const char *nptr);
int				ft_lstsize(t_list *lst);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strnstr(const char *big, const char *little, size_t n);
char			*ft_strdup(const char *s);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
size_t			ft_strlen(const char *s);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
void			*ft_memset(void *s, int c, size_t n);
void			ft_putstr_fd(char *s, int fd);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_calloc(size_t nmemb, size_t size);
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
void			ft_lstadd_front(t_list **lst, t_list *new);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstnew(void *content);
t_list			*ft_lstlast(t_list *lst);
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));
// FT_PRINTF					
# include <stdarg.h>

typedef struct s_format
{
	char	type;
}	t_format;

typedef struct s_arg
{
	char		*arg;
	char		*flags;
	int			arg_len;
	t_format	*format;
}	t_arg;

int			ft_printf(const char *s, ...);
int			ft_has_flag(char *flags, char c);
int			ft_get_fmw(char *flags, char type);
int			ft_hex_len(unsigned long long ptr);
int			fill_fmw(int len, int fmw, char *flags);
int			ft_print_char(char c, char *flags);
int			ft_print_str(char *s, char *flags);
int			ft_print_str_two(char *s, char *flags);
int			ft_print_pointer(unsigned long long ptr, char *flags);
int			ft_print_unsigned_int(unsigned int n, char *flags);
int			ft_print_decimal(int i, char *flags);
int			ft_print_hex(unsigned int hex, char *flags, char type);
int			ft_print_arg(va_list args, t_arg *arg);
int			ft_print_global(va_list args, t_list *format_args, const char *s);
int			ft_absolute(int i);
void		print_hex(unsigned long long ptr, char type);
void		ft_add_format(t_list **formats, char type);
void		ft_free_args(void *arg);
void		ft_free_formats(void *v);
void		ft_printnbr(long n);
t_format	*ft_get_format_type(t_list *formats, char c);
t_list		*get_formats(void);

#endif