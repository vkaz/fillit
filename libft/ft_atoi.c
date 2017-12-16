/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaznodi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 13:06:56 by vkaznodi          #+#    #+#             */
/*   Updated: 2017/11/23 13:06:58 by vkaznodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(char *str)
{
	unsigned long res;
	int s;
	int i;
	int rez;

	res = 0;
	s = 1;
	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r' || str[i] == ' '
			|| str[i] == '+')
		i++;
	if (str[i] == '-')
	{
		s = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if ((res > 922337203685477580 || (res == 922337203685477580 &&(str[i]
		 - '0') > 7)) && s == 1)
			return (-1);
		else if ((res > 922337203685477580 || (res == 922337203685477580 
		 &&(str[i] - '0') > 8)) && s == -1)
			return (0);
		res = res * 10 + str[i] - '0';
		i++;
	}
	rez = res * s;
	return (rez);
}
