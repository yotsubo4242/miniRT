/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_plane.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 01:03:55 by yotsubo           #+#    #+#             */
/*   Updated: 2025/02/26 15:38:08 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_plane	*init_plane(t_vec3 point, t_vec3 plane_n)
{
	t_plane	*plane;

	plane = ft_calloc(1, sizeof(t_plane));
	if (!plane)
		exit(1);
	plane->plane = point;
	plane->plane_n = vec_normalize(plane_n);
	plane->plane_color.r = 255;
	plane->plane_color.g = 255;
	plane->plane_color.b = 0;
	return (plane);
}

t_object	*init_plane_obj(t_plane *plane)
{
	t_object	*obj;

	obj = ft_calloc(1, sizeof(t_object));
	if (!obj)
		exit(1);
	obj->type = PLANE;
	obj->conf = plane;
	return (obj);
}
