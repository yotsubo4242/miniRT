/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 00:49:15 by yotsubo           #+#    #+#             */
/*   Updated: 2025/03/06 17:44:25 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

static void	caluc_all_objects(t_scene *scene)
{
	t_node		*node;
	t_object	*obj;

	node = scene->objects->head;
	while (node)
	{
		obj = (t_object *)(node->data);
		if (obj->type == OBJ_SPHERE)
			sphere(scene, (t_sphere_conf *)(obj->conf));
		else if (obj->type == OBJ_PLANE)
			plane(scene, (t_plane_conf *)(obj->conf));
		else if (obj->type == OBJ_CYLINDER)
			cylinder(scene, (t_cylinder_conf *)(obj->conf));
		if (scene->tmp_t < scene->min_t && scene->tmp_t > 0)
		{
			scene->min_t = scene->tmp_t;
			scene->cur_color = scene->tmp_color;
		}
		ft_bzero(&(scene->n), sizeof(t_vec3));
		node = node->next;
	}
}

void	draw_image(t_mlx_data *mlx, t_scene scene)
{
	int	x;
	int	y;

	scene.camera_to_screen = caluc_camera_to_screen(scene);
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			scene.ray = caluc_ray(x, y, scene);
			scene.min_t = DBL_MAX;
			scene.cur_color = scene.scene_color;
			scene.tmp_color = scene.scene_color;
			caluc_all_objects(&scene);
			my_mlx_pixel_put(mlx, x, y, convert_color_to_hex(scene.cur_color));
			x++;
		}
		y++;
	}
}
