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

NAME	= fillit

SRC		= main.c  \
		  check.c \
		  play.c  \
		  tetrimino.c   

OBJ		= $(SRC:.c=.o)

OBJ_DIR  = obj
SRC_PATH = src
LIB_PATH = src/libft
LIB_LINK = -L $(LIB_PATH) -lft
LIB_DEL = src/libft/*.o

INC_DIR			=	src/
INCS			=	-I $(LIB_PATH)/$(INC_DIR) -I $(INC_DIR)

SRC_POS = $(addprefix $(SRC_PATH),$(SRC))
OBJS = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o)) 

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

LIBFT =	src/libft/libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIB_LINK)

$(LIBFT):
	make -C ./src/libft/

$(OBJ_DIR)/%.o: $(SRC_PATH)/%.c $(SRC_PATH)/*.h
	mkdir -p obj
	$(CC) $(CFLAGS) $(INCS) -c -o $@ $<

clean:
	@rm -f $(OBJS)
	@rm -f $(LIB_DEL)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIB_PATH) fclean

re: fclean all

.PHONY : all, re, clean, flcean
