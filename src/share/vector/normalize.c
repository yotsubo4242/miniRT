/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:34:59 by yuotsubo          #+#    #+#             */
/*   Updated: 2025/02/18 14:35:09 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_vec3	normalize(t_vec3 a)
{
	double	magnitude;

	magnitude = mag(a);
	a.x /= magnitude;
	a.y /= magnitude;
	a.z /= magnitude;
	return (a);
}
