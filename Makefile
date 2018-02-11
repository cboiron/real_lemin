# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cboiron <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/29 18:09:35 by cboiron           #+#    #+#              #
#    Updated: 2018/02/11 03:21:26 by cboiron          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ./lem-in

SRC = srcs/main.c srcs/parse_rooms.c srcs/stock_rooms.c srcs/ft_lstadd.c \
 srcs/get_tubes.c srcs/tools.c srcs/treat_data.c srcs/process.c \
 srcs/print_ants.c srcs/norme.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Werror -Wextra

all : $(NAME)

$(NAME) : $(OBJ)
	@make -C ./libft
	gcc -o $(NAME) $(OBJ) libft/libft.a
	@echo "lem-in ready"

%.o : %.c
	gcc -o $@ -c $< $(FLAGS)

clean :
	@rm -rf $(OBJ)
	@make clean -C ./libft
	@echo "objects cleaned"


fclean : clean
	@rm -f $(NAME)
	@make fclean -C ./libft
	@echo "exe cleaned"

re : fclean all
