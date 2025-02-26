/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:56:22 by yotsubo           #+#    #+#             */
/*   Updated: 2025/02/26 15:23:08 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static double	pl_get_t(t_scene scene, t_plane plane)
{
	double	t;
	double	dn;

	dn = vec_dot(scene.ray, plane.plane_n);
	if (dn == 0)
		return (-1.0);
	t = (vec_dot(plane.plane, plane.plane_n) \
			- vec_dot(scene.camera, plane.plane_n)) \
			/ vec_dot(scene.ray, plane.plane_n);
	return (t);
}

void	plane(t_scene *scene, t_plane *plane)
{
	scene->tmp_t = pl_get_t(*scene, *plane);
	scene->n = plane->plane_n;
	if (scene->tmp_t < 0)
		return ;
	else
	{
		scene->inter = get_inter(scene->tmp_t, *scene);
		phong_shading(scene, (t_object){PLANE, plane});
	}
}
