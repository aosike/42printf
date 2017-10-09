# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agundry <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/28 09:03:11 by agundry           #+#    #+#              #
#    Updated: 2017/10/08 15:17:25 by agundry          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g

IFLAGS = -I.

SRC = ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c \
	  ft_lstmap.c \
	  \
	  ft_isspace.c ft_cntwrd.c ft_cntdigits.c ft_putstrerror.c \
	  ft_cntwrddelimc.c \
	  \
	  ft_tolower.c ft_toupper.c ft_isprint.c ft_isascii.c ft_isalnum.c \
	  ft_isdigit.c ft_isalpha.c ft_atoi.c ft_strncmp.c ft_strcmp.c \
	  ft_strnstr.c ft_strrchr.c ft_strchr.c ft_strlcat.c ft_strncat.c \
	  ft_strcat.c ft_strncpy.c ft_strcpy.c ft_strdup.c ft_strlen.c \
	  ft_memcmp.c ft_memchr.c ft_bzero.c ft_memset.c ft_strstr.c\
	  ft_memccpy.c ft_memcpy.c ft_memmove.c ft_strndup.c \
	  \
	  ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c \
	  ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c \
	  ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c \
	  ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c \
	  ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strnequ.c \
	  ft_buf.c ft_realloc.c \
	  \
	  ft_printf.c ft_printf_core.c parsing.c ft_xtoa_base.c utf8.c \
	  int_formatting.c str_formatting.c conv_c.c conv_d.c conv_prc.c \
	  conv_s.c conv_uo.c conv_wc.c conv_wcs.c conv_x.c utils.c

OBJ = $(SRC:%.c=%.o)

ARCH = ar -rcs $(NAME) $(OBJ)


all: $(NAME)

$(NAME): $(OBJ)
	$(ARCH)

$(OBJ): %.o: %.c
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean:	
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
