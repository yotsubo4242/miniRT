/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitahar <tkitahar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 20:34:58 by tkitahar          #+#    #+#             */
/*   Updated: 2025/02/18 21:50:26 by tkitahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include <fcntl.h>

t_scene	*parse_scene(const char *path)
{
	int		fd;
	t_scene	*scene;

	scene = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		exit_with_error(EXIT_FAILURE, "failed to read file");
	return (scene);
}
