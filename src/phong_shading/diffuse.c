/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diffuse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 12:59:21 by yuotsubo          #+#    #+#             */
/*   Updated: 2025/02/19 16:07:15 by yuotsubo         ###   ########.fr       */
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

	light.x = LIGHT_X;
	light.y = LIGHT_Y;
	light.z = LIGHT_Z;
	t = get_t(a, b, D);
	make_intersection(&intersection, obs, t, ray);
	l = vec_normalize(vec_minus(light, intersection));
	n = vec_normalize(vec_minus(intersection, sphere));
	double	r_d = vec_dot(l, n) * KD * ratio;
	if (r_d < 0)
		r_d = 0;
	return (r_d);
}