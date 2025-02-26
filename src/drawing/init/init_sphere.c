/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sphere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo <y.otsubo.886@ms.saitama-u.ac.j    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 01:01:44 by yotsubo           #+#    #+#             */
/*   Updated: 2025/02/25 02:15:04 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_sphere	*init_sphere(t_vec3 center)
{
	t_sphere	*sphere;

	sphere = ft_calloc(1, sizeof(t_sphere));
	if (!sphere)
		exit(1);
	sphere->center = center;
	sphere->diameter = SPHERE_RADIUS;
	sphere->color.r = 255;
	sphere->color.g = 0;
	sphere->color.b = 0;
	return (sphere);
}

t_object	*init_sphere_obj(t_sphere *sphere)
{
	t_object	*obj;

	obj = ft_calloc(1, sizeof(t_object));
	if (!obj)
		exit(1);
	obj->type = SPHERE;
	obj->conf = sphere;
	return (obj);
}
