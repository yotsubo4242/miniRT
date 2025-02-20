/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitahar <tkitahar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:31:50 by tkitahar          #+#    #+#             */
/*   Updated: 2025/02/19 15:32:10 by tkitahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

void	free_array(char **array)
{
	char	**ptr;

	if (array == NULL)
		return ;
	ptr = array;
	while (*ptr)
	{
		free(*ptr);
		++ptr;
	}
	free(array);
}
