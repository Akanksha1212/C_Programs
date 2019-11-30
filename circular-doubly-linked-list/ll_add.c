/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <lroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 07:09:02 by lroux             #+#    #+#             */
/*   Updated: 2019/10/27 23:15:13 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	ll_add(t_node **head, void *data)
{
	t_node *new;

	if (!data || !(new = calloc(1, sizeof(*new))))
		return ;
	new->data = data;
	if (!*head)
		new->next = new;
	else
		new->next = *head;
	if (!*head)
		new->prev = new;
	else
		new->prev = (*head)->prev;
	if (!*head)
		*head = new;
	(*head)->prev->next = new;
	(*head)->prev = new;
}
