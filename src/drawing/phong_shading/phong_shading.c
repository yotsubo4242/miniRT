/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_shading.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:12:42 by yuotsubo          #+#    #+#             */
/*   Updated: 2025/02/23 19:14:17 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

double	phong_shading(t_mlx_data *mlx_data, t_point pt, t_scene scene)
{
	double	r_a;
	double	r_d;
	double	r_s;
	double	r;

	r_a = ambient(0.8);
	r_d = diffuse(scene, 1.0);
	r_s = specular(scene, 1.0);
	r = r_a + r_d + r_s;
	return (r);
}
