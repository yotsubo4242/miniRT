/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 12:38:30 by yuotsubo          #+#    #+#             */
/*   Updated: 2025/03/02 14:00:19 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	caluc_qe(t_solve_quadratic_equation *qe, \
						t_scene scene, t_sphere sphere)
{
	qe->a = vec_dot(scene.shadow_ray, scene.shadow_ray);
	qe->b = 2 * (vec_dot(scene.shadow_inter, scene.shadow_ray) \
				- vec_dot(sphere.center, scene.shadow_ray));
	qe->c = vec_dot(scene.shadow_inter, scene.shadow_inter) \
				- 2 * vec_dot(sphere.center, scene.shadow_inter) \
				+ vec_dot(sphere.center, sphere.center) \
				- pow(SPHERE_RADIUS, 2);
	qe->d = pow(qe->b, 2) - 4 * qe->a * qe->c;
}

bool	shadow_sphere(t_scene scene, t_sphere sphere)
{
	t_solve_quadratic_equation	qe;
	double						t;
	t_vec3						l;

	l = vec_normalize(vec_minus(scene.light, scene.inter));
	scene.shadow_inter = vec_plus(scene.inter, vec_mult(EPSILON, l));
	scene.shadow_ray = l;
	caluc_qe(&qe, scene, sphere);
	if (!sp_get_t(qe, &t))
		return (false);
	return (is_blocked_light(scene, t));
}
