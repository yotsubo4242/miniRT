/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo <y.otsubo.886@ms.saitama-u.ac.j    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:56:22 by yotsubo           #+#    #+#             */
/*   Updated: 2025/02/21 16:07:53 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	plane(t_mlx_data *mlx_data, t_scene scene)
{
	t_point		pt;
	double		dn;

	pt.y = 0;
	while (pt.y < HEIGHT)
	{
		pt.x = 0;
		while (pt.x < WIDTH)
		{
			scene.screen = caluc_screen_point(pt.x, pt.y);
			scene.ray = caluc_ray(scene.screen);
			dn = vec_dot(scene.ray, scene.plane_n);
			if (dn == 0)
				printf("(%d, %d)\n", pt.x, pt.y);
			if (dn == 0)
				my_mlx_pixel_put(mlx_data, pt.x, pt.y, \
					convert_color_to_hex(scene.scene_color));
			else
				pl_phong_shading(mlx_data, pt, scene);
			(pt.x)++;
		}
		(pt.y)++;
	}
}
