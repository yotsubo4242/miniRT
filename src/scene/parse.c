/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitahar <tkitahar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 20:34:58 by tkitahar          #+#    #+#             */
/*   Updated: 2025/02/19 16:03:47 by tkitahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

static t_scene	*parse_line(t_scene *scene, t_scene_count *scene_count, \
					char *line)
{
	if (*line == 'A')
	{
		scene->ambient = parse_ambient(line);
		++(scene_count->ambient);
	}
	else if (*line == 'C')
	{
		scene->camera = parse_camera(line);
		++(scene_count->camera);
	}
	else if (*line == 'L')
	{
		scene->light = parse_light(line);
		++(scene_count->light);
	}
	else
		push_back_list(scene->objects, parse_object(line));
	return (scene);
}

static void	validate_scene_count(t_scene_count scene_count)
{
	if (scene_count.ambient != 1)
		exit_with_error(EXIT_PARSE_ERROR, "ambient: invalid count");
	if (scene_count.camera != 1)
		exit_with_error(EXIT_PARSE_ERROR, "camera: invalid count");
	if (scene_count.light != 1)
		exit_with_error(EXIT_PARSE_ERROR, "light: invalid count");
}

t_scene	*parse_scene(const char *path)
{
	int				fd;
	t_scene			*scene;
	char			*line;
	t_scene_count	scene_count;

	ft_bzero(&scene_count, sizeof(t_scene_count));
	fd = open(path, O_RDONLY);
	if (fd == -1)
		exit_with_error(EXIT_FAILURE, "failed to read file");
	scene = new_scene();
	while (true)
	{
		errno = 0;
		line = get_next_line(fd);
		if (errno != 0)
			exit_with_error(EXIT_FAILURE, "failed to parse");
		if (!line)
			break ;
		if (*line != '\n')
			parse_line(scene, &scene_count, line);
		free(line);
	}
	validate_scene_count(scene_count);
	return (scene);
}
