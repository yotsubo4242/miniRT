/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   caluc_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:43:32 by yuotsubo          #+#    #+#             */
/*   Updated: 2025/02/19 17:44:42 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_vec3	caluc_ray(t_vec3 screen)
{
	t_vec3	ray;

	ray.x = screen.x - OBSRV_X;
	ray.y = screen.y - OBSRV_Y;
	ray.z = screen.z - OBSRV_Z;
	return (ray);
}