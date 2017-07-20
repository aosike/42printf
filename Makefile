# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agundry <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/28 09:03:11 by agundry           #+#    #+#              #
#    Updated: 2017/07/20 11:34:07 by agundry          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libftprintf.a

CC =	gcc

CFLAGS =	-Wall -Werror -Wextra

IFLAGS =	-Iincludes/

SRC =	ft_printf.c ft_printf_core.c \
		conv_c.c conv_d.c conv_prc.c conv_s.c \
		conv_uo.c conv_wc.c conv_wcs.c conv_x.c \
		parsing.c ft_xtoa_base.c int_formatting.c str_formatting.c utf8.c

SPATH = src

OBJ =	$(patsubst %.c,%.o,$(SRC))

LPATH = libft

LIBFT = $(LPATH)/libft.a

$(LIBFT):
	$(MAKE) -C $(LPATH) all

$(NAME) : $(OBJ) $(LIBFT)
	libtool -v -static -o $@ $^

all : $(NAME)

clean :	
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
