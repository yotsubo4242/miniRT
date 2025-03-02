/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:11:50 by yuotsubo          #+#    #+#             */
/*   Updated: 2025/03/02 14:50:31 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	init_object_list(t_scene *scene)
{
	t_sphere	*sphere;
	t_plane		*plane;
	t_cylinder	*cylinder;

	scene->obj_list = create_list();
	if (!scene->obj_list)
		exit(1);
	sphere = init_sphere((t_vec3){-300, 0, 5000});
	push_back_list(scene->obj_list, init_sphere_obj(sphere));
	plane = init_plane((t_vec3){0, -1000, 0}, (t_vec3){0, 1, 0});
	push_back_list(scene->obj_list, init_plane_obj(plane));
	cylinder = init_cylinder((t_vec3){500, -1500, 4000}, (t_vec3){0, 1, 0});
	push_back_list(scene->obj_list, init_cylinder_obj(cylinder));
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
	init_object_list(&scene);
	return (scene);
}
