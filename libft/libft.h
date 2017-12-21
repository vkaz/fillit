/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaznodi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 12:44:40 by vkaznodi          #+#    #+#             */
/*   Updated: 2017/12/01 12:47:09 by vkaznodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>

typedef	struct		t_list
{
	void			*content;
	size_t			content_size;
	struct t_list	*next;
}					t_list;
void	*ft_memccpy(void *dst, void *src, int c, size_t n);
void	*ft_memchr(const void *arr, int c, size_t n);
void	ft_bzero(char *b, size_t n);
void	*ft_memcpy(void *dst, void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t n);
void	*ft_memset(void *dst, int c, size_t n);
void	ft_putchar_fd(char c, int fd);
void	ft_putchar(char c);
void	ft_putendl(char const *s);
void	ft_putendl_fd(char const *s, int fd);
void	ft_putstr_fd(char const *str, int fd);
void	ft_putnbr(int n);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
void	ft_strdel(char **as);
void	ft_striter(char *s, void (*f)(char *));

int		ft_strequ(char const *s1, char const *s2);
int		ft_atoi(char *str);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int ch);
int		ft_isdigit(int c);
int		ft_isprint(int ch);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_tolower(int c);
int		ft_toupper(int c);
int		ft_strlen(char *s);
int		ft_strncmp(char *s1, char *s2, unsigned int n);
int		ft_strcmp(const char *s1, const char *s2);

char	*ft_strcat(char	*dest, const char *src);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strdup(char *src);
char	*ft_strncat(char *dest, const char *src, size_t n);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
char	*ft_strnstr(char	*str, const char *to_find, int len);
char	*ft_strstr(char *str, char *to_find);
char	*ft_strrchr(const char *str, int ch);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *str, int ch);
char	*ft_strmap(char const *s, char (*f)(char));
char	*ft_strnew(size_t size);
char	*ft_strtrim(char const *s);
char	**ft_strsplit(char const *s, char c);

size_t	ft_strlcat(char *dst, const char *src, size_t size);

#endif
