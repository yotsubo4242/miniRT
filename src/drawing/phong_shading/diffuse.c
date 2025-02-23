/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diffuse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 12:59:21 by yuotsubo          #+#    #+#             */
/*   Updated: 2025/02/23 15:31:41 by yuotsubo         ###   ########.fr       */
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
		if (t1 < 0 && t2 < 0)
			return (0.0);
		if (t1 < 0)
			return (t2);
		if (t2 < 0)
			return (t1);
		if (t1 < t2)
			t = t1;
		else if (t2 < t1)
			t = t2;
	}
	return (t);
}

double	pl_get_t(t_scene scene)
{
	double	t;
	double	dn;

	dn = vec_dot(scene.ray, scene.plane_n);
	if (dn == 0)
		return (0);
	t = (vec_dot(scene.plane, scene.plane_n) \
			- vec_dot(scene.camera, scene.plane_n)) \
			/ vec_dot(scene.ray, scene.plane_n);
	return (t);
}

double	pl_diffuse(t_scene scene, double ratio)
{
	double	t;
	t_vec3	intersection;
	t_vec3	l;
	double	nl;
	double	r_d;

	t = pl_get_t(scene);
	make_intersection(&intersection, t, scene);
	l = vec_normalize(vec_minus(scene.light, intersection));
	nl = vec_dot(scene.plane_n, l);
	if (nl < 0)
		nl = vec_dot(vec_rev(scene.plane_n), l);
	r_d = KD * ratio * nl;
	if (r_d < 0)
		r_d = 0;
	return (r_d);
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
