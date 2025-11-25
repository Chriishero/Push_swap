CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = 	main.c \
		check_args.c \
		utils.c \
		init_stack.c \
		swap_push_stack.c \
		rotate_stack.c \
		push_swap.c
OBJS = $(SRCS:.c=.o)
NAME = Push_swap
LIBFT = ./Libft/libft.a

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C ./Libft/

$(NAME): $(OBJS)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJS)

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