/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 12:55:22 by yuotsubo          #+#    #+#             */
/*   Updated: 2025/03/07 14:36:28 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

t_radiance	ambient(t_ambient_conf ambient)
{
	t_radiance	r_a;

	r_a.r_radiance = ambient.ratio * KA * (ambient.color.r / 255);
	r_a.g_radiance = ambient.ratio * KA * (ambient.color.g / 255);
	r_a.b_radiance = ambient.ratio * KA * (ambient.color.b / 255);
	return (r_a);
}
