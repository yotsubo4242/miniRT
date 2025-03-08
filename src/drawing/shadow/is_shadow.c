/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_shadow.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 12:17:04 by yuotsubo          #+#    #+#             */
/*   Updated: 2025/03/06 14:50:26 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

bool	is_shadow(t_scene scene)
{
	t_node		*node;
	t_object	*obj;
	bool		is_blocked_light;

	node = scene.objects->head;
	is_blocked_light = false;
	while (node)
	{
		obj = (t_object *)(node->data);
		if (obj->type == OBJ_SPHERE)
			is_blocked_light = shadow_sphere(scene, \
								*(t_sphere_conf *)(obj->conf));
		else if (obj->type == OBJ_PLANE)
			is_blocked_light = shadow_plane(scene, \
								*(t_plane_conf *)(obj->conf));
		else if (obj->type == OBJ_CYLINDER)
			is_blocked_light = shadow_cylinder(scene, \
										*(t_cylinder_conf *)(obj->conf));
		if (is_blocked_light == true)
			return (true);
		node = node->next;
	}
	return (false);
}
