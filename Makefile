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
COMPILE_NAME = libftprintf.a

MANDATORY_SOURCES = ft_utils.c ft_printf.c \
	ft_get_chr.c ft_get_str.c ft_get_hex.c \
	ft_get_nbr.c ft_get_unbr.c ft_get_ptr.c

BONUS_SOURCES = ft_utils_bonus.c ft_printf_bonus.c \
	ft_set_flags.c ft_set_padding.c ft_set_precision.c

MANDATORY_OBJECTS = $(addprefix $(OBJDIR)/, $(MANDATORY_SOURCES:.c=.o))
BONUS_OBJECTS = $(addprefix $(OBJDIR)/, $(BONUS_SOURCES:.c=.o))

all: $(COMPILE_NAME)

$(COMPILE_NAME): $(MANDATORY_OBJECTS)

bonus: $(BONUS_OBJECTS) $(MANDATORY_OBJECTS)

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	$(COMPILER) $(CFLAGS) -c $< -o $@
	ar rcs $(COMPILE_NAME) $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -f $(BONUS_OBJECTS) $(MANDATORY_OBJECTS) 
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(COMPILE_NAME)

re: fclean all

.PHONY: all clean fclean re bonus
