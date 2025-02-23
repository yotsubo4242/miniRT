/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cy_diffuse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 14:34:54 by yuotsubo          #+#    #+#             */
/*   Updated: 2025/02/23 17:31:54 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

double	cy_diffuse(double t, t_vec3 n, t_scene scene, double ratio)
{
	t_vec3	l;
	double	nl;
	double	r_d;

	l = vec_normalize(vec_minus(scene.light, \
					vec_plus(scene.camera, vec_mult(t, scene.ray))));
	nl = vec_dot(n, l);
	if (nl < 0)
		nl = vec_dot(vec_rev(n), l);
	r_d = vec_dot(l, n) * KD * ratio;
	if (r_d < 0)
		r_d = 0.0;
	return (r_d);
}
