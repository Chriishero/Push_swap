CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = 	main.c utils.c \
		check_args.c check_args2.c \
		stack.c swap_stack.c push_stack.c rotate_stack.c reverse_rotate_stack.c \
		benchmark.c \
		sorting_utils.c medium_sorting.c simple_sorting.c complex_sorting.c \
		push_swap.c
OBJS = $(SRCS:.c=.o)
NAME = push_swap
LIBFT = ./Libft/libft.a

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C ./Libft/

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L./Libft -lft

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@ -I Libft/

clean:
	$(MAKE) clean -C Libft/
	rm -f $(OBJS)

fclean: clean
	$(MAKE) fclean -C Libft/
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
