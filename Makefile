#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/26 14:54:44 by jlacerda          #+#    #+#              #
#    Updated: 2024/11/02 19:20:03 by jlacerda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COMPILER = cc
CFLAGS = -Wall -Wextra -Werror

OBJDIR = objects
NAME = libftprintf.a
BONUS_NAME = libftprintf.a

SOURCES = ft_utils.c ft_printf.c \
	ft_get_chr.c ft_get_str.c ft_get_hex.c \
	ft_get_nbr.c ft_get_unbr.c ft_get_ptr.c

BONUS_SOURCES = ft_utils_bonus.c ft_printf_bonus.c \
	ft_set_flags.c ft_set_padding.c ft_set_precision.c
	

OBJECTS = $(addprefix $(OBJDIR)/, $(SOURCES:.c=.o))
BONUS_OBJECTS = $(addprefix $(OBJDIR)/, $(BONUS_SOURCES:.c=.o))

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
