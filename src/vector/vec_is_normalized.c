/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_is_vec_normalized.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:24:39 by yuotsubo          #+#    #+#             */
/*   Updated: 2025/02/19 15:27:27 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

bool	vec_is_vec_normalized(t_vec3 v)
{
	return (vec_eq(v, vec_normalize(v)));
}
