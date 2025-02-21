NAME := miniRT

CC = cc

SRC_DIR := src/list src/scene
OBJ_DIR := obj

LIBFT := libft/libft.a

CFLAGS := -Wall -Wextra -Werror

RELEASE_FLAGS := -O3
DEBUG_FLAGS := -ggdb3 -O0 -fsanitize=address
INCLUDES := -Iinclude -Isrc -Ilibft/includes -I./includes -I./libmlx

LDFLAGS := -Llibft -Llibmlx -Lm
LDLIBS := -lft -lmlx_Linux -lX11 -lXext -lm

SRC := $(shell find $(SRC_DIR) -name '*.c')
SRC += $(shell find src -name 'main.c')
OBJ := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))

all: CFLAGS+=$(RELEASE_FLAGS)
all : $(NAME)

debug: CFLAGS+=$(DEBUG_FLAGS)
debug: $(NAME)

$(NAME) : $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) $(LDFLAGS) $(LDLIBS) -o $@

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	make -C libft

clean :
	make -C libft clean
	rm -rf $(OBJ_DIR)

fclean : clean
	make -C libft fclean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
