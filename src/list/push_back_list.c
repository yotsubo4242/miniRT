/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitahar <tkitahar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:14:40 by tkitahar          #+#    #+#             */
/*   Updated: 2025/02/24 13:17:30 by tkitahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

t_node	*push_back_list(t_list *list, void *data)
{
	t_node	*node;

	if (list == NULL)
		return (NULL);
	node = creat_node(data);
	if (!node)
		return (NULL);
	node->prev = list->tail;
	if (list->tail)
		list->tail->next = node;
	list->tail = node;
	if (!list->head)
		list->head = node;
	++list->size;
	return (node);
}
