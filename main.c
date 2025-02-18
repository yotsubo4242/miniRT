/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:41:09 by yuotsubo          #+#    #+#             */
/*   Updated: 2025/02/18 14:14:37 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

#define WIDTH 1000
#define HEIGHT 1000
#define OBSRV_X 0
#define OBSRV_Y 0
#define OBSRV_Z -2500
#define SPHERE_X 0
#define SPHERE_Y 0
#define SPHERE_Z 2500
#define SPHERE_RADIUS 500

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
	t_vec3	screen;
	t_vec3	ray;
	t_vec3	obs;
	t_color	sphare_color;
	t_vec3	sphere;

	// 観測者の位置ベクトル
	obs.x = OBSRV_X;
	obs.y = OBSRV_Y;
	obs.z = OBSRV_Z;
	// 球の中心の位置ベクトル
	sphere.x = SPHERE_X;
	sphere.y = SPHERE_Y;
	sphere.z = SPHERE_Z;
	// 球の色
	sphare_color.r = 255;
	sphare_color.g = 0;
	sphare_color.b = 0;
	// mlxの初期化
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, WIDTH, HEIGHT, "Hello World!");
	data.img = mlx_new_image(data.mlx_ptr, WIDTH, HEIGHT);
	data.img_addr = mlx_get_data_addr(data.img, &data.bpp, &data.line_len, &data.endian);
	// 描画の計算.
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			// スクリーンの中心が原点となるように座標を変換.
			screen.x = x - WIDTH / 2;
			screen.y = HEIGHT / 2 - y;
			screen.z = 0;

			// 視点からスクリーン上の点へのベクトルを計算.
			ray.x = screen.x - OBSRV_X;
			ray.y = screen.y - OBSRV_Y;
			ray.z = screen.z - OBSRV_Z;

			double	a, b, c;
			a = dot(ray, ray);
			b = 2 * (dot(obs, ray) - dot(sphere, ray));
			c = dot(obs, obs) - 2 * dot(sphere, obs) + dot(sphere, sphere) - pow(SPHERE_RADIUS, 2);

			double D = pow(b, 2) - 4 * a * c;
			if (D < 0)
				my_mlx_pixel_put(&data, x, y, 0x000000);
			else
				my_mlx_pixel_put(&data, x, y, convert_color_to_hex(sphare_color));
		}
	}
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img, 0, 0);
	mlx_key_hook(data.win_ptr, my_exit, NULL);
	mlx_loop(data.mlx_ptr);
	return (0);
}
