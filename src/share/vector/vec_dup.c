/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_dup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 17:18:10 by yuotsubo          #+#    #+#             */
/*   Updated: 2025/02/23 17:19:37 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vec3	*vec_dup(t_vec3 a)
{
	t_vec3	*res;

	res = (t_vec3 *)ft_calloc(sizeof(t_vec3), 1);
	if (res == NULL)
		return (NULL);
	res->x = a.x;
	res->y = a.y;
	res->z = a.z;
	return (res);
}
