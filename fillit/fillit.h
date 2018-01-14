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

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

/*typedef struct      s_arr
{
    int             cord0;
    int             cord1;
    int             cord2;
    int             cord3;
    char            letter;
}                   t_arr;*/

void		        ft_putstr(char const *s);

#endif