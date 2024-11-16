# ************************************************************************** #
#                                                                            #
#                                                        :::      ::::::::   #
#   Makefile                                           :+:      :+:    :+:   #
#                                                    +:+ +:+         +:+     #
#   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        #
#                                                +#+#+#+#+#+   +#+           #
#   Created: 2024/10/30 21:52:12 by jlacerda          #+#    #+#             #
#   Updated: 2024/11/15 14:38:20 by jlacerda         ###   ########.fr       #
#                                                                            #
# ************************************************************************** #

COMPILER = cc
CFLAGS = -Wall -Wextra -Werror

OBJDIR = objects
FILE_NAME = libftprintf.a

SOURCES = ft_utils.c ft_utils_extra.c ft_printf.c \
	ft_set_flags.c ft_set_padding.c ft_set_precision.c \
	ft_get_chr.c ft_get_str.c ft_get_hex.c \
	ft_get_nbr.c ft_get_unbr.c ft_get_ptr.c \

OBJECTS = $(addprefix $(OBJDIR)/, $(SOURCES:.c=.o))

all: $(FILE_NAME)

$(FILE_NAME): $(OBJECTS)

bonus: $(OBJECTS)

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	$(COMPILER) $(CFLAGS) -c $< -o $@
	ar rcs $(FILE_NAME) $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(FILE_NAME)

re: fclean all

.PHONY: all clean fclean re bonus
