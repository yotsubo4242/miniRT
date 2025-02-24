/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line_each_object.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitahar <tkitahar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:26:06 by tkitahar          #+#    #+#             */
/*   Updated: 2025/02/24 14:29:03 by tkitahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

// sp [center] [diameter] [color]
t_sphere_conf	parse_sphere(const char *line)
{
	char			**split;
	t_sphere_conf	conf;

	if (!line || ft_strncmp(line, "sp", 2))
		exit_with_error(EXIT_PARSE_ERROR, "sphere: invalid type");
	split = split_space(line);
	if (array_size(split) != 4)
		exit_with_error(EXIT_PARSE_ERROR, "sphere: invalid format");
	conf.center = parse_vec3(split[1]);
	conf.radius = parse_double(split[2]) / 2;
	conf.color = parse_rgb(split[3]);
	if (conf.radius <= 0)
		exit_with_error(EXIT_FAILURE, "sphere: invalid value");
	free_array(split);
	return (conf);
}
