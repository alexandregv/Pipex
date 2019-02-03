/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 18:00:17 by hben-yah          #+#    #+#             */
/*   Updated: 2019/02/03 18:20:50 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>

size_t			ft_strlen(const char *s);
void			ft_putstr(char const *s);
char			*ft_strnew(size_t size);
char			*ft_strjoin(char const *s1, char const *s2);
void			ft_strdel(char **as);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strcat(char *s1, const char *s2);
void			ft_memdel(void **ap);
void			*ft_memalloc(size_t size);
void			ft_bzero(void *s, size_t n);
int				ft_atoi(const char *str);
void			ft_putnbr(int nb);
void			ft_putchar(char c);
void			ft_putendl(char const *s);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_realloc(char *s1, int lenght);
char			*ft_strncat(char *dest, const char *src, size_t n);
unsigned long	ft_strlcat(char *dest, const char *src, size_t size);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putchar_fd(char c, int fd);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			**ft_strtabdup(char **tab);
char			*ft_strdup(const char *s1);
size_t			ft_strtablen(char **tab);
size_t			ft_wrdcnt(const char *s, char c);
char			**ft_strsplit(char const *s, char c);
char			*ft_strjoin3(char const *s1, char const *s2, char const *s3);
void			ft_tabdel(void ***ap);
char			**ft_split_chars(char const *s, int (*is_separator)(int));
int				ft_isspace_wnt(int c);
char			**ft_strtabnew(size_t size);
void			ft_tabdel(void ***ap);

#endif
