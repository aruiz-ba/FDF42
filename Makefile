# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aruiz-ba <aruiz-ba@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/28 12:02:51 by aruiz-ba          #+#    #+#              #
#    Updated: 2019/05/13 14:27:18 by aruiz-ba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = FDF

SRC	= $(addprefix src/,main.c ft_put_line.c ft_set_web.c ft_parse.c ft_read.c \
	image.c center.c inputparse.c stwebwhile.c keyboard.c)

OBJ = $(SRC:.c=.o)

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

MLX_LNK	= -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit -fsanitize=address -g

FT		= ./Libft/
FT_LIB	= $(addprefix $(FT),libft.a)
FT_INC	= -I ./Libft
FT_LNK	= -L ./Libft -l ft

SCRDIR 	= ./src/
INCDIR	= ./includes/
OBJDIR	= ./obj/

all: $(FT_LIB) $(NAME)

%.o: %.c
		$(CC) $(CFLAGS) $(FT_INC) -I $(INCDIR) -o $@ -c $<

$(FT_LIB):
		make -C $(FT)

$(NAME): $(OBJ)
		$(CC) $(OBJ) $(MLX_LNK) $(FT_LNK) -lm -o $(NAME)

clean:
		rm -rf $(OBJ)
		make -C $(FT) clean

fclean: clean
		rm -rf $(NAME)
		make -C $(FT) fclean

re: fclean all
