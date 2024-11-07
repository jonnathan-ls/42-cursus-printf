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
LIBFT_OBJECTS = $(patsubst $(LIBFT_DIR)/%, %, $(wildcard $(LIBFT_DIR)/*.o))

SOURCES = ft_utils.c ft_print_pad.c \
	ft_printf.c ft_get_chr.c ft_get_str.c \
	ft_get_hex.c ft_get_nbr.c ft_get_unbr.c ft_get_ptr.c
OBJECTS = $(SOURCES:.c=.o)

all: $(LIBFT) $(NAME)

$(NAME): $(OBJECTS) $(LIBFT_OBJECTS)
	ar rcs $@ $^

$(LIBFT):
	cd $(LIBFT_DIR) && make
	cp $(LIBFT) .
	ar x $(LIBFT)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)	$(LIBFT_OBJECTS)
	cd $(LIBFT_DIR) && make clean

fclean: clean
	rm -f $(NAME) libft.a
	cd $(LIBFT_DIR) && make fclean

re: fclean all

.PHONY: all clean fclean re $(LIBFT)

# make && cc test_flag.c -L . -lftprintf -L libft -lft && ./a.out