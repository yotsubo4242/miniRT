/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_eq.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:20:14 by yuotsubo          #+#    #+#             */
/*   Updated: 2025/02/19 15:26:47 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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
