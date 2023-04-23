/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_all2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 21:05:41 by joonhlee          #+#    #+#             */
/*   Updated: 2023/04/23 13:15:00 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	merge_a_to_b(t_ps_deque *a, t_ps_deque *b, t_ops_deque *ops)
{
	t_m_env	env;
	int		check;

	env.n_src_top = (same_order(a->top_sub, b->bottom_sub) < 0)
		* a->top_sub->n_node;
	env.n_src_bot = (same_order(a->bottom_sub, b->bottom_sub) > 0)
		* a->bottom_sub->n_node;
	env.n_dst_bot = b->bottom_sub->n_node;
	check = 0;
	while ((env.n_src_top > 0 || env.n_src_bot > 0 || env.n_dst_bot > 0)
		&& check == 0)
	{
		if (b->bottom_sub->sub_ind > 0)
			check = mab(&env, a, b, ops);
		else
			check = mabd(&env, a, b, ops);
	}
	submerge_three_to_b(a, b);
	return (check);
}

int	mab(t_m_env *env, t_ps_deque *a, t_ps_deque *b, t_ops_deque *ops)
{
	if (env->n_src_top > 0
		&& (env->n_src_bot == 0 || a->top->raw > a->bottom->raw)
		&& (env->n_dst_bot == 0 || a->top->raw > b->bottom->raw))
	{
		env->n_src_top--;
		return (ps_pb(a, b, ops));
	}
	else if (env->n_src_bot > 0
		&& (env->n_src_top == 0 || a->bottom->raw > a->top->raw)
		&& (env->n_dst_bot == 0 || a->bottom->raw > b->bottom->raw))
	{
		env->n_src_bot--;
		return (ps_rra(a, ops) + ps_pb(a, b, ops));
	}
	else if (env->n_dst_bot > 0
		&& (env->n_src_top == 0 || b->bottom->raw > a->top->raw)
		&& (env->n_src_bot == 0 || b->bottom->raw > a->bottom->raw))
	{
		env->n_dst_bot--;
		return (ps_rrb(b, ops));
	}
	return (0);
}

int	mabd(t_m_env *env, t_ps_deque *a, t_ps_deque *b, t_ops_deque *ops)
{
	if (env->n_src_top > 0
		&& (env->n_src_bot == 0 || a->top->raw < a->bottom->raw)
		&& (env->n_dst_bot == 0 || a->top->raw < b->bottom->raw))
	{
		env->n_src_top--;
		return (ps_pb(a, b, ops));
	}
	else if (env->n_src_bot > 0
		&& (env->n_src_top == 0 || a->bottom->raw < a->top->raw)
		&& (env->n_dst_bot == 0 || a->bottom->raw < b->bottom->raw))
	{
		env->n_src_bot--;
		return (ps_rra(a, ops) + ps_pb(a, b, ops));
	}
	else if (env->n_dst_bot > 0
		&& (env->n_src_top == 0 || b->bottom->raw < a->top->raw)
		&& (env->n_src_bot == 0 || b->bottom->raw < a->bottom->raw))
	{
		env->n_dst_bot--;
		return (ps_rrb(b, ops));
	}
	return (0);
}

int	merge_b_to_a(t_ps_deque *a, t_ps_deque *b, t_ops_deque *ops)
{
	t_m_env	env;
	int		check;

	env.n_src_top = (same_order(b->top_sub, a->bottom_sub) < 0)
		* b->top_sub->n_node;
	env.n_src_bot = (same_order(b->bottom_sub, a->bottom_sub) > 0)
		* b->bottom_sub->n_node;
	env.n_dst_bot = a->bottom_sub->n_node;
	check = 0;
	while ((env.n_src_top > 0 || env.n_src_bot > 0 || env.n_dst_bot > 0)
		&& check == 0)
	{
		if (a->bottom_sub->sub_ind > 0)
			check = mba(&env, a, b, ops);
		else
			check = mbad(&env, a, b, ops);
	}
	submerge_three_to_b(b, a);
	return (check);
}

int	mba(t_m_env *env, t_ps_deque *a, t_ps_deque *b, t_ops_deque *ops)
{
	if (env->n_src_top > 0
		&& (env->n_src_bot == 0 || b->top->raw > b->bottom->raw)
		&& (env->n_dst_bot == 0 || b->top->raw > a->bottom->raw))
	{
		env->n_src_top--;
		return (ps_pa(a, b, ops));
	}
	else if (env->n_src_bot > 0
		&& (env->n_src_top == 0 || b->bottom->raw > b->top->raw)
		&& (env->n_dst_bot == 0 || b->bottom->raw > a->bottom->raw))
	{
		env->n_src_bot--;
		return (ps_rrb(b, ops) + ps_pa(a, b, ops));
	}
	else if (env->n_dst_bot > 0
		&& (env->n_src_top == 0 || a->bottom->raw > b->top->raw)
		&& (env->n_src_bot == 0 || a->bottom->raw > b->bottom->raw))
	{
		env->n_dst_bot--;
		return (ps_rra(a, ops));
	}
	return (0);
}
