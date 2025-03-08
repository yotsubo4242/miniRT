/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_color_to_hex.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:12:39 by yuotsubo          #+#    #+#             */
/*   Updated: 2025/03/06 13:44:28 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

int	convert_color_to_hex(t_color color)
{
	int	rgb;

	rgb = 0;
	rgb += color.r << 16;
	rgb += color.g << 8;
	rgb += color.b;
	return (rgb);
}
