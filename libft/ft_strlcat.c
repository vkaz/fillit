/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaznodi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 14:27:38 by vkaznodi          #+#    #+#             */
/*   Updated: 2017/12/14 14:27:39 by vkaznodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		i;
	size_t		c;
	size_t		r;

	i = 0;
	c = 0;
	r = ft_strlen((char*)src);
	while (dst[i] != '\0')
		i++;
	if (size > i + 1)
	{
		while (i < size - 1)
			dst[i++] = src[c++];
		dst[i] = '\0';
	}
	else if (size < i + 1)
		return (r + size);
	return (r);
}
