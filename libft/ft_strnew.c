/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaznodi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 14:49:55 by vkaznodi          #+#    #+#             */
/*   Updated: 2017/12/01 14:49:57 by vkaznodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char * ft_strnew(size_t size)
{
	char	*s1;
	size_t	i;

	s1 = (char*)malloc(size);
	if (s1 == NULL)
		return (NULL);
	while (i < size)
	{
		s1[i] = '\0';
		i++;
	}
	return (s1);
}
