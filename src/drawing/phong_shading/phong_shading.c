/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_shading.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:12:42 by yuotsubo          #+#    #+#             */
/*   Updated: 2025/03/07 14:43:37 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

static t_radiance	combine_radiance(t_radiance r_a, \
									t_radiance r_d, t_radiance r_s)
{
	t_radiance	r;

	r.r_radiance = r_a.r_radiance + r_d.r_radiance + r_s.r_radiance;
	if (r.r_radiance > 1)
		r.r_radiance = 1;
	r.g_radiance = r_a.g_radiance + r_d.g_radiance + r_s.g_radiance;
	if (r.g_radiance > 1)
		r.g_radiance = 1;
	r.b_radiance = r_a.b_radiance + r_d.b_radiance + r_s.b_radiance;
	if (r.b_radiance > 1)
		r.b_radiance = 1;
	return (r);
}

void	phong_shading(t_scene *scene, t_object obj)
{
	t_radiance	r_a;
	t_radiance	r_d;
	t_radiance	r_s;

	r_a = ambient(scene->ambient);
	if (is_shadow(*scene))
		scene->r = r_a;
	else
	{
		r_d = diffuse(*scene, 1.0);
		r_s = specular(*scene, 1.0);
		scene->r = combine_radiance(r_a, r_d, r_s);
	}
	scene->tmp_color = caluc_color(*scene, obj);
}
