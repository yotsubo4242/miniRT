/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diffuse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 12:59:21 by yuotsubo          #+#    #+#             */
/*   Updated: 2025/02/19 13:42:02 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	make_intersection(t_vec3 *intersection, t_vec3 obs, double t, t_vec3 ray)
{
	intersection->x = obs.x + t * ray.x;
	intersection->y = obs.y + t * ray.y;
	intersection->z = obs.z + t * ray.z;
}

double	get_t(double a, double b, double D)
{
	double	t;

	t = 0.0;
	if (D == 0)
		t = -b / (2 * a);
	else if (D > 0)
	{
		double	t1;
		double	t2;

		t1 = (-b + sqrt(D)) / (2 * a);
		t2 = (-b - sqrt(D)) / (2 * a);
		if (t1 < 0)
			t1 = DBL_MAX;
		if (t2 < 0)
			t2 = DBL_MAX;
		if (t1 < t2)
			t = t1;
		else if (t2 < t1)
			t = t2;
	}
	return (t);
}

double	diffuse(double D, double a, double b, t_vec3 obs, t_vec3 sphere, t_vec3 ray, double ratio)
{
	double	t;
	t_vec3	intersection;
	t_vec3	l;
	t_vec3	light;
	t_vec3	n;

	// 光源の初期化
	light.x = LIGHT_X;
	light.y = LIGHT_Y;
	light.z = LIGHT_Z;
	// 交点の計算
	t = get_t(a, b, D);
	make_intersection(&intersection, obs, t, ray);
	// 入射ベクトルの計算
	l = normalize(vec_minus(light, intersection));
	// 法線ベクトルの計算
	n = normalize(vec_minus(intersection, sphere));
	// 光強度、拡散反射係数を1として、拡散反射光の放射輝度を計算
	double	r_d = dot(l, n) * KD * ratio;
	if (r_d < 0)
		r_d = 0;
	return (r_d);
	//sphare_color.r = (int)(sphare_color.r * r_d);
	//sphare_color.g = (int)(sphare_color.g * r_d);
	//sphare_color.b = (int)(sphare_color.b * r_d);
	//my_mlx_pixel_put(data, x, y, convert_color_to_hex(sphare_color));
}