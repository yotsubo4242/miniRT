/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_shading.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:12:42 by yuotsubo          #+#    #+#             */
/*   Updated: 2025/02/23 19:53:17 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static t_color	drawing(t_scene scene, t_obj_type type)
{
	t_color	color;

	color.r = 0;
	color.g = 0;
	color.b = 0;
	if (type == SPHERE)
	{
		color.r = scene.sphere.sphere_color.r * scene.r;
		color.g = scene.sphere.sphere_color.g * scene.r;
		color.b = scene.sphere.sphere_color.b * scene.r;
	}
	else if (type == PLANE)
	{
		color.r = scene.plane.plane_color.r * scene.r;
		color.g = scene.plane.plane_color.g * scene.r;
		color.b = scene.plane.plane_color.b * scene.r;
	}
	else if (type == CYLINDER)
	{
		color.r = scene.cylinder.color.r * scene.r;
		color.g = scene.cylinder.color.g * scene.r;
		color.b = scene.cylinder.color.b * scene.r;
	}
	return (color);
}

void	phong_shading(t_mlx_data *mlx_data, t_point pt, t_scene scene, \
					t_obj_type type)
{
	double	r_a;
	double	r_d;
	double	r_s;
	t_color	color;

	r_a = ambient(0.8);
	r_d = diffuse(scene, 1.0);
	r_s = specular(scene, 1.0);
	scene.r = r_a + r_d + r_s;
	if (scene.r > 1)
		scene.r = 1;
	color = drawing(scene, type);
	my_mlx_pixel_put(mlx_data, pt.x, pt.y, convert_color_to_hex(color));
}
