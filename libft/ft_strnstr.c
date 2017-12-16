/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaznodi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 13:25:29 by vkaznodi          #+#    #+#             */
/*   Updated: 2017/11/16 13:25:30 by vkaznodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strnstr(char	*str, const char *to_find, int len)
{
	int		a;
	int		b;
	int		c;

	a = 0;
	c = 0;
	while (str[a] != '\0' && a < len)
	{
		b = a;
		while (str[b] == to_find[c])
		{
			b++;
			c++;
		}
		if (to_find[c] == '\0')
			return (str);
		a++;
	}
	return (0);
}
