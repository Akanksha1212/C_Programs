/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll_pop.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <lroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 14:24:15 by lroux             #+#    #+#             */
/*   Updated: 2019/10/27 23:16:03 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	*ll_pop(t_node **head, int id)
{
	void	*data;
	t_node	*cur;

	if (!head || !(cur = ll_get(*head, id)))
		return (NULL);
	data = cur->data;
	cur->next->prev = cur->prev;
	cur->prev->next = cur->next;
	if (cur->next == cur)
		*head = NULL;
	if (cur == *head)
		*head = cur->next;
	free(cur);
	return (data);
}
