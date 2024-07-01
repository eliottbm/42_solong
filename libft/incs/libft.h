/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebengtss <ebengtss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 13:37:52 by ebengtss          #+#    #+#             */
/*   Updated: 2024/07/01 12:01:59 by ebengtss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdarg.h>
# include <stdint.h>

# ifndef GBL_BUFFER_SIZE
#  define GNL_BUFFER_SIZE 1
# endif

typedef struct s_collec
{
	int				xc;
	int				yc;
	struct s_collec	*next;
}					t_collec;

typedef struct s_img
{
	void			*img;
	char			*pimg;
	int				ximg;
	int				yimg;
	struct s_img	*next;
}					t_img;

t_collec	*ft_colnew(int x, int y);

t_img		*ft_imgnew(char *path, int x, int y);

t_collec	*ft_collast(t_collec *lst);

t_img		*ft_imglast(t_img *lst);

size_t		ft_strlen(char const *str);

size_t		ft_strlcpy(char *dst, const char *src, size_t size);

size_t		ft_strlcat(char *dst, const char *src, size_t size);

void		ft_bzero(void *s, size_t n);

void		ft_striteri(char *s, void (*f)(unsigned int, char *));

void		ft_putchar_fd(char c, int fd);

void		ft_putstr_fd(char *s, int fd);

void		ft_putendl_fd(char *s, int fd);

void		ft_putnbr_fd(int n, int fd);

void		ft_coladd_front(t_collec **lst, t_collec *new);

void		ft_imgadd_front(t_img **lst, t_img *new);

void		ft_coladd_back(t_collec **lst, t_collec *new);

void		ft_imgadd_back(t_img **lst, t_img *new);

void		ft_lstdelone(t_collec *lst, void (*del)(int x, int y));

void		ft_colclear(t_collec **lst);

void		ft_imgclear(t_img **lst);

void		ft_putchar_len(char c, int *counter);

void		ft_putstr_len(char *s, int *counter);

void		ft_putnbr_len(int n, int *counter);

void		ft_puthex_len(unsigned int nb, int uplow, int *counter);

void		ft_putuns_len(unsigned int n, int *counter);

void		ft_getaddress(void *ptr, int *counter);

void		ft_gnlcpy(char *dst, char const *src, size_t size);

void		*ft_memset(void *s, int c, size_t n);

void		*ft_memcpy(void *dest, const void *src, size_t n);

void		*ft_memmove(void *dest, const void *src, size_t n);

void		*ft_memchr(const void *s, int c, size_t n);

void		*ft_calloc(size_t nmemb, size_t size);

char		*ft_strchr(const char *s, int c);

char		*ft_strrchr(const char *s, int c);

char		*ft_strnstr(char const *big, char const *little, size_t len);

char		*ft_strdup(char const *src);

char		*ft_substr(char const *s, unsigned int start, size_t len);

char		*ft_strjoin(char const *s1, char const *s2);

char		*ft_strtrim(char const *s1, char const *set);

char		**ft_split(char const *s, char c);

char		*ft_itoa(int n);

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));

char		*ft_gnljoin(char const *s1, char const *s2);

char		*ft_gnldup(char const *src);

void		ft_gnlcpy(char *dst, char const *src, size_t size);

char		*ft_get_next_line(int fd);

int			ft_isalpha(int c);

int			ft_isdigit(int c);

int			ft_isalnum(int c);

int			ft_isascii(int c);

int			ft_isprint(int c);

int			ft_toupper(int c);

int			ft_tolower(int c);

int			ft_strncmp(const char *s1, const char *s2, size_t n);

int			ft_memcmp(const void *s1, const void *s2, size_t n);

int			ft_atoi(char const *str);

int			ft_colsize(t_collec *lst);

int			ft_imgsize(t_img *lst);

int			ft_printf(const char *args, ...);

int			is_nl(char *line);

#endif
