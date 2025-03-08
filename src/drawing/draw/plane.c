/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:56:22 by yotsubo           #+#    #+#             */
/*   Updated: 2025/03/06 14:06:35 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

static double	pl_get_t(t_scene scene, t_plane_conf plane)
{
	double	t;
	double	dn;

	dn = vec_dot(scene.ray, plane.normal);
	if (dn == 0)
		return (-1.0);
	t = (vec_dot(plane.point, plane.normal) \
			- vec_dot(scene.camera.position, plane.normal)) \
			/ vec_dot(scene.ray, plane.normal);
	return (t);
}

void	plane(t_scene *scene, t_plane_conf *plane)
{
	scene->tmp_t = pl_get_t(*scene, *plane);
	scene->n = plane->normal;
	if (scene->tmp_t < 0)
		return ;
	else
	{
		scene->inter = get_inter(scene->tmp_t, *scene);
		phong_shading(scene, (t_object){OBJ_PLANE, plane});
	}
}
