/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:41:09 by yuotsubo          #+#    #+#             */
/*   Updated: 2025/02/06 13:48:13 by yuotsubo         ###   ########.fr       */
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

int main(void)
{
	t_data	data;

	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, 500, 500, "Hello World!");
	data.img = mlx_new_image(data.mlx_ptr, 500, 500);
	data.img_addr = mlx_get_data_addr(data.img, &data.bpp, &data.line_len, &data.endian);
	for (int i = 200; i < 300; i++)
	{
		for (int j = 200; j < 300; j++)
		{
			my_mlx_pixel_put(&data, i, j, 0x00FFFFFF);
		}
	}
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img, 0, 0);
	mlx_key_hook(data.win_ptr, my_exit, NULL);
	mlx_loop(data.mlx_ptr);
	return (0);
}
