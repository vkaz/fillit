/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkachano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 17:41:09 by mkachano          #+#    #+#             */
/*   Updated: 2017/12/03 17:41:11 by mkachano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define FILE_OPEN_ERROR (-1)

# define MAX_BUFFER_SIZE 544
# define ERROR_INVALID_USAGE 0
# define ERROR_INVALID_DATA 1
# define TETRIMINO_SIZE 20

# include "libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct		s_tetrimino
{
	int				cord0;
	int				cord1;
	int				cord2;
	int				cord3;
	char			letter;
}					t_tetrimino;

void				error(int error_code);
size_t				get_tetriminos_count(t_tetrimino *array);
char				*create_map(size_t dimension);
int					is_tetriminos_valid(char *tetriminos);
int					push_tetriminos(size_t pos, size_t index,
	t_tetrimino *tetriminos, char *map);
t_tetrimino			create_tetrimino(int start, char *str, int index);
t_tetrimino			*create_tetriminos_array(char *tetriminos);

#endif
