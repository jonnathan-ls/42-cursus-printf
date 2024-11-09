CC = cc
NAME = test
CFLAGS = -Wall -Wextra -Werror

all:
	cd .. && make
	$(CC) $(CFLAGS) *.c -L .. -lftprintf -L ../libft -lft  -o $(NAME)
	./$(NAME)

fclean:
	rm -f $(NAME)
	cd .. && make fclean

.PHONY: all fclean
