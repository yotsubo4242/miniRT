NAME := miniRT

SRC_DIR := src
OBJ_DIR := obj

LIBFT := libft/libft.a

CFLAGS := -Wall -Wextra -Werror

RELEASE_FLAGS := -O3
DEBUG_FLAGS := -ggdb3 -O0 -fsanitize=address
INCLUDES := -Iinclude -Isrc -Ilibft/include

CC := cc
CFLAGS := -Wall -Wextra -Werror -g #-fsanitize=address

LDFLAGS := -Llibft
LDLIBS := -lft

SRC := *.c
OBJ := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))

all: CFLAGS+=$(RELEASE_FLAGS)
all : $(NAME)

debug: CFLAGS+=$(DEBUG_FLAGS)
debug: $(NAME)

$(NAME) : $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LDLIBS) $(LDFLAGS) -o $@ $^

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	make -C libft

clean :
	make -C libft clean
	$(RM) $(OBJS)

fclean : clean
	make -C libft fclean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
