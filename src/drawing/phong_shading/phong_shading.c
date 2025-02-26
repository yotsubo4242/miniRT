/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_shading.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:12:42 by yuotsubo          #+#    #+#             */
/*   Updated: 2025/02/26 15:38:44 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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
