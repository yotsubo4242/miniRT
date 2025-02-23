/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:41:09 by yuotsubo          #+#    #+#             */
/*   Updated: 2025/02/23 16:45:31 by yuotsubo         ###   ########.fr       */
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

int	main(void)
{
	t_mlx_data	*mlx_data;
	t_scene		scene;

	scene = init_scene();
	mlx_data = init_mlx();
	cylinder(mlx_data, scene);
	mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->win_ptr, \
							mlx_data->img, 0, 0);
	mlx_key_hook(mlx_data->win_ptr, my_exit, NULL);
	mlx_loop(mlx_data->mlx_ptr);
	return (0);
}
