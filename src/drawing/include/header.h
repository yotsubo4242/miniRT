/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:38:44 by yuotsubo          #+#    #+#             */
/*   Updated: 2025/02/22 19:09:06 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "mlx.h"
# include "libft.h"
# include "vector.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <string.h>
# include <limits.h>
# include <float.h>
# include <stdbool.h>

# define WIDTH 1000
# define HEIGHT 1000
# define OBSRV_X 0
# define OBSRV_Y 0
# define OBSRV_Z -2500
# define SPHERE_X 0
# define SPHERE_Y 0
# define SPHERE_Z 2500
# define SPHERE_RADIUS 500
# define LIGHT_X -2500
# define LIGHT_Y 2500
# define LIGHT_Z -2500
# define PLANE_X 0
# define PLANE_Y 0
# define PLANE_Z 2500
# define PLANE_N_X 1
# define PLANE_N_Y 0
# define PLANE_N_Z 2
// 反射係数
# define KA 0.01
# define KD 0.69
# define KS 0.3
// 鏡面反射での光沢度
# define GLOSS 8

typedef struct s_mlx_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
	char	*img_addr;
	int		bpp;
	int		line_len;
	int		endian;
}				t_mlx_data;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}				t_color;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_solve_quadratic_equation
{
	double	a;
	double	b;
	double	c;
	double	d;
}	t_solve_quadratic_equation;

typedef struct s_scene
{
	t_vec3	screen;
	t_vec3	ray;
	t_vec3	camera;
	t_vec3	sphere;
	t_vec3	plane;
	t_vec3	plane_n;
	t_vec3	light;
	t_color	sphere_color;
	t_color	plane_color;
	t_color	scene_color;
}				t_scene;

typedef enum e_init_mlx_err {
	FT_CALLOC,
	MLX_INIT,
	MLX_NEW_WINDOW,
	MLX_NEW_IMAGE,
	MLX_GET_DATA_ADDR
}	t_init_mlx_err;

//draw
void		sphere(t_mlx_data *mlx_data, t_scene scene);
//error
void		*err_init_mlx(t_mlx_data *mlx_data, t_init_mlx_err function);
//init
t_mlx_data	*init_mlx(void);
t_scene		init_scene(void);
//utils
t_vec3		caluc_ray(t_vec3 screen);
t_vec3		caluc_screen_point(int x, int y);
void		my_mlx_pixel_put(t_mlx_data *data, int x, int y, int color);
int			convert_color_to_hex(t_color color);
// phong_shading
void		make_intersection(t_vec3 *intersection, double t, t_scene scene);
double		get_t(t_solve_quadratic_equation qe);
void		phong_shading(t_mlx_data *mlx_data, t_point pt, \
							t_scene scene, t_solve_quadratic_equation qe);
double		diffuse(t_solve_quadratic_equation qe, t_scene scene, double ratio);
double		ambient(double ratio);
double		specular(t_solve_quadratic_equation qe, \
						t_scene scene, double ratio);

void		plane(t_mlx_data *mlx_data, t_scene scene);
double		pl_get_t(t_scene scene);
double		pl_diffuse(t_scene scene, double ratio);
void		pl_phong_shading(t_mlx_data *mlx_data, t_point pt, t_scene scene);
double		pl_specular(t_scene scene, double ratio);

#endif
