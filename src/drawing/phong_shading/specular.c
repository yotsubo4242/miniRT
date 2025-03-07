/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specular.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 12:59:13 by yuotsubo          #+#    #+#             */
/*   Updated: 2025/03/07 15:00:26 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

static t_radiance	caluc_s_radiance(t_scene scene, t_vec3 v, \
									t_vec3 r, double brightness)
{
	t_radiance	r_s;

	r_s.r_radiance = pow(vec_dot(v, r), GLOSS) * KS \
						* brightness * (scene.light.color.r / 255);
	if (r_s.r_radiance < 0)
		r_s.r_radiance = 0;
	r_s.g_radiance = pow(vec_dot(v, r), GLOSS) * KS \
						* brightness * (scene.light.color.g / 255);
	if (r_s.g_radiance < 0)
		r_s.g_radiance = 0;
	r_s.b_radiance = pow(vec_dot(v, r), GLOSS) * KS \
						* brightness * (scene.light.color.b / 255);
	if (r_s.b_radiance < 0)
		r_s.b_radiance = 0;
	return (r_s);
}

static t_radiance	make_r_s(t_scene scene, t_vec3 l, double brightness)
{
	t_vec3		v;
	t_vec3		r;
	t_radiance	r_s;

	v = vec_normalize(vec_rev(scene.ray));
	r = vec_normalize(vec_minus(vec_mult(2 * vec_dot(scene.n, l), scene.n), l));
	if (vec_dot(v, r) < 0)
		return ((t_radiance){0.0, 0.0, 0.0});
	r_s = caluc_s_radiance(scene, v, r, brightness);
	return (r_s);
}

t_radiance	specular(t_scene scene, double brightness)
{
	t_vec3	l;

	l = vec_normalize(vec_minus(scene.light.position, scene.inter));
	if (vec_dot(scene.n, l) < 0)
		return ((t_radiance){0.0, 0.0, 0.0});
	return (make_r_s(scene, l, brightness));
}
