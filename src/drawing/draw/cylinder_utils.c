/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 17:26:10 by yuotsubo          #+#    #+#             */
/*   Updated: 2025/02/23 17:34:50 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	caluc_qe(t_solve_quadratic_equation *qe, t_scene scene)
{
	t_vec3	dxn;

	dxn = vec_cross(scene.ray, scene.cylinder.axis);
	qe->a = vec_dot(dxn, dxn);
	qe->b = 2 * vec_dot(\
					dxn, vec_cross(\
							vec_minus(scene.camera, scene.cylinder.center), \
							scene.cylinder.axis));
	qe->c = vec_dot(vec_cross(vec_minus(scene.camera, scene.cylinder.center), \
							scene.cylinder.axis), \
					vec_cross(vec_minus(scene.camera, scene.cylinder.center), \
							scene.cylinder.axis)) \
			- pow(scene.cylinder.diameter, 2);
	qe->d = pow(qe->b, 2) - 4 * qe->a * qe->c;
}

static void	cy_get_ts(t_solve_quadratic_equation qe, double *t1, double *t2)
{
	if (qe.d == 0)
		*t1 = -qe.b / (2 * qe.a);
	else if (qe.d > 0)
	{
		*t1 = (-qe.b - sqrt(qe.d)) / (2 * qe.a);
		*t2 = (-qe.b + sqrt(qe.d)) / (2 * qe.a);
	}
}

static t_vec3	caluc_n(t_vec3 p, t_scene scene, double tmp)
{
	t_vec3	n;

	n = vec_minus(vec_minus(p, scene.cylinder.center), \
					vec_mult(tmp, scene.cylinder.axis));
	return (n);
}

static t_vec3	*cy_make_n(t_solve_quadratic_equation qe, \
							t_scene scene, double *t)
{
	t_vec3	p;
	t_vec3	n;
	double	t1;
	double	t2;
	double	tmp;

	cy_get_ts(qe, &t1, &t2);
	p = vec_plus(scene.camera, vec_mult(t1, scene.ray));
	tmp = vec_dot(vec_minus(p, scene.cylinder.center), scene.cylinder.axis);
	if (tmp >= 0 && tmp <= scene.cylinder.height)
	{
		n = caluc_n(p, scene, tmp);
		*t = t1;
		return (vec_dup(vec_div(n, vec_mag(n))));
	}
	p = vec_plus(scene.camera, vec_mult(t2, scene.ray));
	tmp = vec_dot(vec_minus(p, scene.cylinder.center), scene.cylinder.axis);
	if (tmp >= 0 && tmp <= scene.cylinder.height)
	{
		n = caluc_n(p, scene, tmp);
		*t = t2;
		return (vec_dup(vec_div(n, vec_mag(n))));
	}
	return (NULL);
}

void	caluc_cylinder(t_scene scene, t_point pt, t_mlx_data *mlx_data)
{
	t_solve_quadratic_equation	qe;
	t_vec3						dxn;
	t_trush						trush;

	scene.screen = caluc_screen_point(pt.x, pt.y);
	scene.ray = caluc_ray(scene.screen);
	caluc_qe(&qe, scene);
	dxn = vec_cross(scene.ray, scene.cylinder.axis);
	trush.n = cy_make_n(qe, scene, &(trush.t));
	if (trush.n == NULL)
		my_mlx_pixel_put(mlx_data, pt.x, pt.y, \
					convert_color_to_hex(scene.scene_color));
	else if (vec_dot(dxn, dxn) == 0)
		my_mlx_pixel_put(mlx_data, pt.x, pt.y, \
					convert_color_to_hex(scene.scene_color));
	else if (qe.d < 0)
		my_mlx_pixel_put(mlx_data, pt.x, pt.y, \
					convert_color_to_hex(scene.scene_color));
	else
		cy_phong_shading(mlx_data, pt, scene, trush);
	free(trush.n);
}
