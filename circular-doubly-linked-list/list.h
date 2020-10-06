/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <lroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 15:32:09 by lroux             #+#    #+#             */
/*   Updated: 2019/10/27 23:13:22 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include <stdlib.h>
# include "types.h"

typedef struct	s_node {
	void			*data;
	struct s_node	*prev;
	struct s_node	*next;
}				t_node;

void			ll_add(t_node **head, void *data);
t_node			*ll_dup(t_node *head);
t_node			*ll_get(t_node *head, int id);
void			*ll_pop(t_node **head, int id);

void			ll_shift(t_node **head, int offset);

size_t			ll_len(t_node *head);
t_bool			ll_del(t_node **head);

#endif
