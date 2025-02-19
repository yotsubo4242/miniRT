/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:41:09 by yuotsubo          #+#    #+#             */
/*   Updated: 2025/02/19 17:07:55 by yuotsubo         ###   ########.fr       */
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
	t_scene		scene;

	// 観測者の位置ベクトル
	scene.camera.x = OBSRV_X;
	scene.camera.y = OBSRV_Y;
	scene.camera.z = OBSRV_Z;
	// 球の中心の位置ベクトル
	scene.sphere.x = SPHERE_X;
	scene.sphere.y = SPHERE_Y;
	scene.sphere.z = SPHERE_Z;
	// 球の色
	scene.sphere_color.r = 255;
	scene.sphere_color.g = 0;
	scene.sphere_color.b = 0;
	// シーンの色
	scene.scene_color.r = 255;
	scene.scene_color.g = 255;
	scene.scene_color.b = 255;
	// mlxの初期化
	mlx_data = init_mlx();
	// 描画の計算.
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			// スクリーンの中心が原点となるように座標を変換.
			scene.screen.x = x - WIDTH / 2;
			scene.screen.y = HEIGHT / 2 - y;
			scene.screen.z = 0;

			// 視点からスクリーン上の点へのベクトルを計算.
			scene.ray.x = scene.screen.x - OBSRV_X;
			scene.ray.y = scene.screen.y - OBSRV_Y;
			scene.ray.z = scene.screen.z - OBSRV_Z;

			double	a, b, c;
			a = vec_dot(scene.ray, scene.ray);
			b = 2 * (vec_dot(scene.camera, scene.ray) - vec_dot(scene.sphere, scene.ray));
			c = vec_dot(scene.camera, scene.camera) - 2 * vec_dot(scene.sphere, scene.camera) + vec_dot(scene.sphere, scene.sphere) - pow(SPHERE_RADIUS, 2);

			double D = pow(b, 2) - 4 * a * c;
			if (D < 0)
				my_mlx_pixel_put(mlx_data, x, y, convert_color_to_hex(scene.scene_color));
			else
				phong_shading(mlx_data, x, y, D, a, b, scene.camera, scene.sphere, scene.sphere_color, scene.ray);
		}
	}
	mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->win_ptr, mlx_data->img, 0, 0);
	mlx_key_hook(mlx_data->win_ptr, my_exit, NULL);
	mlx_loop(mlx_data->mlx_ptr);
	return (0);
}
