/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_with_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitahar <tkitahar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 21:03:24 by tkitahar          #+#    #+#             */
/*   Updated: 2025/02/18 21:04:16 by tkitahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

void	exit_with_error(int status, const char *message)
{
	if (message == NULL)
		write(STDERR_FILENO, "Error\n", 6);
	else
		ft_dprintf(STDERR_FILENO, "Error: %s\n", message);
	exit(status);
}
