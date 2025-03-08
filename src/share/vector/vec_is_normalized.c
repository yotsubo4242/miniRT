/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_is_normalized.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo <y.otsubo.886@ms.saitama-u.ac.j    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:16:41 by yotsubo           #+#    #+#             */
/*   Updated: 2025/02/21 14:34:22 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

bool	vec_is_normalized(t_vec3 v)
{
	return (vec_eq(v, vec_normalize(v)));
}
