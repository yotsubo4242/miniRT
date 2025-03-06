/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:23:00 by tkitahar          #+#    #+#             */
/*   Updated: 2025/03/06 14:49:41 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "mlx.h"
# include "libft.h"
# include "get_next_line.h"
# include "vector.h"
# include "list.h"
# include <stdbool.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <string.h>
# include <float.h>

typedef double	t_radian;
typedef double	t_degree;
typedef double	t_ratio;
typedef double	t_brightness;

# define WIDTH 1000
# define HEIGHT 1000
# define EXIT_PARSE_ERROR 2
# define KA 0.1
# define KD 0.69
# define KS 0.3
# define GLOSS 8
# define EPSILON 0.03

typedef enum e_init_mlx_err {
	FT_CALLOC,
	MLX_INIT,
	MLX_NEW_WINDOW,
	MLX_NEW_IMAGE,
	MLX_GET_DATA_ADDR
}	t_init_mlx_err;

typedef enum e_object_type
{
	OBJ_SPHERE,
	OBJ_PLANE,
	OBJ_CYLINDER
}	t_object_type;

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
	int			r;
	int			g;
	int			b;
}	t_color;

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

typedef struct s_ambient_conf
{
	t_ratio	ratio;
	t_color	color;
}	t_ambient_conf;

typedef struct s_camera_conf
{
	t_vec3		position;
	t_vec3		orientation;
	t_degree	fov;
}	t_camera_conf;

typedef struct s_light_conf
{
	t_vec3			position;
	t_color			color;
	t_brightness	brightness;
}	t_light_conf;

typedef struct s_sphere_conf
{
	t_vec3			center;
	double			radius;
	t_color			color;
}	t_sphere_conf;

typedef struct s_plane_conf
{
	t_vec3			point;
	t_vec3			normal;
	t_color			color;
}	t_plane_conf;

typedef struct s_cylinder_conf
{
	t_vec3			center;
	t_vec3			axis;
	double			radius;
	double			height;
	t_color			color;
}					t_cylinder_conf;

typedef struct s_object
{
	t_object_type	type;
	void			*conf;
}	t_object;

typedef struct s_scene_count
{
	unsigned int	ambient;
	unsigned int	camera;
	unsigned int	light;
}	t_scene_count;

typedef struct s_scene
{
	t_vec3			screen;
	t_vec3			ray;
	t_ambient_conf	ambient;
	t_camera_conf	camera;
	t_light_conf	light;
	t_list			*objects;
	t_color			scene_color;
	t_color			obj_color;
	t_vec3			n;
	t_vec3			inter;
	double			min_t;
	t_color			cur_color;
	double			r;
	double			tmp_t;
	t_color			tmp_color;
	t_vec3			shadow_ray;
	t_vec3			shadow_inter;
}	t_scene;

typedef struct s_trush
{
	double	t;
	t_vec3	*n;
}	t_trush;

int				plus(int a, int b);
void			exit_with_error(int status, const char *message);
t_scene			*parse_scene(const char *path);
t_scene			*new_scene(void);

// parse_env.c
t_ambient_conf	parse_ambient(const char *line);
t_camera_conf	parse_camera(const char *line);
t_light_conf	parse_light(const char *line);

// utils.c
char			**split_space(const char *str);
int				array_size(char **array);
void			free_array(char **array);

// parse_double.c
bool			is_valid_double(const char *str);
double			parse_double(const char *str);

// in_range.c
bool			is_in_range_double(double value, double min, double max);
bool			is_in_range_uint(unsigned int value, unsigned int min, \
						unsigned int max);

// parse_uint.c
unsigned int	parse_uint(const char *str);

// parse_vec.c
t_vec3			parse_vec3(const char *str);
t_color			parse_rgb(const char *str);

// double_to.c
t_vec3			double_to_vec3(double x, double y, double z);
t_color			uint_to_color(unsigned int x, unsigned int y, unsigned int z);

// getter_rgb.c
double			rgb_get_r(t_color a);
double			rgb_get_g(t_color a);
double			rgb_get_b(t_color a);

// parse_object.c
t_object		*parse_object(const char *line);

// parse_each_object.c
t_sphere_conf	parse_sphere(const char *line);
t_plane_conf	parse_plane(const char *line);
t_cylinder_conf	parse_cylinder(const char *line);

// destructor.c
void			free_config(t_scene *config);
void			free_object(void *data);

//drawing
//draw
void			draw_image(t_mlx_data *mlx, t_scene scene);
bool			sp_get_t(t_solve_quadratic_equation qe, double *t);
void			sphere(t_scene *scene, t_sphere_conf *sphere);
void			plane(t_scene *scene, t_plane_conf *plane);
t_vec3			caluc_n(t_vec3 p, t_cylinder_conf cylinder, double tmp);
void			cy_get_ts(t_solve_quadratic_equation qe, \
							double *t1, double *t2);
void			cylinder(t_scene *scene, t_cylinder_conf *cylinder);
t_vec3			get_inter(double t, t_scene scene);
//error
void			*err_init_mlx(t_mlx_data *mlx_data, t_init_mlx_err function);
//init
t_mlx_data		*init_mlx(void);
t_scene			init_scene(void);
t_cylinder_conf	*init_cylinder(t_vec3 center, t_vec3 axis);
t_object		*init_cylinder_obj(t_cylinder_conf *cylinder);
t_sphere_conf	*init_sphere(t_vec3 center);
t_object		*init_sphere_obj(t_sphere_conf *sphere);
t_plane_conf	*init_plane(t_vec3 point, t_vec3 plane_n);
t_object		*init_plane_obj(t_plane_conf *plane);
//utils
t_vec3			caluc_ray(t_vec3 screen, t_camera_conf camera);
t_vec3			caluc_screen_point(int x, int y);
void			my_mlx_pixel_put(t_mlx_data *data, int x, int y, int color);
int				convert_color_to_hex(t_color color);
// phong_shading
void			make_intersection(t_vec3 *intersection, double t, \
									t_scene scene);
void			phong_shading(t_scene *scene, t_object obj);
double			diffuse(t_scene scene, double ratio);
double			ambient(t_ambient_conf ambient);
double			specular(t_scene scene, double ratio);
t_color			caluc_color(t_scene scene, t_object obj);
// shadow
bool			is_blocked_light(t_scene scene, double t);
bool			is_shadow(t_scene scene);
bool			shadow_sphere(t_scene scene, t_sphere_conf sphere);
bool			shadow_plane(t_scene scene, t_plane_conf plane);
bool			shadow_cylinder(t_scene scene, t_cylinder_conf cylinder);

#endif
