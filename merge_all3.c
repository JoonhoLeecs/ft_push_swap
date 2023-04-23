/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_all3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 21:05:41 by joonhlee          #+#    #+#             */
/*   Updated: 2023/04/23 13:14:56 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	mbad(t_m_env *env, t_ps_deque *a, t_ps_deque *b, t_ops_deque *ops)
{
	if (env->n_src_top > 0
		&& (env->n_src_bot == 0 || b->top->raw < b->bottom->raw)
		&& (env->n_dst_bot == 0 || b->top->raw < a->bottom->raw))
	{
		env->n_src_top--;
		return (ps_pa(a, b, ops));
	}
	else if (env->n_src_bot > 0
		&& (env->n_src_top == 0 || b->bottom->raw < b->top->raw)
		&& (env->n_dst_bot == 0 || b->bottom->raw < a->bottom->raw))
	{
		env->n_src_bot--;
		return (ps_rrb(b, ops) + ps_pa(a, b, ops));
	}
	else if (env->n_dst_bot > 0
		&& (env->n_src_top == 0 || a->bottom->raw < b->top->raw)
		&& (env->n_src_bot == 0 || a->bottom->raw < b->bottom->raw))
	{
		env->n_dst_bot--;
		return (ps_rra(a, ops));
	}
	return (0);
}

void	submerge_three_to_b(t_ps_deque *a, t_ps_deque *b)
{
	t_ps_node	*tmp;

	sub_add_top(b, sub_remove_bottom(b));
	if (a->top_sub && a->top_sub->sub_ind * b->top_sub->sub_ind < 0)
	{
		tmp = a->top_sub->bottom;
		a->top_sub->bottom = a->top_sub->top;
		a->top_sub->top = tmp;
		submerge_tops_to_b(a, b);
	}
	if (a->bottom_sub && a->bottom_sub->sub_ind * b->top_sub->sub_ind > 0)
	{
		sub_add_top(a, sub_remove_bottom(a));
		submerge_tops_to_b(a, b);
	}
}

void	submerge_tops_to_b(t_ps_deque *a, t_ps_deque *b)
{
	t_ps_subseq	*top_sub;
	t_ps_subseq	*next_sub;
	t_ps_node	*node_iter;
	int			sign;

	top_sub = sub_remove_top(b);
	next_sub = sub_remove_top(a);
	sign = (top_sub->sub_ind > 0) * 1 + (top_sub->sub_ind < 0) * -1;
	top_sub->n_node = top_sub->n_node + next_sub->n_node;
	if (top_sub->top->raw * sign > next_sub->top->raw * sign)
		top_sub->top = next_sub->top;
	if (top_sub->bottom->raw * sign < next_sub->bottom->raw * sign)
		top_sub->bottom = next_sub->bottom;
	clear_sub(next_sub);
	node_iter = top_sub->top;
	while (node_iter)
	{
		node_iter->sub_ind = top_sub->sub_ind;
		node_iter = node_iter->next;
	}
	sub_add_top(b, top_sub);
}
