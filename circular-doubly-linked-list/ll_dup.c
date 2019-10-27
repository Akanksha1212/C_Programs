/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll_dup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <lroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 14:26:12 by lroux             #+#    #+#             */
/*   Updated: 2019/10/27 23:16:41 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_node	*ll_dup(t_node *head)
{
	t_node *dup;
	t_node *node;

	dup = 0;
	node = head;
	while (true)
	{
		ll_add(&dup, node->data);
		node = node->next;
		if (node == head)
			break ;
	}
	return (dup);
}
