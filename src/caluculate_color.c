/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   caluculate_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:12:42 by yuotsubo          #+#    #+#             */
/*   Updated: 2025/02/18 17:44:26 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	make_intersection(t_vec3 *intersection, t_vec3 obs, double t, t_vec3 ray)
{
	intersection->x = obs.x + t * ray.x;
	intersection->y = obs.y + t * ray.y;
	intersection->z = obs.z + t * ray.z;
}

void	caluculate_color(t_data *data, int x, int y, double D, double a, double b, \
						t_vec3 obs, t_vec3 sphere, t_color sphare_color, t_vec3 ray)
{
	double	t = 0.0;
	t_vec3	intersection;
	t_vec3	l;
	t_vec3	light;
	t_vec3	n;

	// 光源の初期化
	light.x = LIGHT_X;
	light.y = LIGHT_Y;
	light.z = LIGHT_Z;
	// 交点の計算
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
		else
			return ;
	}
	make_intersection(&intersection, obs, t, ray);
	// 入射ベクトルの計算
	l = normalize(vec_minus(light, intersection));
	printf("l: %f, %f, %f\n", l.x, l.y, l.z);
	// 法線ベクトルの計算
	n = normalize(vec_minus(intersection, sphere));
	printf("n: %f, %f, %f\n", n.x, n.y, n.z);
	// 光強度、拡散反射係数を1として、拡散反射光の放射輝度を計算
	double	r_d = dot(l, n);
	printf("r_d: %f\n", r_d);
	if (r_d < 0)
		r_d = 0;
	sphare_color.r = (int)(sphare_color.r * r_d);
	sphare_color.g = (int)(sphare_color.g * r_d);
	sphare_color.b = (int)(sphare_color.b * r_d);
	my_mlx_pixel_put(data, x, y, convert_color_to_hex(sphare_color));
}