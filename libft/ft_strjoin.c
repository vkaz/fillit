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

int		ft_strlen(char *str);

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*st1;
	int			i;
	int			d;

	i = 0;
	d = (ft_strlen((char*)s1) + ft_strlen((char*)s2) + 1);
	st1 = (char *)malloc(sizeof(*st1) * (d));
	if (st1 == NULL)
		return (NULL);
	while (s1)
		st1[i++] = *s1++;
	while (s2)
		st1[i++] = *s2++;
	st1[i] = '\0';
	return (&*st1);
}

