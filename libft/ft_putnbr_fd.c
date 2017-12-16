/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaznodi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 14:58:48 by vkaznodi          #+#    #+#             */
/*   Updated: 2017/12/01 14:58:49 by vkaznodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putchar(char c);

void ft_putnbr_fd(int n, int fd)
{
		int		i;

	if (n < 0)
	{
		ft_putchar('-');
		i = (unsigned int)(-n) % 10;
		n = (unsigned int)(-n) / 10;
		ft_putnbr_fd(n, fd);
		ft_putchar(i + '0');
	}
	else if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
	{
		ft_putchar(n + '0');
	}
}
