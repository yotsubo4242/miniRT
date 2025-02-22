/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitahar <tkitahar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:01:18 by tkitahar          #+#    #+#             */
/*   Updated: 2025/02/19 20:42:41 by tkitahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

// A [ratio] [color]
t_ambient_conf	parse_ambient(const char *line)
{
	char			**split;
	double			ratio;
	t_ambient_conf	conf;

	if (!line || *line != 'A')
		exit_with_error(EXIT_PARSE_ERROR, "ambient: invalid type");
	ft_bzero(&conf, sizeof(conf));
	split = split_space(line);
	if (array_size(split) != 3)
		exit_with_error(EXIT_PARSE_ERROR, "ambient: invalid format");
	ratio = parse_double(split[1]);
	if (!is_in_range_double(ratio, 0, 1))
		exit_with_error(EXIT_PARSE_ERROR, "ambient: invalid light ratio");
	conf.ratio = ratio;
	conf.color = parse_rgb(split[2]);
	free_array(split);
	return (conf);
}

// C [position] [orientation] [fov]
t_camera_conf	parse_camera(const char *line)
{
	char			**split;
	unsigned int	fov;
	t_vec3			orient;
	t_camera_conf	conf;

	if (!line || *line != 'C')
		exit_with_error(EXIT_PARSE_ERROR, "camera: invalid type");
	ft_bzero(&conf, sizeof(conf));
	split = split_space(line);
	if (array_size(split) != 4)
		exit_with_error(EXIT_PARSE_ERROR, "camera : invalid format");
	orient = parse_vec3(split[2]);
	fov = parse_uint(split[3]);
	if (!vec_is_normalized(orient) || !is_in_range_uint(fov, 0, 180))
		exit_with_error(EXIT_FAILURE, "camera: invalid value");
	conf.position = parse_vec3(split[1]);
	conf.orientation = orient;
	conf.fov = fov;
	free_array(split);
	return (conf);
}
