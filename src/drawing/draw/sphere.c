/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:48:52 by yuotsubo          #+#    #+#             */
/*   Updated: 2025/02/23 20:06:04 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	caluc_qe(t_solve_quadratic_equation *qe, t_scene scene)
{
	qe->a = vec_dot(scene.ray, scene.ray);
	qe->b = 2 * (vec_dot(scene.camera, scene.ray) \
				- vec_dot(scene.sphere.sphere, scene.ray));
	qe->c = vec_dot(scene.camera, scene.camera) \
				- 2 * vec_dot(scene.sphere.sphere, scene.camera) \
				+ vec_dot(scene.sphere.sphere, scene.sphere.sphere) \
				- pow(SPHERE_RADIUS, 2);
	qe->d = pow(qe->b, 2) - 4 * qe->a * qe->c;
}

static bool	sp_get_t(t_solve_quadratic_equation qe, double *t)
{
	double	t1;
	double	t2;

	if (qe.d < 0)
		return (false);
	if (qe.d == 0)
		*t = -qe.b / (2 * qe.a);
	else if (qe.d > 0)
	{
		t1 = (-qe.b + sqrt(qe.d)) / (2 * qe.a);
		t2 = (-qe.b - sqrt(qe.d)) / (2 * qe.a);
		if (t1 < 0 && t2 < 0)
			return (false);
		if (t1 < 0)
			*t = t2;
		else if (t2 < 0)
			*t = t1;
		else if (t1 < t2)
			*t = t1;
		else if (t2 < t1)
			*t = t2;
	}
	return (true);
}

static void	caluc_sphere(t_mlx_data *mlx_data, t_scene scene, t_point pt)
{
	t_solve_quadratic_equation	qe;

	scene.screen = caluc_screen_point(pt.x, pt.y);
	scene.ray = caluc_ray(scene.screen);
	caluc_qe(&qe, scene);
	if (qe.d < 0 || !sp_get_t(qe, &(scene.t)))
	{
		my_mlx_pixel_put(mlx_data, pt.x, pt.y, \
					convert_color_to_hex(scene.scene_color));
	}
	else
	{
		scene.inter = get_inter(scene.t, scene);
		scene.n = vec_normalize(\
				vec_minus(scene.inter, scene.sphere.sphere));
		phong_shading(mlx_data, pt, scene, SPHERE);
	}
}

void	sphere(t_mlx_data *mlx_data, t_scene scene)
{
	t_point						pt;

	pt.y = 0;
	while (pt.y < HEIGHT)
	{
		pt.x = 0;
		while (pt.x < WIDTH)
		{
			caluc_sphere(mlx_data, scene, pt);
			(pt.x)++;
		}
		(pt.y)++;
	}
}
