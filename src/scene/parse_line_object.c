/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line_object.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitahar <tkitahar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:48:23 by tkitahar          #+#    #+#             */
/*   Updated: 2025/02/24 14:17:49 by tkitahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

static void	init_object(t_object *object, t_object_type type, size_t size)
{
	object->type = type;
	object->conf = ft_calloc(1, size);
}

// pl, cy incoming
static void	parse_object_conf(t_object *object, const char *line)
{
	if (!ft_strncmp(line, "sp", 2))
	{
		init_object(object, OBJ_SPHERE, sizeof(t_sphere_conf));
		*(t_sphere_conf *)object->conf = parse_sphere(line);
	}
	if (!ft_strncmp(line, "pl", 2))
	{
		init_object(object, OBJ_PLANE, sizeof(t_plane_conf));
		*(t_plane_conf *)object->conf = parse_plane(line);
	}
	else
		exit_with_error(EXIT_PARSE_ERROR, "invalid object type");
}

t_object	*parse_object(const char *line)
{
	t_object	*object;

	object = ft_calloc(1, sizeof(t_object));
	parse_object_conf(object, line);
	return (object);
}
