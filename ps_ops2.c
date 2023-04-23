/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_ops2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 16:56:09 by joonhlee          #+#    #+#             */
/*   Updated: 2023/04/23 12:45:18 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ops_add_front(t_ops_deque *ops_deque, t_op_node *new)
{
	if (ops_deque == 0)
		return ;
	if (ops_deque->head == 0)
	{
		ops_deque->head = new;
		ops_deque->tail = new;
	}
	else
	{
		ops_deque->head->prev = new;
		new->next = ops_deque->head;
		ops_deque->head = new;
	}
}

void	ops_add_back(t_ops_deque *ops_deque, t_op_node *new)
{
	if (ops_deque == 0)
		return ;
	if (ops_deque->tail == 0)
	{
		ops_deque->head = new;
		ops_deque->tail = new;
	}
	else
	{
		ops_deque->tail->next = new;
		new->prev = ops_deque->tail;
		ops_deque->tail = new;
	}
}
