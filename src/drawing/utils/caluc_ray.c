/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   caluc_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:43:32 by yuotsubo          #+#    #+#             */
/*   Updated: 2025/03/06 13:46:38 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

t_vec3	caluc_ray(t_vec3 screen, t_camera_conf camera)
{
	t_vec3	ray;

	ray.x = screen.x - camera.position.x;
	ray.y = screen.y - camera.position.y;
	ray.z = screen.z - camera.position.z;
	return (ray);
}
