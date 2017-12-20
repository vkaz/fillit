/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaznodi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 14:55:12 by vkaznodi          #+#    #+#             */
/*   Updated: 2017/12/01 14:55:14 by vkaznodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char		*str;
	int			i;
	int			c;
	int			a;

	c = 0;
	a = 0;
	i = ft_strlen((char*)s);
	while (s[i - 1] == ' ' || s[i - 1] == ',' || s[i - 1] == '\n' ||
			s[i - 1] == '\t')
			i--;
	if (i <= 0)
		i = 0;
	while (s[c] == ' ' || s[c] == ',' || s[c] == '\n' || s[c] == '\t')
		c++;
	str = (char*)malloc(sizeof(*str) * ((i - c) + 1));
	if (!str)
		return (NULL);
	if (str)
	{
		while (c < i)
			str[a++] = s[c++];
		str[a] = '\0';
		return (str);
	}
	return (NULL);
}