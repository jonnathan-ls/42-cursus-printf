#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/26 14:54:44 by jlacerda          #+#    #+#              #
#    Updated: 2024/11/02 19:20:03 by jlacerda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COMPILER = cc
CFLAGS = -Wall -Wextra -Werror

SOURCES = ft_utils.c ft_printf.c \
	ft_add_chr.c ft_add_str.c ft_add_hex.c \
	ft_add_nbr.c ft_add_unbr.c ft_add_ptr.c
BONUS_SOURCES = ft_utils_bonus.c ft_printf_bonus.c \
	ft_add_padding.c ft_add_precision.c ft_utils_precision_bonus.c

OBJDIR = objects
OBJECTS = $(addprefix $(OBJDIR)/, $(SOURCES:.c=.o))
BONUS_OBJECTS = $(addprefix $(OBJDIR)/, $(BONUS_SOURCES:.c=.o))

NAME = libftprintf.a
BONUS_NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJECTS)

bonus: $(BONUS_OBJECTS) $(OBJECTS)

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	$(COMPILER) $(CFLAGS) -c $< -o $@
	ar rcs $(NAME) $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -f $(OBJECTS) $(BONUS_OBJECTS)
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re bonus