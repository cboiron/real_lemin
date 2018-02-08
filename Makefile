# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cboiron <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/29 18:09:35 by cboiron           #+#    #+#              #
#    Updated: 2018/02/08 05:09:40 by cboiron          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ./lem-in

SRC = srcs/main.c srcs/parse_rooms.c srcs/stock_rooms.c srcs/ft_lstadd.c \
 srcs/get_tubes.c srcs/error.c srcs/tools.c srcs/treat_data.c srcs/process.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Werror -Wextra -g

all : $(NAME)

$(NAME) : $(OBJ)
	@make -C ./libft
	gcc -o $(NAME) $(OBJ) libft/libft.a
	@echo "lem-in ready"

%.o : %.c
	gcc -o $@ -c $< $(FLAG)

clean :
	@rm -rf $(OBJ)
	@make clean -C ./libft
	@echo "objects cleaned"


fclean : clean
	@rm -f $(NAME)
	@make fclean -C ./libft
	@echo "exe cleaned"

re : fclean all
