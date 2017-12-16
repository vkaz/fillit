/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaznodi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 11:56:58 by vkaznodi          #+#    #+#             */
/*   Updated: 2017/11/16 11:57:00 by vkaznodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(char *str, char *to_find)
{
	int		i;
	int		c;
	int		l;

	i = 0;
	c = 0;
	l = ft_strlen(to_find);
	if (l > 0)
	{
		while (str[i])
		{
			str[i] == to_find;
			if (str[i] ==  to_find[c])
			{
				while (str[i] ==  to_find[c])
				{
					if (to_find[c + 1] == '\0')
						return (str[i - c]);
					i++;
					c++;
				}
			}
			i++;
		}
	}
	return (str);
}
