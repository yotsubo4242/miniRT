/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mag.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:39:06 by yuotsubo          #+#    #+#             */
/*   Updated: 2025/02/06 17:32:16 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

double	mag(t_vec3 a)
{
	return (sqrt(dot(a, a)));
}