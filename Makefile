# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: epeters- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/09 17:56:05 by epeters-          #+#    #+#              #
#    Updated: 2022/07/17 19:05:22 by epeters-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra -I./include

DIR_SRCS	= src
DIR_LIBFT	= libft

SRCS = ft_printf.c char_conv.c str_conv.c int_conv.c \
	   hex_conv.c ptr_conv.c\

OBJS = $(addprefix $(DIR_SRCS)/,$(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@echo Compiling libft...
	make -C $(DIR_LIBFT)
	mv $(DIR_LIBFT)/libft.a .
	@echo Compiling $(NAME)...
	mv libft.a $(NAME)
	ar rcs $(NAME) $(OBJS)
	@echo $(NAME) ready!

clean:
	make clean -C $(DIR_LIBFT)
	rm -f $(OBJS)

fclean: clean
	make fclean -C $(DIR_LIBFT)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
