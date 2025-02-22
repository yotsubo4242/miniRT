# NAME = libdrawing.a
NAME = testdrawing
LIBFT = ../../libft/libft.a
SRCS = main.c \
	./draw/sphere.c \
	./draw/plane.c \
	./error/err_init_mlx.c \
	./init/init_mlx.c \
	./init/init_scene.c \
	./utils/caluc_screen_point.c \
	./utils/caluc_ray.c \
	./utils/my_mlx_pixel_put.c \
	./utils/convert_color_to_hex.c \
	./phong_shading/ambient.c \
	./phong_shading/diffuse.c \
	./phong_shading/specular.c \
	./phong_shading/phong_shading.c
OBJS = $(SRCS:.c=.o)
INCLUDES = -I./include -I../share/include -I../../libmlx -I../../libft
CC = cc
CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address
LIBS = -lmlx_Linux -lX11 -lXext -lm -lft -lshare
MLX_PATH = ../../libmlx
MLX = $(MLX_PATH)/libmlx_Linux.a
SHARE = ../share/libshare.a

all : $(NAME)

$(NAME) : $(OBJS) $(MLX) $(LIBFT) $(SHARE)
	$(CC) $(CFLAGS) $(INCLUDES) -L../../libmlx -L../share -L../../libft $(OBJS) $(LIBS)  -o $@ 

%.o : %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(SHARE) :
	make -C ../share

$(LIBFT) :
	make -C ../../libft

$(MLX) :
	make -C $(MLX_PATH)

clean :
	$(RM) $(OBJS)
	make clean -C $(MLX_PATH)
	make clean -C ../../libft
	make clean -C ../share

fclean : clean
	$(RM) $(NAME)
	make fclean -C ../../libft
	make fclean -C ../share

re : fclean all

.PHONY : all clean fclean re
