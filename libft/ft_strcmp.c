/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaznodi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 14:07:17 by vkaznodi          #+#    #+#             */
/*   Updated: 2017/11/16 14:07:18 by vkaznodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;
	unsigned char	*src1;
	unsigned char	*src2;

	i = 0;
	src1 = s1;
	src2 = s2;
	while (src1[i] != '\0' || src2[i] != '\0')
	{
		if (src1[i] != src2[i])
			return (src1[i] - src2[i]);
		i++;
	}
	return (0);
}
