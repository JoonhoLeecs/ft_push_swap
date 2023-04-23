/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refine_subs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 12:12:20 by joonhlee          #+#    #+#             */
/*   Updated: 2023/04/23 12:45:18 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	refine_subs(t_ps_deque *a, t_ps_deque *b)
{
	refine_sub(a);
	refine_sub(b);
}

void	refine_sub(t_ps_deque *a)
{
	t_ps_subseq	*sub_iter;
	t_ps_subseq	*sub_iter_next;

	if (a->n_subseq <= 1)
		return ;
	sub_iter = a->top_sub;
	while (sub_iter->next_sub)
	{
		if (find_next_inc_dec(sub_iter->bottom) > 0)
		{
			sub_iter_next = sub_iter->next_sub;
			update_sub_ind(sub_iter_next, sub_iter->sub_ind);
			a->n_subseq -= 1;
			if (a->bottom_sub->top->raw == sub_iter_next->top->raw)
				a->bottom_sub = sub_iter;
			sub_iter->next_sub = sub_iter_next->next_sub;
			if (sub_iter_next->next_sub != 0)
				sub_iter_next->next_sub->prev_sub = sub_iter;
			sub_iter->bottom = sub_iter_next->bottom;
			sub_iter->n_node += sub_iter_next->n_node;
			clear_sub(sub_iter_next);
		}
		else
			sub_iter = sub_iter->next_sub;
	}
}

void	update_sub_ind(t_ps_subseq *sub, int sub_ind)
{
	t_ps_node	*node_iter;

	if (sub->n_node == 0)
		return ;
	node_iter = sub->top;
	while (node_iter)
	{
		node_iter->sub_ind = sub_ind;
		node_iter = node_iter->next;
	}
}
