/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitahar <tkitahar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 16:29:08 by tkitahar          #+#    #+#             */
/*   Updated: 2025/02/28 16:37:57 by tkitahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

void	clear_list(t_list *list, void (*del)(void *))
{
	t_node	*node;
	t_node	*next;

	if (!list)
		return ;
	node = list->head;
	while (node)
	{
		next = node->next;
		if (del)
			del(node->data);
		free(node);
		node = next;
	}
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
}
