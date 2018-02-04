# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cboiron <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/29 18:09:35 by cboiron           #+#    #+#              #
#    Updated: 2018/02/04 15:47:57 by cboiron          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ./lem-in

SRC = srcs/main.c srcs/parse_rooms.c srcs/stock_rooms.c srcs/ft_lstadd.c \
srcs/get_nbr_ants.c srcs/get_tubes.c srcs/parse_tubes.c srcs/print_links.c \
srcs/error.c srcs/path.c srcs/start.c srcs/tools.c srcs/treat_data.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Werror -Wextra -g3

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
