/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:11:50 by yuotsubo          #+#    #+#             */
/*   Updated: 2025/02/23 18:38:07 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	init_plane(t_scene *scene)
{
	scene->plane.plane.x = PLANE_X;
	scene->plane.plane.y = PLANE_Y;
	scene->plane.plane.z = PLANE_Z;
	scene->plane.plane_n.x = PLANE_N_X;
	scene->plane.plane_n.y = PLANE_N_Y;
	scene->plane.plane_n.z = PLANE_N_Z;
	scene->plane.plane_n = vec_normalize(scene->plane.plane_n);
	scene->plane.plane_color.r = 255;
	scene->plane.plane_color.g = 255;
	scene->plane.plane_color.b = 0;
}

static void	init_cylinder(t_scene *scene)
{
	scene->cylinder.center.x = 0.0;
	scene->cylinder.center.y = -500.0;
	scene->cylinder.center.z = 500;
	scene->cylinder.axis.x = 0.0;
	scene->cylinder.axis.y = 1.0;
	scene->cylinder.axis.z = 0.0;
	scene->cylinder.diameter = 500;
	scene->cylinder.height = 1000;
	scene->cylinder.color.r = 10;
	scene->cylinder.color.g = 0;
	scene->cylinder.color.b = 255;
}

static void	init_sphere(t_scene *scene)
{
	scene->sphere.sphere_color.r = 255;
	scene->sphere.sphere_color.g = 0;
	scene->sphere.sphere_color.b = 0;
	scene->sphere.sphere.x = SPHERE_X;
	scene->sphere.sphere.y = SPHERE_Y;
	scene->sphere.sphere.z = SPHERE_Z;
}

t_scene	init_scene(void)
{
	t_scene	scene;

	scene.camera.x = OBSRV_X;
	scene.camera.y = OBSRV_Y;
	scene.camera.z = OBSRV_Z;
	scene.light.x = LIGHT_X;
	scene.light.y = LIGHT_Y;
	scene.light.z = LIGHT_Z;
	scene.scene_color.r = 255;
	scene.scene_color.g = 255;
	scene.scene_color.b = 255;
	init_cylinder(&scene);
	init_sphere(&scene);
	init_plane(&scene);
	return (scene);
}
