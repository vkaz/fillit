/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaznodi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 13:58:37 by vkaznodi          #+#    #+#             */
/*   Updated: 2017/11/10 13:58:39 by vkaznodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memset(void *dst, int c, size_t n)
{
	unsigned long		i;

	i = 0;
	while (i < n)
	{
		((char *)dst)[i] = (unsigned long)c;
		i++;
	}
	return (dst);
}
