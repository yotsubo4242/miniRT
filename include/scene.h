/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitahar <tkitahar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:23:00 by tkitahar          #+#    #+#             */
/*   Updated: 2025/02/18 21:56:21 by tkitahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include <stdbool.h>
# include <stdio.h>
# include "../libft/includes/libft.h"
# include "../src/scene/list/list.h"
# include "vector.h"

typedef double	t_radian;
typedef double	t_degree;
typedef double	t_ratio;
typedef double	t_brightness;

typedef struct s_ambient_conf
{
	t_ratio	ratio;
	t_rgb	color;
}	t_ambient_conf;

typedef struct s_camera_conf
{
	t_vec3		position;
	t_vec3		orientation;
	t_degree	fov;
}	t_camera_conf;

typedef struct s_light_conf
{
	t_vec3			position;
	t_rgb			color;
	t_brightness	brightness;
}	t_light_conf;

typedef struct s_scene
{
	t_ambient_conf	*ambient;
	t_camera_conf	*camera;
	t_light_conf	*light;
	t_list			*objects;
}	t_scene;

int		plus(int a, int b);
void	exit_with_error(int status, const char *message);
t_scene	*parse_scene(const char *path);

#endif
