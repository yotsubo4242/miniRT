/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_shading.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:12:42 by yuotsubo          #+#    #+#             */
/*   Updated: 2025/02/19 16:10:09 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	phong_shading(t_mlx_data *mlx_data, int x, int y, double D, double a, double b, \
						t_vec3 obs, t_vec3 sphere, t_color sphare_color, t_vec3 ray)
{
	double	r_a = 0.0;
	double	r_d;
	double	r_s = 0.0;
	double	r;

	r_a = ambient(0.1);
	r_d = diffuse(D, a, b, obs, sphere, ray, 1.0);
	r_s = specular(D, a, b, obs, sphere, ray, 1.0);
	r = r_a + r_d + r_s;
	sphare_color.r = (int)(sphare_color.r * r);
	sphare_color.g = (int)(sphare_color.g * r);
	sphare_color.b = (int)(sphare_color.b * r);
	my_mlx_pixel_put(mlx_data, x, y, convert_color_to_hex(sphare_color));
}
