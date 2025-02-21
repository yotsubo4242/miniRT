/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo <y.otsubo.886@ms.saitama-u.ac.j    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:41:09 by yuotsubo          #+#    #+#             */
/*   Updated: 2025/02/20 15:06:15 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	my_exit(int keycode, void *param)
{
	(void)param;
	if (keycode == 65307)
		exit(0);
	return (0);
}
//
// int	main(void)
// {
// 	t_mlx_data	*mlx_data;
// 	t_scene		scene;
//
// 	scene = init_scene();
// 	mlx_data = init_mlx();
// 	sphere(mlx_data, scene);
// 	mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->win_ptr, \
// 							mlx_data->img, 0, 0);
// 	mlx_key_hook(mlx_data->win_ptr, my_exit, NULL);
// 	mlx_loop(mlx_data->mlx_ptr);
// 	return (0);
// }
