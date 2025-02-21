/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_shading.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:12:42 by yuotsubo          #+#    #+#             */
/*   Updated: 2025/02/19 13:43:02 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	phong_shading(t_data *data, int x, int y, double D, double a, double b, \
						t_vec3 obs, t_vec3 sphere, t_color sphare_color, t_vec3 ray)
{
	double	r_a = 0.0;
	double	r_d;
	double	r_s = 0.0;
	double	r;

	// 環境光の強度は仮で一旦入れてます. 
	r_a = ambient(0.8);
	// 拡散反射光の強度も仮で一旦入れてます.
	r_d = diffuse(D, a, b, obs, sphere, ray, 0.8);
	//r_s = specular();
	r = r_a + r_d + r_s;
	sphare_color.r = (int)(sphare_color.r * r);
	sphare_color.g = (int)(sphare_color.g * r);
	sphare_color.b = (int)(sphare_color.b * r);
	my_mlx_pixel_put(data, x, y, convert_color_to_hex(sphare_color));
}
