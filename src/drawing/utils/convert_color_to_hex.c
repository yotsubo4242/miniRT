/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_color_to_hex.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo <y.otsubo.886@ms.saitama-u.ac.j    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:12:39 by yuotsubo          #+#    #+#             */
/*   Updated: 2025/02/20 15:15:08 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	convert_color_to_hex(t_color color)
{
	int	rgb;

	rgb = 0;
	rgb += color.r << 16;
	rgb += color.g << 8;
	rgb += color.b;
	return (rgb);
}
