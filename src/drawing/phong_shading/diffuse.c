/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diffuse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 12:59:21 by yuotsubo          #+#    #+#             */
/*   Updated: 2025/03/06 14:32:19 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

void	make_intersection(t_vec3 *intersection, double t, t_scene scene)
{
	intersection->x = scene.camera.position.x + t * scene.ray.x;
	intersection->y = scene.camera.position.y + t * scene.ray.y;
	intersection->z = scene.camera.position.z + t * scene.ray.z;
}

double	diffuse(t_scene scene, double ratio)
{
	t_vec3	l;
	double	nl;
	double	r_d;

	l = vec_normalize(vec_minus(scene.light.position, scene.inter));
	nl = vec_dot(scene.n, l);
	if (nl < 0)
		nl = vec_dot(vec_rev(scene.n), l);
	r_d = nl * KD * ratio;
	if (r_d < 0)
		r_d = 0;
	return (r_d);
}
