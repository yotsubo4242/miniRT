/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   caluc_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:43:32 by yuotsubo          #+#    #+#             */
/*   Updated: 2025/03/08 13:42:44 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

t_vec3	caluc_camera_to_screen(t_scene scene)
{
	double	dist;
	t_vec3	c_2_s;

	dist = (1 / tan(((scene.camera.fov / 2) / 180) * PI)) * (WIDTH / 2);
	c_2_s = vec_mult(dist, scene.camera.orientation);
	return (c_2_s);
}

static t_vec3	caluc_esx(t_scene scene)
{
	t_vec3	esx;

	esx.x = scene.camera.orientation.z / \
			(sqrt(pow(scene.camera.orientation.x, 2) \
				+ pow(scene.camera.orientation.z, 2)));
	esx.y = 0;
	esx.z = -(scene.camera.orientation.x / \
			(sqrt(pow(scene.camera.orientation.x, 2) \
				+ pow(scene.camera.orientation.z, 2))));
	return (esx);
}

t_vec3	caluc_ray(int x, int y, t_scene scene)
{
	t_vec3	screen;
	t_vec3	esx;
	t_vec3	esy;
	t_vec3	ray;

	esx = vec_normalize(caluc_esx(scene));
	esy = vec_normalize(vec_cross(scene.camera.orientation, esx));
	screen = vec_plus(vec_mult(x - (WIDTH / 2), esx), \
						vec_mult((HEIGHT / 2) - y, esy));
	ray = vec_div(vec_plus(scene.camera_to_screen, screen), \
					vec_mag(vec_plus(scene.camera_to_screen, screen)));
	return (ray);
}
