/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitahar <tkitahar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 22:01:19 by tkitahar          #+#    #+#             */
/*   Updated: 2025/02/18 22:01:36 by tkitahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

t_scene	*new_scene(void)
{
	t_scene	*config;

	config = ft_calloc(1, sizeof(t_scene));
	ft_bzero(&config->ambient, sizeof(t_ambient_conf));
	ft_bzero(&config->light, sizeof(t_light_conf));
	ft_bzero(&config->camera, sizeof(t_camera_conf));
	config->objects = create_list();
	return (config);
}
