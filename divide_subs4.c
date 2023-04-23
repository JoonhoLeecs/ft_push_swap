/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_subs4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 14:46:21 by joonhlee          #+#    #+#             */
/*   Updated: 2023/04/23 12:47:09 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	insertion_better(t_ps_deque *a, t_ps_deque *b)
{
	long long	current;
	long long	next;
	t_ib_env	env;

	env.an_node = (long long)a->n_node;
	env.bn_node = (long long)b->n_node;
	env.an_sub = (long long)a->n_subseq;
	env.bn_sub = (long long)b->n_subseq;
	if (env.an_sub == 0 || env.bn_sub == 0 || env.an_node < 4 || env.an_sub < 3
		|| 9 * env.an_node / env.an_sub >= env.bn_node / env.bn_sub)
		return (0);
	current = (4 * env.bn_node * (env.an_sub - 1) + env.bn_sub * env.an_node
			* (1 - env.an_node)) / (4 * env.bn_sub);
	next = calc_next(a, b, &env);
	if (current > 0 && current >= next)
		return (1);
	else
		return (0);
}

long long	calc_next(t_ps_deque *a, t_ps_deque *b, t_ib_env *env)
{
	long long	next;

	if (same_order(a->bottom_sub, b->bottom_sub) > 0)
	{
		env->an_node -= a->bottom_sub->n_node;
		env->bn_node += a->bottom_sub->n_node;
		env->an_sub -= 1;
		env->bn_sub += 1;
	}
	if (same_order(a->top_sub, b->bottom_sub) < 0 || (a->top_sub->n_node <= 3
			&& same_order(a->top_sub, b->bottom_sub) > 0))
	{
		env->an_node -= a->top_sub->n_node;
		env->bn_node += a->top_sub->n_node;
		env->an_sub -= 1;
		env->bn_sub += 1;
	}
	next = (4 * env->bn_node * (env->an_sub - 1) + env->bn_sub * env->an_node
			* (1 - env->an_node)) / (4 * env->bn_sub);
	return (next);
}

int	insert_to_b(t_ps_deque *a, t_ps_deque *b, t_ops_deque *ops)
{
	int	direction;
	int	check;

	direction = ds_find_rb_rrb(b);
	if (direction > 0)
		check = insert_rb(a, b, ops, b->top_sub->sub_ind);
	else
		check = insert_rrb(a, b, ops, b->bottom_sub->sub_ind);
	return (check);
}

int	insert_rb(t_ps_deque *a, t_ps_deque *b, t_ops_deque *ops, int s)
{
	int	raw;
	int	check;

	check = 0;
	while (s > 0 && a->n_node > 0 && check == 0)
	{
		raw = find_min(a);
		check = move_rb(a, b, ops, raw);
	}
	while (s < 0 && a->n_node > 0 && check == 0)
	{
		raw = find_max(a);
		check = move_rb(a, b, ops, raw);
	}
	sub_add_bottom(b, sub_remove_top(b));
	ps_clear_all_subseq(a);
	while (b->top->raw != b->top_sub->top->raw && check == 0)
		check = ps_rb(b, ops);
	return (check);
}

int	insert_rrb(t_ps_deque *a, t_ps_deque *b, t_ops_deque *ops, int s)
{
	int	raw;
	int	check;

	check = 0;
	while (s > 0 && a->n_node > 0 && check == 0)
	{
		raw = find_max(a);
		check = move_rrb(a, b, ops, raw);
	}
	while (s < 0 && a->n_node > 0 && check == 0)
	{
		raw = find_min(a);
		check = move_rrb(a, b, ops, raw);
	}
	sub_add_top(b, sub_remove_bottom(b));
	ps_clear_all_subseq(a);
	while (b->bottom->raw != b->bottom_sub->bottom->raw && check == 0)
		check = ps_rrb(b, ops);
	return (check);
}
