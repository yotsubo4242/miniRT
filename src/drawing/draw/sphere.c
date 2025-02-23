/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo <y.otsubo.886@ms.saitama-u.ac.j    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:48:52 by yuotsubo          #+#    #+#             */
/*   Updated: 2025/02/23 00:55:56 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	caluc_qe(t_solve_quadratic_equation *qe, t_scene scene)
{
	qe->a = vec_dot(scene.ray, scene.ray);
	qe->b = 2 * (vec_dot(scene.camera, scene.ray) \
				- vec_dot(scene.sphere, scene.ray));
	qe->c = vec_dot(scene.camera, scene.camera) \
				- 2 * vec_dot(scene.sphere, scene.camera) \
				+ vec_dot(scene.sphere, scene.sphere) \
				- pow(SPHERE_RADIUS, 2);
	qe->d = pow(qe->b, 2) - 4 * qe->a * qe->c;
}

void	sphere(t_mlx_data *mlx_data, t_scene scene)
{
	t_point						pt;
	t_solve_quadratic_equation	qe;

	pt.y = 0;
	while (pt.y < HEIGHT)
	{
		pt.x = 0;
		while (pt.x < WIDTH)
		{
			scene.screen = caluc_screen_point(pt.x, pt.y);
			scene.ray = caluc_ray(scene.screen);
			caluc_qe(&qe, scene);
			if (qe.d < 0)
				my_mlx_pixel_put(mlx_data, pt.x, pt.y, \
							convert_color_to_hex(scene.scene_color));
			else
				phong_shading(mlx_data, pt, scene, qe);
			(pt.x)++;
		}
		(pt.y)++;
	}
}
