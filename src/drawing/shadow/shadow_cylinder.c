/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 14:09:26 by yuotsubo          #+#    #+#             */
/*   Updated: 2025/03/02 14:44:22 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	caluc_qe(t_solve_quadratic_equation *qe, t_scene scene, \
					t_cylinder cylinder)
{
	t_vec3	dxn;

	dxn = vec_cross(scene.shadow_ray, cylinder.axis);
	qe->a = vec_dot(dxn, dxn);
	qe->b = 2 * vec_dot(\
					dxn, vec_cross(\
							vec_minus(scene.shadow_inter, cylinder.center), \
							cylinder.axis));
	qe->c = vec_dot(vec_cross(vec_minus(scene.shadow_inter, cylinder.center), \
							cylinder.axis), \
					vec_cross(vec_minus(scene.shadow_inter, cylinder.center), \
							cylinder.axis)) \
			- pow(cylinder.diameter, 2);
	qe->d = pow(qe->b, 2) - 4 * qe->a * qe->c;
}

static t_vec3	*cy_make_n(t_solve_quadratic_equation qe, \
						t_scene scene, t_cylinder cylinder, double *t)
{
	t_vec3	p;
	t_vec3	n;
	double	t1;
	double	t2;
	double	tmp;

	cy_get_ts(qe, &t1, &t2);
	p = vec_plus(scene.shadow_inter, vec_mult(t1, scene.shadow_ray));
	tmp = vec_dot(vec_minus(p, cylinder.center), cylinder.axis);
	if (tmp >= 0 && tmp <= cylinder.height)
	{
		n = caluc_n(p, cylinder, tmp);
		*t = t1;
		return (vec_dup(vec_div(n, vec_mag(n))));
	}
	p = vec_plus(scene.shadow_inter, vec_mult(t2, scene.shadow_ray));
	tmp = vec_dot(vec_minus(p, cylinder.center), cylinder.axis);
	if (tmp >= 0 && tmp <= cylinder.height)
	{
		n = caluc_n(p, cylinder, tmp);
		*t = t2;
		return (vec_dup(vec_div(n, vec_mag(n))));
	}
	return (NULL);
}

bool	shadow_cylinder(t_scene scene, t_cylinder cylinder)
{
	t_solve_quadratic_equation	qe;
	t_vec3						dxn;
	t_vec3						*n;
	double						t;

	scene.shadow_ray = vec_normalize(vec_minus(scene.light, scene.inter));
	scene.shadow_inter = vec_plus(scene.inter, vec_mult(EPSILON, scene.shadow_ray));
	caluc_qe(&qe, scene, cylinder);
	dxn = vec_cross(scene.shadow_ray, cylinder.axis);
	n = cy_make_n(qe, scene, cylinder, &t);
	if (n == NULL)
		return (false);
	free(n);
	if (vec_dot(dxn, dxn) == 0 || qe.d < 0)
		return (false);
	return (is_blocked_light(scene, t));
}
