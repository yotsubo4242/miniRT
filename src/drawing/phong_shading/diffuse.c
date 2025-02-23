/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diffuse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 12:59:21 by yuotsubo          #+#    #+#             */
/*   Updated: 2025/02/23 19:28:15 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	make_intersection(t_vec3 *intersection, double t, t_scene scene)
{
	intersection->x = scene.camera.x + t * scene.ray.x;
	intersection->y = scene.camera.y + t * scene.ray.y;
	intersection->z = scene.camera.z + t * scene.ray.z;
}

double	diffuse(t_scene scene, double ratio)
{
	t_vec3	l;
	double	nl;
	double	r_d;

	l = vec_normalize(vec_minus(scene.light, scene.inter));
	nl = vec_dot(scene.n, l);
	if (nl < 0)
		nl = vec_dot(vec_rev(scene.n), l);
	r_d = nl * KD * ratio;
	if (r_d < 0)
		r_d = 0;
	return (r_d);
}
