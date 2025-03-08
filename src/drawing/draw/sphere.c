/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:48:52 by yuotsubo          #+#    #+#             */
/*   Updated: 2025/03/06 13:57:54 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

static void	caluc_qe(t_solve_quadratic_equation *qe, \
						t_scene scene, t_sphere_conf sphere)
{
	qe->a = vec_dot(scene.ray, scene.ray);
	qe->b = 2 * (vec_dot(scene.camera.position, scene.ray) \
				- vec_dot(sphere.center, scene.ray));
	qe->c = vec_dot(scene.camera.position, scene.camera.position) \
				- 2 * vec_dot(sphere.center, scene.camera.position) \
				+ vec_dot(sphere.center, sphere.center) \
				- pow(sphere.radius, 2);
	qe->d = pow(qe->b, 2) - 4 * qe->a * qe->c;
}

bool	sp_get_t(t_solve_quadratic_equation qe, double *t)
{
	double	t1;
	double	t2;

	if (qe.d < 0)
		return (false);
	if (qe.d == 0)
		*t = -qe.b / (2 * qe.a);
	else if (qe.d > 0)
	{
		t1 = (-qe.b + sqrt(qe.d)) / (2 * qe.a);
		t2 = (-qe.b - sqrt(qe.d)) / (2 * qe.a);
		if (t1 < 0 && t2 < 0)
			return (false);
		if (t1 < 0)
			*t = t2;
		else if (t2 < 0)
			*t = t1;
		else if (t1 < t2)
			*t = t1;
		else if (t2 < t1)
			*t = t2;
	}
	return (true);
}

void	sphere(t_scene *scene, t_sphere_conf *sphere)
{
	t_solve_quadratic_equation	qe;

	caluc_qe(&qe, *scene, *sphere);
	if (!sp_get_t(qe, &(scene->tmp_t)))
	{
		scene->tmp_t = -1;
		return ;
	}
	else
	{
		scene->inter = get_inter(scene->tmp_t, *scene);
		scene->n = vec_normalize(\
				vec_minus(scene->inter, sphere->center));
		phong_shading(scene, (t_object){OBJ_SPHERE, sphere});
	}
}
