/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_shading.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:12:42 by yuotsubo          #+#    #+#             */
/*   Updated: 2025/02/26 15:27:07 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_color	caluc_color_sphere(t_scene scene, t_sphere *sphere)
{
	t_color	color;

	color.r = sphere->color.r * scene.r;
	color.g = sphere->color.g * scene.r;
	color.b = sphere->color.b * scene.r;
	return (color);
}

t_color	caluc_color_plane(t_scene scene, t_plane *plane)
{
	t_color	color;

	color.r = plane->plane_color.r * scene.r;
	color.g = plane->plane_color.g * scene.r;
	color.b = plane->plane_color.b * scene.r;
	return (color);
}

t_color	caluc_color_cylinder(t_scene scene, t_cylinder *cylinder)
{
	t_color	color;

	color.r = cylinder->color.r * scene.r;
	color.g = cylinder->color.g * scene.r;
	color.b = cylinder->color.b * scene.r;
	return (color);
}

void	cap_color(t_color *color)
{
	if (color->r > 255)
		color->r = 255;
	if (color->g > 255)
		color->g = 255;
	if (color->b > 255)
		color->b = 255;
}

static t_color	caluc_color(t_scene scene, t_object obj)
{
	t_color	color;

	if (obj.type == SPHERE)
		color = caluc_color_sphere(scene, (t_sphere *)(obj.conf));
	else if (obj.type == PLANE)
		color = caluc_color_plane(scene, (t_plane *)(obj.conf));
	else if (obj.type == CYLINDER)
		color = caluc_color_cylinder(scene, (t_cylinder *)(obj.conf));
	cap_color(&color);
	return (color);
}

void	phong_shading(t_scene *scene, t_object obj)
{
	double	r_a;
	double	r_d;
	double	r_s;

	r_a = ambient(0.8);
	r_d = diffuse(*scene, 1.0);
	r_s = specular(*scene, 1.0);
	scene->r = r_a + r_d + r_s;
	if (scene->r > 1)
		scene->r = 1;
	scene->tmp_color = caluc_color(*scene, obj);
}
