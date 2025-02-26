NAME = libshare.a
SRCS = ./vector/vec_dot.c \
		./vector/vec_eq.c \
		./vector/vec_is_normalized.c \
		./vector/vec_mag.c \
		./vector/vec_minus.c \
		./vector/vec_mult.c \
		./vector/vec_normalize.c \
		./vector/vec_rev.c \
		./vector/vec_plus.c \
		./vector/vec_cross.c \
		./vector/vec_div.c \
		./vector/vec_dup.c \
		./list/creat_list.c \
		./list/creat_node.c \
		./list/push_back_list.c

OBJS = $(SRCS:.c=.o)
INCLUDES = -I./include -I../../libmlx -I../../libft/includes -I../../include -I../scene/get_next_line -I../scene
CC = cc -g
CFLAGS = -Wall -Wextra -Werror
LDLIBS := -lm

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) rc $(NAME) $(OBJS) $(LDLIBS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES)  -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
