/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitahar <tkitahar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:04:00 by tkitahar          #+#    #+#             */
/*   Updated: 2025/02/20 17:04:33 by tkitahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

double	rgb_get_r(t_rgb a)
{
	return (a.x);
}

double	rgb_get_g(t_rgb a)
{
	return (a.y);
}

double	rgb_get_b(t_rgb a)
{
	return (a.z);
}
