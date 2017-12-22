/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaznodi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 14:55:28 by vkaznodi          #+#    #+#             */
/*   Updated: 2017/12/01 14:55:29 by vkaznodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		get_len(char const *s, char c)
{
	size_t		i;
	size_t		count;

	i = 0;
	count = 0;
	if (s[i] == c)
		i++;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		count++;
	}
	return (count);
}

static int		words(char const *s, char c)
{
	size_t		i;
	size_t		count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
			count++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (count);
}

char			**ft_strsplit(char const *s, char c)
{
	int			i;
	int			j;
	int			a;
	int			w;
	char		**str;

	j = 0;
	w = -1;
	if (!s || !(str = (char **)malloc(sizeof(*str) * (words(s, c) + 1))))
		return (NULL);
	while (++w < words(&s[j], c))
	{
		a = 0;
		i = get_len((char*)s, c);
		if (!(str[w] = (char*)malloc(sizeof(*str) * (i + 1))))
			str[w] = NULL;
		while (s[j] == c)
			j++;
		while (s[j] != c && s[j])
			str[w][a++] = s[j++];
		str[w][a] = '\0';
	}
	str[w] = 0;
	return (str);
}
