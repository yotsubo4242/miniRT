/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_inter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 18:49:01 by yuotsubo          #+#    #+#             */
/*   Updated: 2025/03/06 13:58:16 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

t_vec3	get_inter(double t, t_scene scene)
{
	t_vec3	inter;

	inter.x = scene.camera.position.x + t * scene.ray.x;
	inter.y = scene.camera.position.y + t * scene.ray.y;
	inter.z = scene.camera.position.z + t * scene.ray.z;
	return (inter);
}
