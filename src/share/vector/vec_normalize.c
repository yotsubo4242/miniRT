/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_normalize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo <y.otsubo.886@ms.saitama-u.ac.j    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:34:59 by yuotsubo          #+#    #+#             */
/*   Updated: 2025/02/20 15:16:30 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_vec3	vec_normalize(t_vec3 a)
{
	double	magnitude;

	magnitude = vec_mag(a);
	a.x /= magnitude;
	a.y /= magnitude;
	a.z /= magnitude;
	return (a);
}
