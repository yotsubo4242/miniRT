/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:41:09 by yuotsubo          #+#    #+#             */
/*   Updated: 2025/02/19 16:43:48 by yuotsubo         ###   ########.fr       */
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
	t_mlx_data	*mlx_data;
	t_vec3		screen;
	t_vec3		ray;
	t_vec3		obs;
	t_vec3		sphere;
	t_color		sphare_color;
	t_color		scene_color;

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
	// シーンの色
	scene_color.r = 255;
	scene_color.g = 255;
	scene_color.b = 255;
	// mlxの初期化
	mlx_data = init_mlx();
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
			a = vec_dot(ray, ray);
			b = 2 * (vec_dot(obs, ray) - vec_dot(sphere, ray));
			c = vec_dot(obs, obs) - 2 * vec_dot(sphere, obs) + vec_dot(sphere, sphere) - pow(SPHERE_RADIUS, 2);

			double D = pow(b, 2) - 4 * a * c;
			if (D < 0)
				my_mlx_pixel_put(mlx_data, x, y, convert_color_to_hex(scene_color));
			else
				phong_shading(mlx_data, x, y, D, a, b, obs, sphere, sphare_color, ray);
		}
	}
	mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->win_ptr, mlx_data->img, 0, 0);
	mlx_key_hook(mlx_data->win_ptr, my_exit, NULL);
	mlx_loop(mlx_data->mlx_ptr);
	return (0);
}
