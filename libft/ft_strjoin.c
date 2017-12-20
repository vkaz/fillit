/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaznodi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 14:54:54 by vkaznodi          #+#    #+#             */
/*   Updated: 2017/12/01 14:54:55 by vkaznodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*str;
	int			i;
	int			c;
	int			c1;

	i = 0;
	c = 0;
	c1 = 0;
	while (s1[c])
		c++;
	while (s2[c1])
		c1++;
	str = (char*)malloc(sizeof(*str) * (c + c1));
	if (str)
	{
		
		while (*s1)
			str[i++] = *s1++;
		while (*s2)
			str[i++] = *s2++;
		return ((char*)str);
	}
	return (NULL);
}
