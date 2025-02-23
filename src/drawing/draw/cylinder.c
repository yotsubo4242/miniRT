/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 23:26:39 by yotsubo           #+#    #+#             */
/*   Updated: 2025/02/23 17:31:20 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	cylinder(t_mlx_data *mlx_data, t_scene scene)
{
	t_point						pt;

	pt.y = 0;
	while (pt.y < HEIGHT)
	{
		pt.x = 0;
		while (pt.x < WIDTH)
		{
			caluc_cylinder(scene, pt, mlx_data);
			(pt.x)++;
		}
		(pt.y)++;
	}
}
