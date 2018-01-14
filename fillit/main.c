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

# define MAX_BUFFER_SIZE 544
# define ERROR_INVALID_USAGE 0
# define ERROR_INVALID_DATA 1
# define TETRIMINO_SIZE 19


/* ========= LIB FUNC */

void	ft_putstr(char	const *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
}

size_t		ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

/* ========== LIB FUNC END */
void error(int error_code)
{
	if (error_code == ERROR_INVALID_USAGE)
		ft_putstr("usage: ./fillit source_file");
	else if (error_code == ERROR_INVALID_DATA)
		ft_putstr("error");
	ft_putstr("\n");
}

int is_valid_file_size(int bytes_count)
{
	int figure_count;
	int total_size;

	if (bytes_count > MAX_BUFFER_SIZE || bytes_count < TETRIMINO_SIZE)
	 	return (0);
	figure_count = (bytes_count + 2) / (TETRIMINO_SIZE + 2);
	total_size = ((figure_count - 1) * 2) + figure_count * TETRIMINO_SIZE;
	if (total_size != bytes_count)
		return (0);
	return (1);
}

int optimize_coord(size_t *coord)
{
	size_t i;
	size_t c;

	i = 0;
	if (coord[0] >= 5) {
		c = coord[0] / 5;
		while (i < 4)
		{
			coord[i] = coord[i] - c * 5;
			i += 1;
		}
	}
	i = 0;
	c = 0;
	while (i < 4)
	{
		if (c == 0)
			c = coord[i] % 5;
		if (c  > coord[i] % 5)
			c = coord[i] % 5;
		i += 1;
	}
	i = 0;
	if (c > 0)
		while (i < 4)
		{
			coord[i] = coord[i] - c;
			i+=1;
		}
	return (0);
}

int is_tetrimino_pattern_match(size_t *coord)
{
	int i;
	int j;
	int conn;
	size_t *c;

	i = 0;
	conn = 0;
	c = coord;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (j != i && j < i && (c[i] == (c[j] + 1) || c[i] == (c[j] + 5))) {
				conn += 1;
			}
			if (j != i && j > i && (c[i] == (c[j] - 1) || c[i] == (c[j] - 5))) {
				conn += 1;
			}
			j += 1;
		}
		i += 1;
	}

	if (conn < 6)
			return (0);
	return (1);
}

int is_tetrimino(int start, char *str)
{
	size_t i;
	size_t dots;
	size_t sharps;
	size_t coord[4];

	i = 0;
	dots = 0;
	sharps = 0;
	while (i < TETRIMINO_SIZE)
	{
		if ((i > 0) && ((i + 1) % 5 == 0) && (str[start] != '\n'))
			return (0);
		if (str[start] == '.')
			dots += 1;
		if (str[start] == '#')
		{
			coord[sharps] = i;
			sharps += 1;
		}
		i += 1;
		start += 1;
	}

	// NOT NESSESERY
	// optimize_coord(coord);
	if (dots == 12 && sharps == 4 && is_tetrimino_pattern_match(coord))
		return (1);

	return (0);
}


int is_tetriminos_valid(char *tetriminos)
{
	size_t bytes_count;
	size_t figure_count;
	size_t i;
	size_t star_from;

	i = 0;
	bytes_count = ft_strlen(tetriminos);
	figure_count = (bytes_count + 2) / (TETRIMINO_SIZE + 2);

	while (i < figure_count)
	{
		star_from = i * (TETRIMINO_SIZE + 2);
		if (i != 0 && (tetriminos[star_from - 1] != '\n' || tetriminos[star_from - 2] != '\n'))
			return (0);                                                                                                        
		if (is_tetrimino(star_from, tetriminos) != 1)
			return (0);
		i += 1;
	}

	return (1);
}


char *read_tetriminos_file(char *source_file)
{
	int fd;	
	int bytes_count;
	char *content;

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

char make_square(int c)
{
    char    *arr;

    if (!(arr = (char)malloc(sizeof(c + 1))))
        return(0);
	return (arr);
}


int main(int args, char **argv)
{

	char *content;
 	
 	if (args == 2) {
		if ((content = read_tetriminos_file(argv[1])) != NULL) {
			//printf("%s\n", content);
			if (is_tetriminos_valid(content))
				make_square(content);// printf("%s\n", "VALID");
			else
				error(ERROR_INVALID_DATA);
				// printf("%s\n", "NOT VALID");
		}
	}
	else 
		error(ERROR_INVALID_USAGE);
	return (0);
}