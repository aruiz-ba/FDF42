# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aruiz-ba <aruiz-ba@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/01 16:04:50 by aruiz-ba          #+#    #+#              #
#    Updated: 2019/04/24 16:56:54 by aruiz-ba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_atoi.c\
		ft_strrchr.c\
		ft_isalpha.c\
		ft_isdigit.c\
		ft_strcat.c\
		ft_strchr.c\
		ft_strcmp.c\
		ft_strcpy.c\
		ft_strdup.c\
		ft_strlen.c\
		ft_strlcat.c\
		ft_strncat.c\
		ft_strncmp.c\
		ft_strncpy.c\
		ft_strnstr.c\
		ft_strstr.c\
		ft_isalnum.c\
		ft_isascii.c\
		ft_isprint.c\
		ft_memccpy.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_memcpy.c\
		ft_memmove.c\
		ft_memset.c\
		ft_tolower.c\
		ft_toupper.c\
		ft_bzero.c\
		ft_memdel.c\
		ft_memalloc.c\
		ft_putchar.c\
		ft_putstr.c\
		ft_strdel.c\
		ft_strequ.c\
		ft_striter.c\
		ft_striteri.c\
		ft_strnew.c\
		ft_strclr.c\
		ft_strmap.c\
		ft_strmapi.c\
		ft_strnequ.c\
		ft_strsub.c\
		ft_strjoin.c\
		ft_strtrim.c\
		ft_strsplit.c\
		ft_putendl.c\
		ft_putnbr.c\
		ft_putchar_fd.c\
		ft_putstr_fd.c\
		ft_putnbr_fd.c\
		ft_putendl_fd.c\
		ft_intlen.c\
		ft_itoa.c\
		ft_lstnew.c\
		ft_lstdel.c\
		ft_lstdelone.c\
		ft_lstadd.c\
		ft_lstiter.c\
		ft_lstmap.c\
		ft_iswhitespace.c\
		get_next_line.c\
		ft_strtrimstr.c

OBJ = $(SRC:.c=.o)

SRCDIR = srcs

OBJDIR = objs

SRCS = $(addprefix $(SRCDIR)/, $(SRC))

OBJS = $(addprefix $(OBJDIR)/, $(OBJ))

HEADER = -I includes

CC = gcc

CFLAGS = -c -Wall -Wextra -Werror

NAME = libft.a

all: $(NAME)

$(OBJS): $(SRCS)
	/bin/mkdir -p $(OBJDIR) ;
	$(CC) $(CFLAGS) $(SRCS) $(HEADER) ;
	/bin/mv $(OBJ) $(OBJDIR)/

$(NAME): $(OBJS)
	ar rcs $@ $^
	ranlib $@

clean:
	/bin/rm -rf $(OBJDIR)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re