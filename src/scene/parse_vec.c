/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_vec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitahar <tkitahar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:34:09 by tkitahar          #+#    #+#             */
/*   Updated: 2025/02/20 16:56:36 by tkitahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

static size_t	count_char(const char *str, char c)
{
	size_t	count;

	count = 0;
	while (*str)
	{
		if (*str == c)
			count++;
		str++;
	}
	return (count);
}

t_rgb	parse_rgb(const char *str)
{
	char	**split;
	t_rgb	rgb;

	if (count_char(str, ',') != 2)
		exit_with_error(EXIT_PARSE_ERROR, "parse_rgb: invalid format");
	split = ft_split(str, ',');
	if (split == NULL || array_size(split) != 3)
		exit_with_error(EXIT_PARSE_ERROR, "parse_rgb: invalid format");
	rgb = double_to_vec3(parse_uint(split[0]), \
					parse_uint(split[1]), \
					parse_uint(split[2]));
	if (rgb_get_r(rgb) > 255 || rgb_get_g(rgb) > 255 || rgb_get_b(rgb) > 255)
		exit_with_error(EXIT_PARSE_ERROR,
			"parse_rgb: value out of range (0-255)");
	return (rgb);
}
