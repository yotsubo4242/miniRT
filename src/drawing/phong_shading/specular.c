/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specular.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 12:59:13 by yuotsubo          #+#    #+#             */
/*   Updated: 2025/02/23 19:51:40 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static double	caluc_r_s(t_scene scene, t_vec3 l, double ratio)
{
	t_vec3	v;
	t_vec3	r;
	double	r_s;

	v = vec_normalize(vec_rev(scene.ray));
	r = vec_normalize(vec_minus(vec_mult(2 * vec_dot(scene.n, l), scene.n), l));
	if (vec_dot(v, r) < 0)
		return (0.0);
	r_s = pow(vec_dot(v, r), GLOSS) * KS * ratio;
	if (r_s < 0)
		r_s = 0;
	return (r_s);
}

double	specular(t_scene scene, double ratio)
{
	t_vec3	l;

	l = vec_normalize(vec_minus(scene.light, scene.inter));
	if (vec_dot(scene.n, l) < 0)
		return (0.0);
	return (caluc_r_s(scene, l, ratio));
}
