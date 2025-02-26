/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitahar <tkitahar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:23:00 by tkitahar          #+#    #+#             */
/*   Updated: 2025/02/24 14:19:36 by tkitahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include <stdbool.h>
# include <stdio.h>
# include "libft.h"
# include "list.h"
# include "get_next_line.h"
# include <fcntl.h>
# include <errno.h>
# include "vector.h"

typedef double	t_radian;
typedef double	t_degree;
typedef double	t_ratio;
typedef double	t_brightness;

# define EXIT_PARSE_ERROR 2

typedef struct s_color
{
	int			r;
	int			g;
	int			b;
}	t_color;

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

typedef enum e_object_type
{
	OBJ_SPHERE,
	OBJ_PLANE,
	OBJ_CYLINDER
}	t_object_type;

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
	t_ambient_conf	ambient;
	t_camera_conf	camera;
	t_light_conf	light;
	t_list			*objects;
}	t_scene;

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
#endif
