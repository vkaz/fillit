/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaznodi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 15:05:18 by vkaznodi          #+#    #+#             */
/*   Updated: 2018/01/22 15:05:19 by vkaznodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void				error(int error_code)
{
	if (error_code == ERROR_INVALID_USAGE)
		ft_putstr("usage: ./fillit source_file");
	else if (error_code == ERROR_INVALID_DATA)
		ft_putstr("error");
	ft_putstr("\n");
}

static int			is_tetrimino_pattern_match(size_t *coord)
{
	int		i;
	int		j;
	int		conn;
	size_t	*c;

	i = 0;
	conn = 0;
	c = coord;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (j != i && j < i && (c[i] == (c[j] + 1) || c[i] == (c[j] + 5)))
				conn += 1;
			if (j != i && j > i && (c[i] == (c[j] - 1) || c[i] == (c[j] - 5)))
				conn += 1;
			j += 1;
		}
		i += 1;
	}
	if (conn < 6)
		return (0);
	return (1);
}

static int			is_tetrimino(int start, char *str)
{
	size_t	i;
	size_t	dots;
	size_t	sharps;
	size_t	coord[4];

	i = 0;
	dots = 0;
	sharps = 0;
	while (i < TETRIMINO_SIZE - 1)
	{
		if ((i > 0) && ((i + 1) % 5 == 0) && (str[start] != '\n'))
			return (0);
		if (str[start] == '.')
			dots += 1;
		if (str[start] == '#' && sharps < 4)
		{
			coord[sharps] = i;
			sharps += 1;
		}
		i += 1;
		start += 1;
	}
	if (dots == 12 && sharps == 4 && is_tetrimino_pattern_match(coord))
		return (1);
	return (0);
}

int					is_tetriminos_valid(char *tetriminos)
{
	size_t bytes_count;
	size_t figure_count;
	size_t i;
	size_t star_from;

	i = 0;
	bytes_count = ft_strlen(tetriminos);
	figure_count = (bytes_count + 1) / (TETRIMINO_SIZE + 1);
	while (i < figure_count)
	{
		star_from = i * (TETRIMINO_SIZE + 1);
		if (i != 0 && (tetriminos[star_from - 1] != '\n' ||
			tetriminos[star_from - 2] != '\n'))
			return (0);
		if (is_tetrimino(star_from, tetriminos) == 0)
			return (0);
		i += 1;
	}
	return (1);
}
