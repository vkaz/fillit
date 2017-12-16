/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaznodi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 12:31:46 by vkaznodi          #+#    #+#             */
/*   Updated: 2017/11/30 12:31:48 by vkaznodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*ds;
	unsigned char	*sr;
	size_t	i;

	i = 0;
	ds = (unsigned char *)dst;
	sr = (unsigned char *)src;
	if (sr < ds)
	{
		while (i < n)
		{
			ds[i] = sr[i];
			i++;
		}
	}
	else
		ft_memcpy(ds, sr, n);
	return ((void*)ds);
}
