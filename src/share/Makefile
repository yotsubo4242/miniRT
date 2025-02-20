NAME = libshare.a
SRCS = ./vector/vec_dot.c \
		./vector/vec_eq.c \
		./vector/vec_is_normalized.c \
		./vector/vec_mag.c \
		./vector/vec_minus.c \
		./vector/vec_mult.c \
		./vector/vec_normalize.c \
		./vector/vec_rev.c
OBJS = $(SRCS:.c=.o)
INCLUDES = -I../../includes -I../../libmlx -I../../libft
CC = cc -g
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) rc $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
