/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 17:26:10 by yuotsubo          #+#    #+#             */
/*   Updated: 2025/02/26 15:22:56 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	caluc_qe(t_solve_quadratic_equation *qe, t_scene scene, \
					t_cylinder cylinder)
{
	t_vec3	dxn;

	dxn = vec_cross(scene.ray, cylinder.axis);
	qe->a = vec_dot(dxn, dxn);
	qe->b = 2 * vec_dot(\
					dxn, vec_cross(\
							vec_minus(scene.camera, cylinder.center), \
							cylinder.axis));
	qe->c = vec_dot(vec_cross(vec_minus(scene.camera, cylinder.center), \
							cylinder.axis), \
					vec_cross(vec_minus(scene.camera, cylinder.center), \
							cylinder.axis)) \
			- pow(cylinder.diameter, 2);
	qe->d = pow(qe->b, 2) - 4 * qe->a * qe->c;
}

static void	cy_get_ts(t_solve_quadratic_equation qe, double *t1, double *t2)
{
	if (qe.d == 0)
		*t1 = -qe.b / (2 * qe.a);
	else if (qe.d > 0)
	{
		*t1 = (-qe.b - sqrt(qe.d)) / (2 * qe.a);
		*t2 = (-qe.b + sqrt(qe.d)) / (2 * qe.a);
	}
}

static t_vec3	caluc_n(t_vec3 p, t_cylinder cylinder, double tmp)
{
	t_vec3	n;

	n = vec_normalize(vec_minus(vec_minus(p, cylinder.center), \
					vec_mult(tmp, cylinder.axis)));
	return (n);
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
	p = vec_plus(scene.camera, vec_mult(t1, scene.ray));
	tmp = vec_dot(vec_minus(p, cylinder.center), cylinder.axis);
	if (tmp >= 0 && tmp <= cylinder.height)
	{
		n = caluc_n(p, cylinder, tmp);
		*t = t1;
		return (vec_dup(vec_div(n, vec_mag(n))));
	}
	p = vec_plus(scene.camera, vec_mult(t2, scene.ray));
	tmp = vec_dot(vec_minus(p, cylinder.center), cylinder.axis);
	if (tmp >= 0 && tmp <= cylinder.height)
	{
		n = caluc_n(p, cylinder, tmp);
		*t = t2;
		return (vec_dup(vec_div(n, vec_mag(n))));
	}
	return (NULL);
}

void	cylinder(t_scene *scene, t_cylinder *cylinder)
{
	t_solve_quadratic_equation	qe;
	t_vec3						dxn;
	t_vec3						*n;

	caluc_qe(&qe, *scene, *cylinder);
	dxn = vec_cross(scene->ray, cylinder->axis);
	n = cy_make_n(qe, *scene, *cylinder, &(scene->tmp_t));
	if (n == NULL)
	{
		scene->tmp_t = -1;
		return ;
	}
	scene->inter = get_inter(scene->tmp_t, *scene);
	scene->n = *n;
	if (vec_dot(dxn, dxn) != 0 && qe.d >= 0)
		phong_shading(scene, (t_object){CYLINDER, cylinder});
	free(n);
}
