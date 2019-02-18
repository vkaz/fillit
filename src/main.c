/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkachano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 17:38:36 by mkachano          #+#    #+#             */
/*   Updated: 2017/12/03 17:38:43 by mkachano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetrimino			*create_tetriminos_array(char *tetriminos)
{
	size_t			bytes_count;
	size_t			figure_count;
	size_t			i;
	size_t			star_from;
	t_tetrimino		*tetriminos_array;

	i = 0;
	bytes_count = ft_strlen(tetriminos);
	figure_count = (bytes_count + 1) / (TETRIMINO_SIZE + 1);
	if (!(tetriminos_array = (t_tetrimino *)malloc(sizeof(t_tetrimino)
	* (figure_count + 1))))
		return (0);
	while (i < figure_count)
	{
		star_from = i * (TETRIMINO_SIZE + 1);
		tetriminos_array[i] = create_tetrimino(star_from, tetriminos, i);
		i += 1;
	}
	tetriminos_array[i].letter = '\0';
	return (tetriminos_array);
}

static char			*play(t_tetrimino *tetriminos_array)
{
	char	*map;
	size_t	map_dimension;
	size_t	tetriminos_count;
	int		is_map_filled;

	is_map_filled = 0;
	tetriminos_count = get_tetriminos_count(tetriminos_array);
	map_dimension = ft_sqrt(tetriminos_count * 4);
	while (is_map_filled == 0)
	{
		map = create_map(map_dimension);
		is_map_filled = push_tetriminos(0, 0, tetriminos_array, map);
		free(map);
		map_dimension += 1;
	}
	return (map);
}

static int			is_valid_file_size(int bytes_count)
{
	int		figure_count;
	int		total_size;

	if (bytes_count > MAX_BUFFER_SIZE || bytes_count < TETRIMINO_SIZE)
		return (0);
	figure_count = (bytes_count + 1) / (TETRIMINO_SIZE + 1);
	total_size = (figure_count - 1) + figure_count * TETRIMINO_SIZE;
	if (total_size != bytes_count)
		return (0);
	return (1);
}

static char			*read_tetriminos_file(char *source_file)
{
	int		fd;
	int		bytes_count;
	char	*content;

	content = (char *)malloc(sizeof(char) * MAX_BUFFER_SIZE + 1);
	if (content == NULL)
		return (NULL);
	if ((fd = open(source_file, O_RDONLY)) != FILE_OPEN_ERROR)
	{
		bytes_count = read(fd, content, MAX_BUFFER_SIZE + 1);
		if (is_valid_file_size(bytes_count))
			return (content);
		else
			error(ERROR_INVALID_DATA);
	}
	else
		error(ERROR_INVALID_USAGE);
	free(content);
	content = NULL;
	return (NULL);
}

int					main(int args, char **argv)
{
	char			*content;
	char			*result;
	t_tetrimino		*tetriminos_list;

	if (args == 2)
	{
		if ((content = read_tetriminos_file(argv[1])) != NULL)
		{
			if (is_tetriminos_valid(content))
			{
				tetriminos_list = create_tetriminos_array(content);
				result = play(tetriminos_list);
				ft_putstr(result);
			}
			else
				error(ERROR_INVALID_DATA);
		}
	}
	else
		error(ERROR_INVALID_USAGE);
	return (0);
}
