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
	t_ambient_conf	ambient_conf;

	if (!line || *line != 'A')
		exit_with_error(EXIT_PARSE_ERROR, "ambient: invalid type");
	(void) ratio;
	ft_bzero(&ambient_conf, sizeof(ambient_conf));
	split = split_space(line);
	if (array_size(split) != 3)
		exit_with_error(EXIT_PARSE_ERROR, "ambient: invalid format");
	ratio = parse_double(split[1]);
	if (!is_in_range_double(ratio, 0, 1))
		exit_with_error(EXIT_PARSE_ERROR, "ambient: invalid light ratio");
	free_array(split);
	return (ambient_conf);
}
