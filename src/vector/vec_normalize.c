/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_vec_normalize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:34:59 by yuotsubo          #+#    #+#             */
/*   Updated: 2025/02/19 15:27:52 by yuotsubo         ###   ########.fr       */
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
