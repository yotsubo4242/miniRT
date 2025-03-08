/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:38:44 by yuotsubo          #+#    #+#             */
/*   Updated: 2025/03/06 13:43:14 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

//# include "mlx.h"
//# include <stdlib.h>
//# include <unistd.h>
//# include <math.h>
//# include <string.h>
//# include <float.h>

//# define WIDTH 1000
//# define HEIGHT 1000
//# define OBSRV_X 0
//# define OBSRV_Y 0
//# define OBSRV_Z -2500
//# define SPHERE_X 0
//# define SPHERE_Y 0
//# define SPHERE_Z 2500
//# define SPHERE_RADIUS 500
//# define LIGHT_X -2500 -> light.position
//# define LIGHT_Y 2500 -> ..
//# define LIGHT_Z -2500 -> ..
//# define PLANE_X 0
//# define PLANE_Y 0
//# define PLANE_Z 2500
//# define PLANE_N_X 1
//# define PLANE_N_Y 0
//# define PLANE_N_Z 2
// 反射係数
//# define KA 0.1
//# define KD 0.69
//# define KS 0.3
// 鏡面反射での光沢度
//# define GLOSS 8
//# define EPSILON 0.03

//typedef enum e_init_mlx_err {
//	FT_CALLOC,
//	MLX_INIT,
//	MLX_NEW_WINDOW,
//	MLX_NEW_IMAGE,
//	MLX_GET_DATA_ADDR
//}	t_init_mlx_err;

//typedef enum e_obj_type {
//	SPHERE,
//	PLANE,
//	CYLINDER
//}	t_obj_type;

//typedef struct s_mlx_data
//{
//	void	*mlx_ptr;
//	void	*win_ptr;
//	void	*img;
//	char	*img_addr;
//	int		bpp;
//	int		line_len;
//	int		endian;
//}				t_mlx_data;

//typedef struct s_color
//{
//	int	r;
//	int	g;
//	int	b;
//}				t_color;

//typedef struct s_point
//{
//	int	x;
//	int	y;
//}	t_point;

//typedef struct s_solve_quadratic_equation
//{
//	double	a;
//	double	b;
//	double	c;
//	double	d;
//}	t_solve_quadratic_equation;
//typedef struct s_sphere
//{
//	t_vec3	center;
//	t_color	color;
//	double	diameter; -> radius
//}	t_sphere;

//typedef struct s_plane
//{
//	t_vec3		plane; -> point
//	t_vec3		plane_n; -> normal
//	t_color		plane_color; -> color
//}	t_plane;

//typedef struct s_cylinder
//{
//	t_vec3	axis;
//	t_vec3	center;
//	double	diameter; -> radius
//	double	height;
//	t_color	color;
//}	t_cylinder;

//typedef struct s_object
//{
//	t_obj_type	type;
//	void		*conf;
//}	t_object;

//typedef struct s_scene
//{
//	t_vec3		screen;
//	t_vec3		ray;
	//t_vec3		camera; -> in camera
	//t_vec3		light; -> in light
	//t_list		*obj_list;
//	t_color		scene_color;
//	t_color		obj_color;
//	t_vec3		n;
//	t_vec3		inter;
//	double		min_t;
//	t_color		cur_color;
//	double		r;
//	double		tmp_t;
//	t_color		tmp_color;
//	t_vec3		shadow_ray;
//	t_vec3		shadow_inter;
//}				t_scene;

//typedef struct s_trush
//{
//	double	t;
//	t_vec3	*n;
//}	t_trush;

////draw
//void		draw_image(t_mlx_data *mlx, t_scene scene);
//bool		sp_get_t(t_solve_quadratic_equation qe, double *t);
//void		sphere(t_scene *scene, t_sphere_conf*sphere);
//void		plane(t_scene *scene, t_plane_conf *plane);
//t_vec3		caluc_n(t_vec3 p, t_cylinder_conf cylinder, double tmp);
//void		cy_get_ts(t_solve_quadratic_equation qe, double *t1, double *t2);
//void		cylinder(t_scene *scene, t_cylinder_conf *cylinder);
//t_vec3		get_inter(double t, t_scene scene);
////error
//void		*err_init_mlx(t_mlx_data *mlx_data, t_init_mlx_err function);
////init
//t_mlx_data	*init_mlx(void);
//t_scene		init_scene(void);
//t_cylinder_conf	*init_cylinder(t_vec3 center, t_vec3 axis);
//t_object	*init_cylinder_obj(t_cylinder_conf *cylinder);
//t_sphere_conf	*init_sphere(t_vec3 center);
//t_object	*init_sphere_obj(t_sphere_conf*sphere);
//t_plane_conf		*init_plane(t_vec3 point, t_vec3 plane_n);
//t_object	*init_plane_obj(t_plane_conf *plane);
////utils
//t_vec3		caluc_ray(t_vec3 screen);
//t_vec3		caluc_screen_point(int x, int y);
//void		my_mlx_pixel_put(t_mlx_data *data, int x, int y, int color);
//int			convert_color_to_hex(t_color color);
//// phong_shading
//void		make_intersection(t_vec3 *intersection, double t, t_scene scene);
//void		phong_shading(t_scene *scene, t_object obj);
//double		diffuse(t_scene scene, double ratio);
//double		ambient(double ratio);
//double		specular(t_scene scene, double ratio);
//t_color		caluc_color(t_scene scene, t_object obj);
//// shadow
//bool		is_blocked_light(t_scene scene, double t);
//bool		is_shadow(t_scene scene);
//bool		shadow_sphere(t_scene scene, t_sphere_confsphere);
//bool		shadow_plane(t_scene scene, t_plane_conf plane);
//bool		shadow_cylinder(t_scene scene, t_cylinder_conf cylinder);

#endif
