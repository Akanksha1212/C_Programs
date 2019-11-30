/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll_len.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <lroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 14:25:25 by lroux             #+#    #+#             */
/*   Updated: 2019/10/27 23:15:52 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

size_t	ll_len(t_node *head)
{
	size_t len;
	t_node *node;

	if (!head)
		return (0);
	len = 0;
	node = head;
	while (true)
	{
		len++;
		node = node->next;
		if (node == head)
			break ;
	}
	return (len);
}
