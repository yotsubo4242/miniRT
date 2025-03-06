/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:25:11 by tkitahar          #+#    #+#             */
/*   Updated: 2025/03/06 13:39:57 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

static bool	is_rt_file(char *filename)
{
	const size_t	len = ft_strlen(filename);

	if (len < 4)
		return (false);
	return (ft_strcmp(filename + len - 3, ".rt") == 0);
}

static int	my_exit(int keycode, void *param)
{
	t_scene	*scene;

	scene = (t_scene *)param;
	if (keycode == 65307)
	{
		free_config(scene);
		exit(0);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_scene		*scene;
	t_mlx_data	*mlx_data;

	if (argc != 2)
	{
		printf("Usage: %s <scene_file>\n", argv[0]);
		return (EXIT_FAILURE);
	}
	if (!is_rt_file(argv[1]))
	{
		printf("Error: %s is not a .rt file\n", argv[1]);
		return (EXIT_FAILURE);
	}
	scene = parse_scene(argv[1]);
	mlx_data = init_mlx();
	draw_image(mlx_data, *scene);
	mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->win_ptr, \
							mlx_data->img, 0, 0);
	mlx_key_hook(mlx_data->win_ptr, my_exit, scene);
	mlx_loop(mlx_data->mlx_ptr);
}
