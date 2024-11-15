# ************************************************************************** #
#                                                                            #
#                                                        :::      ::::::::   #
#   Makefile                                           :+:      :+:    :+:   #
#                                                    +:+ +:+         +:+     #
#   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        #
#                                                +#+#+#+#+#+   +#+           #
#   Created: 2024/10/30 21:52:12 by jlacerda          #+#    #+#             #
#   Updated: 2024/11/14 01:43:08 by jlacerda         ###   ########.fr       #
#                                                                            #
# ************************************************************************** #

NAME = libftprintf.a

COMPILER = cc
CFLAGS = -Wall -Wextra -Werror

B_DIR = ./bonus
M_DIR = ./mandatory
OBJS_DIR = ./objects
B_OBJS_DIR = ${OBJS_DIR}/bonus
M_OBJS_DIR = ${OBJS_DIR}/mandatory

B_SRCS = \
	$(B_DIR)/ft_utils_bonus.c \
	$(B_DIR)/ft_printf_bonus.c \
	$(B_DIR)/ft_set_flags_bonus.c \
	$(B_DIR)/ft_set_padding_bonus.c \
	$(B_DIR)/ft_set_precision_bonus.c \
	$(B_DIR)/ft_utils_m_bonus.c \
	$(B_DIR)/ft_get_chr_bonus.c \
	$(B_DIR)/ft_get_str_bonus.c \
	$(B_DIR)/ft_get_hex_bonus.c \
	$(B_DIR)/ft_get_nbr_bonus.c \
	$(B_DIR)/ft_get_ptr_bonus.c \
	$(B_DIR)/ft_get_unbr_bonus.c \

M_SRCS = \
	$(M_DIR)/ft_utils.c \
	$(M_DIR)/ft_printf.c \
	$(M_DIR)/ft_get_chr.c \
	$(M_DIR)/ft_get_str.c \
	$(M_DIR)/ft_get_hex.c \
	$(M_DIR)/ft_get_nbr.c \
	$(M_DIR)/ft_get_ptr.c \
	$(M_DIR)/ft_get_unbr.c

B_OBJS = $(B_SRCS:$(B_DIR)/%.c=$(B_OBJS_DIR)/%.o)
M_OBJS = $(M_SRCS:$(M_DIR)/%.c=$(M_OBJS_DIR)/%.o)


all: $(NAME)

$(NAME): $(M_OBJS)

bonus: $(B_OBJS)

$(M_OBJS_DIR)/%.o: $(M_DIR)/%.c
	@mkdir -p $(M_OBJS_DIR)
	$(COMPILER) $(CFLAGS) -c $< -o $@
	ar rcs $(NAME) $@

$(B_OBJS_DIR)/%.o: $(B_DIR)/%.c
	@if [ -d $(M_OBJS_DIR) ]; then \
		ar -d $(NAME) $(M_DIR)/ft_printf.o; \
	fi
	@mkdir -p $(B_OBJS_DIR)
	$(COMPILER) $(CFLAGS) -c $< -o $@
	ar rcs $(NAME) $@

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus