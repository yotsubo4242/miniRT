NAME = test
LIBFT = ./libft/libft.a
SRCS = main.c \
	./src/draw/sphere.c \
	./src/error/err_init_mlx.c \
	./src/init/init_mlx.c \
	./src/init/init_scene.c \
	./src/utils/caluc_screen_point.c \
	./src/utils/caluc_ray.c \
	./src/utils/my_mlx_pixel_put.c \
	./src/utils/convert_color_to_hex.c \
	./src/vector/vec_dot.c \
	./src/vector/vec_eq.c \
	./src/vector/vec_is_normalized.c \
	./src/vector/vec_mag.c \
	./src/vector/vec_normalize.c \
	./src/vector/vec_minus.c \
	./src/vector/vec_mult.c \
	./src/vector/vec_rev.c \
	./src/phong_shading/ambient.c \
	./src/phong_shading/diffuse.c \
	./src/phong_shading/specular.c \
	./src/phong_shading/phong_shading.c
OBJS = $(SRCS:.c=.o)
INCLUDES = -I./includes -I./libmlx -I./libft
CC = cc
CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address
LIBS = -lmlx_Linux -lX11 -lXext -lm -lft
MLX_PATH = ./libmlx
MLX = $(MLX_PATH)/libmlx_Linux.a

all : $(NAME)

$(NAME) : $(OBJS) $(MLX) $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDES) -L./libmlx -L./libft $(OBJS) $(LIBS)  -o $@ 

%.o : %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT) :
	make -C ./libft

$(MLX) :
	make -C $(MLX_PATH)

clean :
	$(RM) $(OBJS)
	make clean -C $(MLX_PATH)
	make clean -C ./libft

fclean : clean
	$(RM) $(NAME)
	make fclean -C ./libft

re : fclean all

.PHONY : all clean fclean re
