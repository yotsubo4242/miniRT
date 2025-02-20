/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:13:14 by yuotsubo          #+#    #+#             */
/*   Updated: 2025/02/19 16:52:31 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_mlx_data	*init_mlx(void)
{
	t_mlx_data	*mlx_data;

	mlx_data = ft_calloc(sizeof(t_mlx_data), 1);
	if (mlx_data == NULL)
		return (err_init_mlx(mlx_data, FT_CALLOC));
	mlx_data->mlx_ptr = mlx_init();
	if (mlx_data->mlx_ptr == NULL)
		return (err_init_mlx(mlx_data, MLX_INIT));
	mlx_data->win_ptr = mlx_new_window(mlx_data->mlx_ptr, \
									WIDTH, HEIGHT, "miniRT");
	if (mlx_data->win_ptr == NULL)
		return (err_init_mlx(mlx_data, MLX_NEW_WINDOW));
	mlx_data->img = mlx_new_image(mlx_data->mlx_ptr, WIDTH, HEIGHT);
	if (mlx_data->img == NULL)
		return (err_init_mlx(mlx_data, MLX_NEW_IMAGE));
	mlx_data->img_addr = mlx_get_data_addr(mlx_data->img, &mlx_data->bpp, \
										&mlx_data->line_len, &mlx_data->endian);
	if (mlx_data->img_addr == NULL)
		return (err_init_mlx(mlx_data, MLX_GET_DATA_ADDR));
	return (mlx_data);
}
