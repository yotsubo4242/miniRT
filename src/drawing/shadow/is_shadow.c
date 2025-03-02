/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_shadow.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 12:17:04 by yuotsubo          #+#    #+#             */
/*   Updated: 2025/03/02 13:58:54 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

bool	is_shadow(t_scene scene)
{
	t_node		*node;
	t_object	*obj;
	bool		is_blocked_light;

	node = scene.obj_list->head;
	is_blocked_light = false;
	while (node)
	{
		obj = (t_object *)(node->data);
		if (obj->type == SPHERE)
			is_blocked_light = shadow_sphere(scene, *(t_sphere *)(obj->conf));
		//else if (obj->type == PLANE)
		//	shadow_plane(scene, (t_plane *)(obj->conf));
		//else if (obj->type == CYLINDER)
		//	shadow_cylinder(scene, (t_cylinder *)(obj->conf));
		if (is_blocked_light == true)
			return (true);
		node = node->next;
	}
	return (false);
}