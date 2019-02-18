/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaznodi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 15:09:04 by vkaznodi          #+#    #+#             */
/*   Updated: 2018/01/22 15:09:05 by vkaznodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char				*create_map(size_t dimension)
{
	size_t		i;
	size_t		total_size;
	size_t		size;
	char		*map;

	size = dimension;
	total_size = size * size + size;
	if (!(map = (char *)malloc(sizeof(char) * (total_size + 1))))
		return (0);
	i = 0;
	while (i < total_size)
	{
		map[i] = '.';
		if ((i + 1) % (size + 1) == 0)
			map[i] = '\n';
		i += 1;
	}
	map[i] = '\0';
	return (map);
}

static int			optimize_coord(size_t *coord)
{
	size_t	i;
	size_t	c;

	i = -1;
	if (coord[0] >= 5)
	{
		c = coord[0] / 5;
		while (++i < 4)
			coord[i] = coord[i] - c * 5;
	}
	i = -1;
	c = 0;
	while (++i < 4)
	{
		if (c == 0)
			c = coord[i] % 5;
		if (c > coord[i] % 5)
			c = coord[i] % 5;
	}
	i = -1;
	if (c > 0)
		while (++i < 4)
			coord[i] = coord[i] - c;
	return (0);
}

t_tetrimino			create_tetrimino(int start, char *str, int index)
{
	size_t			i;
	size_t			sharps;
	size_t			coord[4];
	t_tetrimino		tetrimino;

	i = 0;
	sharps = 0;
	while (i < TETRIMINO_SIZE - 1)
	{
		if (str[start] == '#')
		{
			coord[sharps] = i;
			sharps += 1;
		}
		i += 1;
		start += 1;
	}
	optimize_coord(coord);
	tetrimino.cord0 = coord[0];
	tetrimino.cord1 = coord[1];
	tetrimino.cord2 = coord[2];
	tetrimino.cord3 = coord[3];
	tetrimino.letter = index + 65;
	return (tetrimino);
}
