/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:56:22 by yotsubo           #+#    #+#             */
/*   Updated: 2025/02/23 19:43:24 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static double	pl_get_t(t_scene scene)
{
	double	t;
	double	dn;

	dn = vec_dot(scene.ray, scene.plane.plane_n);
	if (dn == 0)
		return (-1.0);
	t = (vec_dot(scene.plane.plane, scene.plane.plane_n) \
			- vec_dot(scene.camera, scene.plane.plane_n)) \
			/ vec_dot(scene.ray, scene.plane.plane_n);
	return (t);
}

void	plane(t_mlx_data *mlx_data, t_scene scene)
{
	t_point		pt;

	pt.y = 0;
	while (pt.y < HEIGHT)
	{
		pt.x = 0;
		while (pt.x < WIDTH)
		{
			scene.screen = caluc_screen_point(pt.x, pt.y);
			scene.ray = caluc_ray(scene.screen);
			scene.t = pl_get_t(scene);
			scene.n = scene.plane.plane_n;
			if (scene.t < 0)
				my_mlx_pixel_put(mlx_data, pt.x, pt.y, \
					convert_color_to_hex(scene.scene_color));
			else
				phong_shading(mlx_data, pt, scene, PLANE);
			(pt.x)++;
		}
		(pt.y)++;
	}
}
