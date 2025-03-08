/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 14:01:03 by yuotsubo          #+#    #+#             */
/*   Updated: 2025/03/06 14:04:41 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

static double	pl_get_t(t_scene scene, t_plane_conf plane)
{
	double	t;
	double	dn;

	dn = vec_dot(scene.shadow_ray, plane.normal);
	if (dn == 0)
		return (-1.0);
	t = (vec_dot(plane.point, plane.normal) \
			- vec_dot(scene.shadow_inter, plane.normal)) \
			/ vec_dot(scene.shadow_ray, plane.normal);
	return (t);
}

bool	shadow_plane(t_scene scene, t_plane_conf plane)
{
	double						t;
	t_vec3						l;

	l = vec_normalize(vec_minus(scene.light.position, scene.inter));
	scene.shadow_inter = vec_plus(scene.inter, \
									vec_mult(EPSILON, l));
	scene.shadow_ray = l;
	t = pl_get_t(scene, plane);
	if (t < 0)
		return (false);
	return (is_blocked_light(scene, t));
}
