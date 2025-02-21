/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_eq.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo <y.otsubo.886@ms.saitama-u.ac.j    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:20:14 by yuotsubo          #+#    #+#             */
/*   Updated: 2025/02/21 14:34:16 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

bool	vec_eq(t_vec3 a, t_vec3 b)
{
	if (a.x != b.x)
		return (false);
	if (a.y != b.y)
		return (false);
	if (a.z != b.z)
		return (false);
	return (true);
}
