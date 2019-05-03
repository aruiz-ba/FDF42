# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aruiz-ba <aruiz-ba@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/28 12:02:51 by aruiz-ba          #+#    #+#              #
#    Updated: 2019/05/03 15:51:29 by aruiz-ba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = FDF

SRC		= main.c\
		ft_put_line.c\
		ft_set_web.c\
		ft_parse.c\
		ft_read.c\
		image.c\
		center.c\
		inputparse.c\
		stwebwhile.c\

OBJ = $(addprefix $(OBJDIR),$(SRC:.c=.o))

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

MLX		= ./miniLibX
MLX_LIB	= $(addprefix $(MLX),mlx.a)
MLX_INC	= -I ./miniLibX
MLX_LNK	= -L ./miniLibX -l mlx -framework OpenGL -framework AppKit

FT		= ./libft/
FT_LIB	= $(addprefix $(FT),libft.a)
FT_INC	= -I ./libft
FT_LNK	= -L ./libft -l ft

SCRDIR 	= ./src/
INCDIR	= ./includes/
OBJDIR	= ./obj/

all: obj $(FT_LIB) $(MLX_LIB) $(NAME)

obj:
		mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c
		$(CC) $(CFLAGS) $(MLX_INC) $(FT_INC) -I $(INCDIR) -O $@ -c $<

$(FT_LIB):
		make -C $(FT)

$(MLX_LIB):
		make -C $(MLX)

$(NAME): $(OBJ)
		$(CC) $(OBJ) $(MLX_LNK) $(FT_LNK) -lm -o $(NAME)

clean:
		rm -rf $(OBJDIR)
		make -C $(FT) clean
		make -C $(MLX) clean

fclean: clean
		rm -rf $(NAME)
		make -C $(FT) fclean

re: fclean all
