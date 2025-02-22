/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:11:50 by yuotsubo          #+#    #+#             */
/*   Updated: 2025/02/22 19:09:13 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	init_objects(t_scene *scene)
{
	scene->plane.x = PLANE_X;
	scene->plane.y = PLANE_Y;
	scene->plane.z = PLANE_Z;
	scene->plane_n.x = PLANE_N_X;
	scene->plane_n.y = PLANE_N_Y;
	scene->plane_n.z = PLANE_N_Z;
	scene->plane_n = vec_normalize(scene->plane_n);
	scene->plane_color.r = 255;
	scene->plane_color.g = 255;
	scene->plane_color.b = 0;
}

t_scene	init_scene(void)
{
	t_scene	scene;

	scene.camera.x = OBSRV_X;
	scene.camera.y = OBSRV_Y;
	scene.camera.z = OBSRV_Z;
	scene.sphere.x = SPHERE_X;
	scene.sphere.y = SPHERE_Y;
	scene.sphere.z = SPHERE_Z;
	scene.light.x = LIGHT_X;
	scene.light.y = LIGHT_Y;
	scene.light.z = LIGHT_Z;
	scene.sphere_color.r = 255;
	scene.sphere_color.g = 0;
	scene.sphere_color.b = 0;
	scene.scene_color.r = 255;
	scene.scene_color.g = 255;
	scene.scene_color.b = 255;
	init_objects(&scene);
	return (scene);
}
