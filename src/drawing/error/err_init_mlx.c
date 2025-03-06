/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_init_mlx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:24:53 by yuotsubo          #+#    #+#             */
/*   Updated: 2025/03/06 13:44:28 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

void	*err_init_mlx(t_mlx_data *mlx_data, t_init_mlx_err function)
{
	if (function == FT_CALLOC)
		return (NULL);
	if (function == MLX_NEW_WINDOW)
	{
		mlx_destroy_display(mlx_data->mlx_ptr);
	}
	else if (function == MLX_NEW_IMAGE)
	{
		mlx_destroy_window(mlx_data->mlx_ptr, mlx_data->win_ptr);
		mlx_destroy_display(mlx_data->mlx_ptr);
	}
	else if (function == MLX_GET_DATA_ADDR)
	{
		mlx_destroy_image(mlx_data->mlx_ptr, mlx_data->img);
		mlx_destroy_window(mlx_data->mlx_ptr, mlx_data->win_ptr);
		mlx_destroy_display(mlx_data->mlx_ptr);
	}
	free(mlx_data);
	return (NULL);
}
