/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destructor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitahar <tkitahar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 20:39:09 by tkitahar          #+#    #+#             */
/*   Updated: 2025/02/19 20:39:21 by tkitahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

void	free_object(void *data)
{
	t_object	*obj;

	obj = data;
	free(obj->conf);
	free(obj);
}

void	free_config(t_scene *config)
{
	destroy_list(config->objects, free_object);
	free(config);
}
