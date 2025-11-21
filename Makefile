CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = 	main.c \
		check_args.c \
		utils.c
OBJS = $(SRCS:.c=.o)
NAME = Push_swap
LIBFT = ./Libft/libft.a

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C ./Libft/

$(NAME)