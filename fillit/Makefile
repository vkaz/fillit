# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkachano <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/03 17:37:17 by mkachano          #+#    #+#              #
#    Updated: 2017/12/03 17:37:20 by mkachano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS = main.c \

CC = gcc

FLAGS = -Wall -Wextra -Werror

LIBFT = libft/

#all: libft_make $(NAME)
all: $(NAME)

$(NAME):
	@$(CC) $(FLAGS) $(SRCS) -o $(NAME)
	@echo "$(NAME) compiled"

libft_make:
	make -C $(LIBFT)
clean:
	@rm -f *.o
	@make -C $(LIBFT) clean
	@echo "Object files removed"

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT) fclean
	@echo "$(NAME) file removed"

re: fclean all

.PHONY: all clean fclean re libft_make