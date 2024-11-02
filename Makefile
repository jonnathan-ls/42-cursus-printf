# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/26 14:54:44 by jlacerda          #+#    #+#              #
#    Updated: 2024/11/02 19:20:03 by jlacerda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SOURCES = ft_utils.c print_chr_padding.c \
	ft_printf.c ft_strlen.c ft_printchar.c ft_printstr.c \
	ft_printhex.c ft_printnbr.c ft_printunbr.c ft_printptr.c
OBJECTS = $(SOURCES:.c=.o)

all: $(LIBFT) $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $@ $^

$(LIBFT):
	cd libft && make

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)
	cd $(LIBFT_DIR) && make clean

fclean: clean
	rm -f $(NAME)
	cd $(LIBFT_DIR) && make fclean

re: fclean all

.PHONY: all clean fclean re $(LIBFT)

# make && cc test_flag.c -L . -lftprintf -L libft -lft && ./a.out