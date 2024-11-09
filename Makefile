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

COMPILER = cc
CFLAGS = -Wall -Wextra -Werror

SOURCES = ft_utils.c ft_printf.c \
	ft_node_add_chr.c ft_node_add_str.c ft_node_add_hex.c \
	ft_node_add_nbr.c ft_node_add_uns_nbr.c ft_node_add_ptr.c
BONUS_SOURCES = ft_utils_bonus.c ft_printf_bonus.c

OBJECTS = $(SOURCES:.c=.o)
BONUS_OBJECTS = $(BONUS_SOURCES:.c=.o)

NAME = libftprintf.a
BONUS_NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $@ $^

bonus: $(BONUS_OBJECTS) $(OBJECTS)
	ar rcs $(BONUS_NAME) $(BONUS_OBJECTS) $(OBJECTS)

%.o: %.c ft_printf.h
	$(COMPILER) $(CFLAGS) -c $< -o $@

%.o: %.c ft_printf_bonus.h
	$(COMPILER) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(BONUS_OBJECTS)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re bonus
