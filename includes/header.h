/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:38:44 by yuotsubo          #+#    #+#             */
/*   Updated: 2025/02/19 14:46:50 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <string.h>
# include <limits.h>
# include <float.h>

#define WIDTH 1000
#define HEIGHT 1000
#define OBSRV_X 0
#define OBSRV_Y 0
#define OBSRV_Z -2500
#define SPHERE_X 0
#define SPHERE_Y 0
#define SPHERE_Z 2500
#define SPHERE_RADIUS 500
#define LIGHT_X -2500
#define LIGHT_Y 2500
#define LIGHT_Z -2500
// 反射係数
#define KA 0.01
#define KD 0.69
#define KS 0.3
// 鏡面反射での光沢度
#define GLOSS 8

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
	char	*img_addr;
	int		bpp;
	int		line_len;
	int		endian;
}				t_data;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}				t_color;

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}				t_vec3;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		convert_color_to_hex(t_color color);
// vector
t_vec3	normalize(t_vec3 a);
double	mag(t_vec3 a);
double	dot(t_vec3 a, t_vec3 b);
t_vec3	vec_minus(t_vec3 a, t_vec3 b);
t_vec3	vec_mult(double	x, t_vec3 v);
t_vec3	vec_rev(t_vec3 v);
// phong_shading
void	make_intersection(t_vec3 *intersection, t_vec3 obs, double t, t_vec3 ray);
double	get_t(double a, double b, double D);
void	phong_shading(t_data *data, int x, int y, double D, double a, double b, \
						t_vec3 obs, t_vec3 sphere, t_color sphare_color, t_vec3 ray);
double	diffuse(double D, double a, double b, t_vec3 obs, t_vec3 sphere, t_vec3 ray, double ratio);
double	ambient(double ratio);
double	specular(double D, double a, double b, t_vec3 obs, t_vec3 sphere, t_vec3 ray, double ratio);

#endif