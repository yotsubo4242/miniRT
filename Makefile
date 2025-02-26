NAME := miniRT

CC = cc

SRC_DIR := src/list src/scene
OBJ_DIR := obj

LIBFT := libft/libft.a
SHARE := src/share/libshare.a

CFLAGS := -Wall -Wextra -Werror

RELEASE_FLAGS := -O3
DEBUG_FLAGS := -ggdb3 -O0 -fsanitize=address
INCLUDES := -Iinclude -Ilibft/includes -Ilibmlx -Isrc/share/include -Isrc/list -Isrc/scene/get_next_line -Isrc/share/list -Isrc/scene

LDFLAGS := -Llibft -Llibmlx -Lm -Lsrc/share
LDLIBS := -lft -lshare -lm

SRC := $(shell find $(SRC_DIR) -name '*.c')
SRC += src/main.c
OBJ := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))

all: CFLAGS+=$(RELEASE_FLAGS)
all : $(NAME)

debug: CFLAGS+=$(DEBUG_FLAGS)
debug: $(NAME)

$(NAME) : $(SHARE) $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) $(LDFLAGS) $(LDLIBS) -o $@

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(SHARE):
	make -C src/share

$(LIBFT):
	make -C libft

clean :
	make -C libft clean
	make -C src/share clean
	rm -rf $(OBJ_DIR)

fclean : clean
	make -C libft fclean
	make -C src/share fclean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
