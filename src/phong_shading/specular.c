/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specular.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 12:59:13 by yuotsubo          #+#    #+#             */
/*   Updated: 2025/02/19 15:29:15 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

double	specular(double D, double a, double b, t_vec3 obs, t_vec3 sphere, t_vec3 ray, double ratio)
{
	double	t;
	t_vec3	intersection;
	t_vec3	l;
	t_vec3	light;
	t_vec3	n;
	t_vec3	r;
	t_vec3	v;

	// 光源の初期化
	light.x = LIGHT_X;
	light.y = LIGHT_Y;
	light.z = LIGHT_Z;
	// 交点の計算
	t = get_t(a, b, D);
	make_intersection(&intersection, obs, t, ray);
	// 入射ベクトルの計算
	l = vec_normalize(vec_minus(light, intersection));
	// 法線ベクトルの計算
	n = vec_normalize(vec_minus(intersection, sphere));
	if (vec_dot(n, l) < 0)
		return (0.0);
	v = vec_normalize(vec_rev(ray));
	r = vec_normalize(vec_minus(vec_mult(2 * vec_dot(n, l), n), l));
	if (vec_dot(v, r) < 0)
		return (0.0);
	// 光強度、拡散反射係数を1として、拡散反射光の放射輝度を計算
	double	r_s = pow(vec_dot(v, r), GLOSS) * KS * ratio;
	if (r_s < 0)
		r_s = 0;
	return (r_s);
}