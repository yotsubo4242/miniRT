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

// pl [point] [normal] [color]
t_plane_conf	parse_plane(const char *line)
{
	char				**split;
	t_plane_conf		conf;

	if (!line || ft_strncmp(line, "pl", 2))
		exit_with_error(EXIT_PARSE_ERROR, "plane: invalid type");
	split = split_space(line);
	if (array_size(split) != 4)
		exit_with_error(EXIT_PARSE_ERROR, "plane: invalid format");
	conf.point = parse_vec3(split[1]);
	conf.normal = parse_vec3(split[2]);
	conf.color = parse_rgb(split[3]);
	if (!vec_is_normalized(conf.normal))
		exit_with_error(EXIT_PARSE_ERROR, "plane: invalid value");
	free_array(split);
	return (conf);
}

// cy [center] [axis] [diameter] [height] [color]
t_cylinder_conf	parse_cylinder(const char *line)
{
	char			**split;
	t_cylinder_conf	conf;

	if (!line || ft_strncmp(line, "cy", 2))
		exit_with_error(EXIT_PARSE_ERROR, "cylinder: invalid type");
	split = split_space(line);
	if (array_size(split) != 6)
		exit_with_error(EXIT_PARSE_ERROR, "cylinder: invalid format");
	conf.center = parse_vec3(split[1]);
	conf.axis = parse_vec3(split[2]);
	conf.radius = parse_double(split[3]) / 2;
	conf.height = parse_double(split[4]);
	conf.color = parse_rgb(split[5]);
	if (!vec_is_normalized(conf.axis) || conf.radius <= 0 || conf.height <= 0)
		exit_with_error(EXIT_FAILURE, "cylinder: invalid value");
	free_array(split);
	return (conf);
}
