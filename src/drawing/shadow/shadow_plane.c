/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 14:01:03 by yuotsubo          #+#    #+#             */
/*   Updated: 2025/03/02 14:07:27 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static double	pl_get_t(t_scene scene, t_plane plane)
{
	double	t;
	double	dn;

	dn = vec_dot(scene.shadow_ray, plane.plane_n);
	if (dn == 0)
		return (-1.0);
	t = (vec_dot(plane.plane, plane.plane_n) \
			- vec_dot(scene.shadow_inter, plane.plane_n)) \
			/ vec_dot(scene.shadow_ray, plane.plane_n);
	return (t);
}

bool	shadow_plane(t_scene scene, t_plane plane)
{
	double						t;
	t_vec3						l;

	l = vec_normalize(vec_minus(scene.light, scene.inter));
	scene.shadow_inter = vec_plus(scene.inter, \
									vec_mult(EPSILON, l));
	scene.shadow_ray = l;
	t = pl_get_t(scene, plane);
	if (t < 0)
		return (false);
	return (is_blocked_light(scene, t));
}
