/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specular.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo <y.otsubo.886@ms.saitama-u.ac.j    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 12:59:13 by yuotsubo          #+#    #+#             */
/*   Updated: 2025/02/20 15:42:28 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static double	caluc_r_s(t_scene scene, t_vec3 n, t_vec3 l, double ratio)
{
	t_vec3	v;
	t_vec3	r;
	double	r_s;

	v = vec_normalize(vec_rev(scene.ray));
	r = vec_normalize(vec_minus(vec_mult(2 * vec_dot(n, l), n), l));
	if (vec_dot(v, r) < 0)
		return (0.0);
	r_s = pow(vec_dot(v, r), GLOSS) * KS * ratio;
	if (r_s < 0)
		r_s = 0;
	return (r_s);
}

double	specular(t_solve_quadratic_equation qe, t_scene scene, double ratio)
{
	t_vec3	intersection;
	t_vec3	l;
	t_vec3	n;

	make_intersection(&intersection, get_t(qe), scene);
	l = vec_normalize(vec_minus(scene.light, intersection));
	n = vec_normalize(vec_minus(intersection, scene.sphere));
	if (vec_dot(n, l) < 0)
		return (0.0);
	return (caluc_r_s(scene, n, l, ratio));
}
