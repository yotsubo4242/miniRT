/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitahar <tkitahar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 21:29:52 by tkitahar          #+#    #+#             */
/*   Updated: 2025/02/24 13:27:37 by tkitahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include "scene.h"

typedef struct s_node
{
	void			*data;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_list
{
	t_node			*head;
	t_node			*tail;
	size_t			size;
}					t_list;


t_node	*creat_node(void *data);
t_node	*push_back_list(t_list *list, void *data);
t_list	*create_list(void);

#endif
