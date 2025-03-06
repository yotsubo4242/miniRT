/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   caluc_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:38:36 by yuotsubo          #+#    #+#             */
/*   Updated: 2025/03/06 14:50:45 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

static t_color	caluc_color_sphere(t_scene scene, t_sphere_conf*sphere)
{
	t_color	color;

	color.r = sphere->color.r * scene.r;
	color.g = sphere->color.g * scene.r;
	color.b = sphere->color.b * scene.r;
	return (color);
}

static t_color	caluc_color_plane(t_scene scene, t_plane_conf *plane)
{
	t_color	color;

	color.r = plane->color.r * scene.r;
	color.g = plane->color.g * scene.r;
	color.b = plane->color.b * scene.r;
	return (color);
}

static t_color	caluc_color_cylinder(t_scene scene, t_cylinder_conf *cylinder)
{
	t_color	color;

	color.r = cylinder->color.r * scene.r;
	color.g = cylinder->color.g * scene.r;
	color.b = cylinder->color.b * scene.r;
	return (color);
}

static void	cap_color(t_color *color)
{
	if (color->r > 255)
		color->r = 255;
	if (color->g > 255)
		color->g = 255;
	if (color->b > 255)
		color->b = 255;
}

t_color	caluc_color(t_scene scene, t_object obj)
{
	t_color	color;

	if (obj.type == OBJ_SPHERE)
		color = caluc_color_sphere(scene, (t_sphere_conf *)(obj.conf));
	else if (obj.type == OBJ_PLANE)
		color = caluc_color_plane(scene, (t_plane_conf *)(obj.conf));
	else if (obj.type == OBJ_CYLINDER)
		color = caluc_color_cylinder(scene, (t_cylinder_conf *)(obj.conf));
	cap_color(&color);
	return (color);
}
