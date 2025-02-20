/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitahar <tkitahar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:25:11 by tkitahar          #+#    #+#             */
/*   Updated: 2025/02/18 22:05:00 by tkitahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

static bool	is_rt_file(char *filename)
{
	const size_t	len = ft_strlen(filename);

	if (len < 4)
		return (false);
	return (ft_strcmp(filename + len - 3, ".rt") == 0);
}

int	main(int argc, char **argv)
{
	t_scene	*scene;

	if (argc != 2)
	{
		printf("Usage: %s <scene_file>\n", argv[0]);
		return (EXIT_FAILURE);
	}
	if (!is_rt_file(argv[1]))
	{
		printf("Error: %s is not a .rt file\n", argv[1]);
		return (EXIT_FAILURE);
	}
	scene = parse_scene(argv[1]);
	(void)scene;
}
