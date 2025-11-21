CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
      ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
      ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
      ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
      ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
      ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
      ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
OBJ = $(SRC:.c=.o)
SRC_PRINTF =	ft_printf/ft_printf.c \
				ft_printf/ft_printargs.c \
				ft_printf/ft_printf_utils.c \
				ft_printf/ft_dectohex.c \
				ft_printf/ft_nbrlen.c \
				ft_printf/ft_print_c.c \
				ft_printf/ft_print_s.c \
				ft_printf/ft_print_p.c \
				ft_printf/ft_print_int.c \
				ft_printf/ft_print_u.c \
				ft_printf/ft_print_hex.c
OBJ_PRINTF = $(SRC_PRINTF:.c=.o)
SRC_BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstadd_back.c ft_lstdelone.c \
			ft_lstclear.c ft_lstsize.c ft_lstlast.c ft_lstiter.c ft_lstmap.c
OBJ_BONUS = $(SRC_BONUS:.c=.o)
NAME = libft.a

all: $(NAME)

$(NAME) : $(OBJ) $(OBJ_PRINTF) $(OBJ_BONUS)
	ar rcs $(NAME) $(OBJ) $(OBJ_PRINTF) $(OBJ_BONUS)

mandatory: $(OBJ)
	ar rcs $(NAME) $(OBJ)

printf: $(OBJ_PRINTF)
	ar rcs $(NAME) $(OBJ_PRINTF)

bonus: $(OBJ_BONUS)
	ar rcs $(NAME) $(OBJ_BONUS)

%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(OBJ_PRINTF) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
