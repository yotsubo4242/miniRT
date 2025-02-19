/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitahar <tkitahar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:23:08 by tkitahar          #+#    #+#             */
/*   Updated: 2025/02/19 15:23:34 by tkitahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

char	**split_space(const char *str)
{
	char	*copy;
	char	*ptr;
	char	**result;

	copy = ft_strdup(str);
	ptr = copy;
	while (*ptr)
	{
		if (ft_isspace(*ptr))
			*ptr = ' ';
		ptr++;
	}
	result = ft_split(copy, ' ');
	free(copy);
	return (result);
}
