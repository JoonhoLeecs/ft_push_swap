/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_subs5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 14:46:21 by joonhlee          #+#    #+#             */
/*   Updated: 2023/04/23 12:45:18 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	raw_find_ra_rra(t_ps_deque *a, int raw)
{
	t_ps_node	*node;
	int			ra;
	int			rra;

	node = a->top;
	if (node->raw == 0)
		return (0);
	ra = 0;
	while (node)
	{
		if (node->raw == raw)
			break ;
		ra++;
		node = node->next;
	}
	node = a->bottom;
	rra = 0;
	while (node)
	{
		rra++;
		if (node->raw == raw)
			break ;
		node = node->prev;
	}
	return (rra - ra);
}

int	move_rb(t_ps_deque *a, t_ps_deque *b, t_ops_deque *ops, int raw)
{
	int	a_direction;
	int	check;
	int	sign;

	a_direction = raw_find_ra_rra(a, raw);
	sign = (b->top_sub->sub_ind > 0) * 1 + (b->top_sub->sub_ind < 0) * -1;
	check = 0;
	while (a_direction >= 0 && a->top->raw != raw && check == 0)
		check = ps_ra(a, ops);
	while (a_direction < 0 && a->top->raw != raw && check == 0)
		check = ps_rra(a, ops);
	while (sign * raw > sign * b->top->raw
		&& b->top->raw != b->top_sub->next_sub->top->raw && check == 0)
		check = ps_rb(b, ops);
	if (check == 0)
		check = ps_pb(a, b, ops);
	insert_submerge(b, b->top_sub);
	return (check);
}

int	move_rrb(t_ps_deque *a, t_ps_deque *b, t_ops_deque *ops, int raw)
{
	int	a_direction;
	int	check;
	int	sign;

	a_direction = raw_find_ra_rra(a, raw);
	sign = (b->bottom_sub->sub_ind > 0) * 1 + (b->bottom_sub->sub_ind < 0) * -1;
	check = 0;
	while (a_direction > 0 && a->top->raw != raw && check == 0)
		check = ps_ra(a, ops);
	while (a_direction <= 0 && a->top->raw != raw && check == 0)
		check = ps_rra(a, ops);
	while (sign * raw < sign * b->bottom->raw
		&& b->bottom->raw != b->bottom_sub->prev_sub->bottom->raw && check == 0)
		check = ps_rrb(b, ops);
	if (check == 0)
		check = ps_pb(a, b, ops);
	insert_submerge(b, b->bottom_sub);
	return (check);
}

void	insert_submerge(t_ps_deque *b, t_ps_subseq *sub)
{
	int	raw;

	raw = b->top->raw;
	sub->n_node += 1;
	if (sub->sub_ind > 0 && raw < sub->top->raw)
		sub->top = b->top;
	if (sub->sub_ind > 0 && raw > sub->bottom->raw)
		sub->bottom = b->top;
	if (sub->sub_ind < 0 && raw > sub->top->raw)
		sub->top = b->top;
	if (sub->sub_ind < 0 && raw < sub->bottom->raw)
		sub->bottom = b->top;
}
