/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaznodi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 15:20:38 by vkaznodi          #+#    #+#             */
/*   Updated: 2018/01/22 15:20:39 by vkaznodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		remove_tetrimimo(char *area, t_tetrimino tetrimino,
	size_t position, size_t area_size)
{
	size_t coord;
	size_t coord1;
	size_t coord2;
	size_t coord3;

	coord = position;
	coord1 = (area_size - 4) * (tetrimino.cord1 / 4) + position +
	tetrimino.cord1 - tetrimino.cord0;
	coord2 = (area_size - 4) * (tetrimino.cord2 / 4) + position +
	tetrimino.cord2 - tetrimino.cord0;
	coord3 = (area_size - 4) * (tetrimino.cord3 / 4) + position +
	tetrimino.cord3 - tetrimino.cord0;
	area[coord] = '.';
	area[coord1] = '.';
	area[coord2] = '.';
	area[coord3] = '.';
	return (0);
}

static int		put_tetrimimo(char *area, t_tetrimino tetrimino,
	size_t position, size_t area_size)
{
	size_t coord;
	size_t coord1;
	size_t coord2;
	size_t coord3;

	coord = position;
	coord1 = (area_size - 4) * (tetrimino.cord1 / 4) + position +
	tetrimino.cord1 - tetrimino.cord0;
	coord2 = (area_size - 4) * (tetrimino.cord2 / 4) + position +
	tetrimino.cord2 - tetrimino.cord0;
	coord3 = (area_size - 4) * (tetrimino.cord3 / 4) + position +
	tetrimino.cord3 - tetrimino.cord0;
	if (area[coord] == '.' && area[coord1] == '.' && area[coord2] ==
		'.' && area[coord3] == '.')
	{
		area[coord] = tetrimino.letter;
		area[coord1] = tetrimino.letter;
		area[coord2] = tetrimino.letter;
		area[coord3] = tetrimino.letter;
		return (1);
	}
	return (0);
}

size_t			get_tetriminos_count(t_tetrimino *array)
{
	size_t i;

	i = 0;
	while (array[i].letter != '\0')
		i += 1;
	return (i);
}

static size_t	get_map_dimention(char *map)
{
	size_t i;

	i = 0;
	while (map[i] != '\n')
		i += 1;
	return (i);
}

int				push_tetriminos(size_t pos, size_t index, t_tetrimino
	*tetriminos, char *map)
{
	size_t n;
	size_t total_size;
	size_t tetri_count;
	size_t map_dim;

	tetri_count = get_tetriminos_count(tetriminos);
	total_size = ft_strlen(map);
	map_dim = get_map_dimention(map);
	n = index;
	while (pos < total_size)
	{
		if (put_tetrimimo(map, tetriminos[n], pos, map_dim))
		{
			if (n == tetri_count - 1)
				return (1);
			if (push_tetriminos(0, n + 1, tetriminos, map) == 0)
				remove_tetrimimo(map, tetriminos[n], pos, map_dim);
			else
				return (1);
		}
		pos += 1;
	}
	return (0);
}
