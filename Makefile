# Diretórios
B_DIR = ./bonus
M_DIR = ./mandatory

# Arquivos de origem
B_SRCS = \
	$(B_DIR)/ft_utils_bonus.c \
	$(B_DIR)/ft_printf_bonus.c \
	$(B_DIR)/ft_set_flags_bonus.c \
	$(B_DIR)/ft_set_padding_bonus.c \
	$(B_DIR)/ft_set_precision_bonus.c \
	$(B_DIR)/ft_utils_mandatory_bonus.c \
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

B_OBJS_DIR = objects_bonus
M_OBJS_DIR = objects_mandatory

# Arquivos objeto
B_OBJS = $(B_SRCS:$(B_DIR)/%.c=$(B_OBJS_DIR)/%.o)
M_OBJS = $(M_SRCS:$(M_DIR)/%.c=$(M_OBJS_DIR)/%.o)

# Nome do arquivo de saída
NAME = libftprintf.a

# Compilador e flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Regras
all: $(NAME)

$(NAME): sclean $(M_OBJS)

bonus: sclean $(B_OBJS)

sclean:
	rm -rf $(NAME)

$(B_OBJS_DIR)/%.o: $(B_DIR)/%.c
	@mkdir -p $(B_OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
	ar rcs $(NAME) $@

$(M_OBJS_DIR)/%.o: $(M_DIR)/%.c
	@mkdir -p $(M_OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
	ar rcs $(NAME) $@

clean:
	rm -f $(M_OBJS) $(B_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus