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

#include "scene.h"

double	rgb_get_r(t_color a)
{
	return (a.r);
}

double	rgb_get_g(t_color a)
{
	return (a.g);
}

double	rgb_get_b(t_color a)
{
	return (a.b);
}
