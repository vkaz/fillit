/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaznodi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 14:58:28 by vkaznodi          #+#    #+#             */
/*   Updated: 2017/12/01 14:58:29 by vkaznodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putchar(char c);

void ft_putstr_fd(char const *str, int fd)
{
	int s;

	s = 0;
	while (str[s] != '\0')
	{
		ft_putchar(str[s]);
		s++;
	}
}
