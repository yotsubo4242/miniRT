/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitahar <tkitahar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 20:15:01 by tkitahar          #+#    #+#             */
/*   Updated: 2025/02/18 21:31:47 by tkitahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <limits.h>
# include <stdarg.h>
# include <stddef.h>
# include <unistd.h>
# include <stdint.h>
# include <stdlib.h>

// is
int					ft_isalpha(int c);
int					ft_isupper(int c);
int					ft_islower(int c);
int					ft_isdigit(int c);
int					ft_isascii(int c);
int					ft_isalnum(int c);
int					ft_isprint(int c);
int					ft_isspace(int c);

// to
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_atoi(const char *str);
char				*ft_itoa(int n);

// mem
void				*ft_memset(void *str, int c, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);

// str
size_t				ft_strlen(const char *s);
size_t				ft_strnlen(const char *s, size_t maxlen);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnstr(const char *haystack, const char *needle,
						size_t len);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
char				*ft_strdup(const char *s);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_strldup(const char *s, int len);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
int					ft_strcmp(const char *s1, const char *s2);

// put
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);

// ft_stdlib
unsigned int		ft_abs(int n);
void				ft_bzero(void *s, size_t n);
char				**ft_split(char const *s, char c);
void				*ft_calloc(size_t n, size_t m);

// printf
int					ft_printf(const char *str, ...);
int					ft_putchar(char c);
int					ft_putstr(char *c);
int					ft_putnbr(long nbr, char *base);
int					ft_putaddress(uintptr_t nbr, char *base);

// dprintf
void				ft_dprintf(int fd, const char *str, ...);
void				ft_dputchar(int fd, char c);
void				ft_dputstr(int fd, char *c);
void				ft_dputnbr(int fd, long nbr, char *base);
void				ft_dputaddress(int fd, uintptr_t nbr, char *base);

#endif
