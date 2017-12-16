/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaznodi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 14:58:03 by vkaznodi          #+#    #+#             */
/*   Updated: 2017/12/01 14:58:05 by vkaznodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putchar(char c);

void		ft_putnbr(int n)
{
	int		i;

	if (n < 0)
	{
		ft_putchar('-');
		i = (unsigned int)(-n) % 10;
		n = (unsigned int)(-n) / 10;
		ft_putnbr(n);
		ft_putchar(i + '0');
	}
	else if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
	{
		ft_putchar(n + '0');
	}
}
