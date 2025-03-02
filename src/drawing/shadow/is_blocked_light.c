/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_blocked_light.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 12:49:59 by yuotsubo          #+#    #+#             */
/*   Updated: 2025/03/02 13:54:06 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

bool	is_blocked_light(t_scene scene, double t)
{
	double	light_dist;
	double	obj_dist;

	if (t < 0)
		return (false);
	light_dist = vec_mag(vec_minus(scene.light, scene.shadow_inter));
	obj_dist = vec_mag(vec_plus(scene.shadow_inter, vec_mult(t, scene.shadow_ray)));
	if (light_dist < obj_dist)
		return (false);
	return (true);
}
