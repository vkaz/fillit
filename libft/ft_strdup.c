/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaznodi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 14:23:30 by vkaznodi          #+#    #+#             */
/*   Updated: 2017/11/11 14:23:31 by vkaznodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(char *src)
{
	int		i;
	int		strlen;
	char	*strdup;
	int		a;

	a = 0;
	while (src[a] != '\0')
		a++;
	strlen = a;
	strdup = (char *)malloc(a + 1);
	if (!(char *)malloc(a + 1))
		return (NULL);
	i = 0;
	while (i <= strlen)
	{
		strdup[i] = src[i];
		i++;
	}
	return (strdup);
}
