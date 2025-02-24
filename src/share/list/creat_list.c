/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitahar <tkitahar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 21:32:41 by tkitahar          #+#    #+#             */
/*   Updated: 2025/02/24 13:26:16 by tkitahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

t_list	*create_list(void)
{
	t_list	*list;

	list = ft_calloc(1, sizeof(t_list));
	if (list == NULL)
		return (NULL);
	return (list);
}
