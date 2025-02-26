/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cylinder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo <y.otsubo.886@ms.saitama-u.ac.j    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 01:04:32 by yotsubo           #+#    #+#             */
/*   Updated: 2025/02/25 02:17:58 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_cylinder	*init_cylinder(t_vec3 center, t_vec3 axis)
{
	t_cylinder	*cylinder;

	cylinder = ft_calloc(1, sizeof(t_cylinder));
	if (!cylinder)
		exit(1);
	cylinder->center = center;
	cylinder->axis = vec_normalize(axis);
	cylinder->diameter = 500;
	cylinder->height = 1000;
	cylinder->color.r = 10;
	cylinder->color.g = 255;
	cylinder->color.b = 0;
	return (cylinder);
}

t_object	*init_cylinder_obj(t_cylinder *cylinder)
{
	t_object	*obj;

	obj = ft_calloc(1, sizeof(t_object));
	if (!obj)
		exit(1);
	obj->type = CYLINDER;
	obj->conf = cylinder;
	return (obj);
}
