# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aruiz-ba <aruiz-ba@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/28 12:02:51 by aruiz-ba          #+#    #+#              #
#    Updated: 2019/04/29 18:28:02 by aruiz-ba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = FDF

# directories
SRC_DIR	:= ./srcs
INC_DIR	:= ./includes
OBJ_DIR	:= ./obj
LIB_DIR	:= ./lib

SRC = ./srcs/main.c\
		./srcs/ft_put_line.c\
		./srcs/ft_set_web.c\
		./srcs/ft_parse.c\
		./srcs/ft_read.c\
		./srcs/image.c\
		./srcs/center.c\
		./srcs/inputparse.c\
		./srcs/stwebwhile.c\
		./Libft/libft.a

$(NAME): $(SRC)
	@make -C libft/
	gcc -g -fsanitize=address -I /usr/local/include $(SRC) -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit -I includes 
	@echo "_________________"
	@echo "                 "
	@echo "    SUCCESS!     "
	@echo "     FDF      "
	@echo "    was created  "
	@echo "_________________"


all: $(NAME)

clean:
	@make -C libft/ clean

fclean:
	@rm -f $(NAME)
	@make fclean -C libft/

re: fclean all $(NAME)
