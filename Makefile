NAME = test
SRCS = main.c \
	./src/my_mlx_pixel_put.c \
	./src/dot.c \
	./src/mag.c
OBJS = $(SRCS:.c=.o)
INCLUDES = -I./includes -I./libmlx
CC = cc
CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address
LIBS = -lmlx_Linux -lX11 -lXext -lm
MLX_PATH = ./libmlx
MLX = $(MLX_PATH)/libmlx_Linux.a

all : $(NAME)

$(NAME) : $(OBJS) $(MLX)
	$(CC) $(CFLAGS) $(INCLUDES) -L./libmlx $(OBJS) $(LIBS)  -o $@ 

%.o : %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(MLX) :
	make -C $(MLX_PATH)

clean :
	$(RM) $(OBJS)
	make clean -C $(MLX_PATH)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
