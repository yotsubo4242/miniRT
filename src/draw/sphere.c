/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:48:52 by yuotsubo          #+#    #+#             */
/*   Updated: 2025/02/19 18:00:41 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	sphere(t_mlx_data *mlx_data, t_scene scene)
{
	int							x;
	int							y;
	t_solve_quadratic_equation	qe;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			scene.screen = caluc_screen_point(x, y);
			scene.ray = caluc_ray(scene.screen);
			qe.a = vec_dot(scene.ray, scene.ray);
			qe.b = 2 * (vec_dot(scene.camera, scene.ray) \
						- vec_dot(scene.sphere, scene.ray));
			qe.c = vec_dot(scene.camera, scene.camera) \
						- 2 * vec_dot(scene.sphere, scene.camera) \
						+ vec_dot(scene.sphere, scene.sphere) \
						- pow(SPHERE_RADIUS, 2);
			qe.D = pow(qe.b, 2) - 4 * qe.a * qe.c;
			if (qe.D < 0)
				my_mlx_pixel_put(mlx_data, x, y, \
							convert_color_to_hex(scene.scene_color));
			else
				phong_shading(mlx_data, x, y, qe.D, qe.a, qe.b, scene.camera, \
							scene.sphere, scene.sphere_color, scene.ray);
			x++;
		}
		y++;
	}
}
