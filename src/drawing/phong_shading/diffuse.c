/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diffuse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 12:59:21 by yuotsubo          #+#    #+#             */
/*   Updated: 2025/03/07 15:02:50 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

void	make_intersection(t_vec3 *intersection, double t, t_scene scene)
{
	intersection->x = scene.camera.position.x + t * scene.ray.x;
	intersection->y = scene.camera.position.y + t * scene.ray.y;
	intersection->z = scene.camera.position.z + t * scene.ray.z;
}

static t_radiance	caluc_diffuse_radiance(t_scene scene, \
										double nl, double brightness)
{
	t_radiance	r_d;

	r_d.r_radiance = nl * KD * brightness * (scene.light.color.r / 255);
	if (r_d.r_radiance < 0)
		r_d.r_radiance = 0;
	r_d.g_radiance = nl * KD * brightness * (scene.light.color.g / 255);
	if (r_d.g_radiance < 0)
		r_d.g_radiance = 0;
	r_d.b_radiance = nl * KD * brightness * (scene.light.color.b / 255);
	if (r_d.b_radiance < 0)
		r_d.b_radiance = 0;
	return (r_d);
}

t_radiance	diffuse(t_scene scene, double brightness)
{
	t_vec3		l;
	double		nl;
	t_radiance	r_d;

	l = vec_normalize(vec_minus(scene.light.position, scene.inter));
	nl = vec_dot(scene.n, l);
	if (nl < 0)
		nl = vec_dot(vec_rev(scene.n), l);
	r_d = caluc_diffuse_radiance(scene, nl, brightness);
	return (r_d);
}
