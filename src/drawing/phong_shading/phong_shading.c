/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_shading.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo <y.otsubo.886@ms.saitama-u.ac.j    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:12:42 by yuotsubo          #+#    #+#             */
/*   Updated: 2025/02/20 15:44:42 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	phong_shading(t_mlx_data *mlx_data, t_point pt, \
						t_scene scene, t_solve_quadratic_equation qe)
{
	double	r_a;
	double	r_d;
	double	r_s;
	double	r;

	r_a = ambient(0.1);
	r_d = diffuse(qe, scene, 1.0);
	r_s = specular(qe, scene, 1.0);
	r = r_a + r_d + r_s;
	scene.sphere_color.r = (int)(scene.sphere_color.r * r);
	scene.sphere_color.g = (int)(scene.sphere_color.g * r);
	scene.sphere_color.b = (int)(scene.sphere_color.b * r);
	my_mlx_pixel_put(mlx_data, pt.x, pt.y, \
					convert_color_to_hex(scene.sphere_color));
}
