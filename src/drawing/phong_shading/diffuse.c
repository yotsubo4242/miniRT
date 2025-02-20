/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diffuse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo <y.otsubo.886@ms.saitama-u.ac.j    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 12:59:21 by yuotsubo          #+#    #+#             */
/*   Updated: 2025/02/20 15:49:13 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	make_intersection(t_vec3 *intersection, double t, t_scene scene)
{
	intersection->x = scene.camera.x + t * scene.ray.x;
	intersection->y = scene.camera.y + t * scene.ray.y;
	intersection->z = scene.camera.z + t * scene.ray.z;
}

double	get_t(t_solve_quadratic_equation qe)
{
	double	t;
	double	t1;
	double	t2;

	t = 0.0;
	if (qe.d == 0)
		t = -qe.b / (2 * qe.a);
	else if (qe.d > 0)
	{
		t1 = (-qe.b + sqrt(qe.d)) / (2 * qe.a);
		t2 = (-qe.b - sqrt(qe.d)) / (2 * qe.a);
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

double	diffuse(t_solve_quadratic_equation qe, t_scene scene, double ratio)
{
	double	t;
	t_vec3	intersection;
	t_vec3	l;
	t_vec3	n;
	double	r_d;

	t = get_t(qe);
	make_intersection(&intersection, t, scene);
	l = vec_normalize(vec_minus(scene.light, intersection));
	n = vec_normalize(vec_minus(intersection, scene.sphere));
	r_d = vec_dot(l, n) * KD * ratio;
	if (r_d < 0)
		r_d = 0;
	return (r_d);
}
