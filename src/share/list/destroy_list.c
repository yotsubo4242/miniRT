/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitahar <tkitahar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 16:29:27 by tkitahar          #+#    #+#             */
/*   Updated: 2025/02/28 16:31:49 by tkitahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

void	destroy_list(t_list *list, void (*del)(void *))
{
	if (!list)
		return ;
	clear_list(list, del);
	free(list);
}
