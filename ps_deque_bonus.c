/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_deque_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:04:18 by joonhlee          #+#    #+#             */
/*   Updated: 2023/04/23 14:06:50 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_ps_node	*ps_new_node(int raw)
{
	t_ps_node	*new_node;

	new_node = (t_ps_node *) malloc(sizeof (t_ps_node));
	if (new_node == 0)
		return (0);
	new_node->raw = raw;
	new_node->sub_ind = 0;
	new_node->next = 0;
	new_node->prev = 0;
	return (new_node);
}

t_ps_deque	*ps_new_deque(void)
{
	t_ps_deque	*new_deque;

	new_deque = (t_ps_deque *) malloc(sizeof (t_ps_deque));
	if (new_deque == 0)
		return (0);
	new_deque->n_node = 0;
	new_deque->top = 0;
	new_deque->bottom = 0;
	new_deque->n_subseq = 0;
	new_deque->top_sub = 0;
	new_deque->bottom_sub = 0;
	return (new_deque);
}

void	ps_clear_deque(t_ps_deque *deque)
{
	t_ps_node	*node_iter;
	t_ps_node	*node_to_clear;

	if (deque == 0)
		return ;
	node_iter = deque->top;
	while (node_iter)
	{
		node_to_clear = node_iter;
		node_iter = node_iter->next;
		node_to_clear->next = 0;
		node_to_clear->prev = 0;
		free(node_to_clear);
		node_to_clear = 0;
	}
	ps_clear_all_subseq(deque);
	deque->top = 0;
	deque->bottom = 0;
	free(deque);
	deque = 0;
}

void	ps_clear_all_subseq(t_ps_deque *deque)
{
	t_ps_subseq	*subseq_iter;
	t_ps_subseq	*subseq_to_clear;

	subseq_iter = deque->top_sub;
	while (subseq_iter)
	{
		subseq_to_clear = subseq_iter;
		subseq_iter = subseq_iter->next_sub;
		subseq_to_clear->top = 0;
		subseq_to_clear->bottom = 0;
		subseq_to_clear->next_sub = 0;
		subseq_to_clear->prev_sub = 0;
		free(subseq_to_clear);
		subseq_to_clear = 0;
	}
	deque->top_sub = 0;
	deque->bottom_sub = 0;
	deque->n_subseq = 0;
}
