/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 19:31:45 by joonhlee          #+#    #+#             */
/*   Updated: 2023/04/23 12:45:18 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_small(t_ps_deque *a, t_ps_deque *b, t_ops_deque *ops)
{
	int	check;

	check = 0;
	if (a->n_node == 1)
		return (0);
	if (a->n_node == 2)
		return (sort_two_a(a, ops));
	if (a->n_node == 3)
		return (sort_three_a(a, ops));
	if (a->n_node == 4)
		return (sort_four(a, b, ops));
	return (sort_five(a, b, ops));
}

int	sort_two_a(t_ps_deque *a, t_ops_deque *ops)
{
	if (is_ordered(a) == 1)
		return (0);
	else
		return (ps_sa(a, ops));
}

int	sort_two_b(t_ps_deque *b, t_ops_deque *ops)
{
	if (is_ordered(b) == 1)
		return (0);
	else
		return (ps_sb(b, ops));
}

int	sort_three_a(t_ps_deque *a, t_ops_deque *ops)
{
	int	top_raw;
	int	middle_raw;
	int	bottom_raw;

	if (is_ordered(a) == 1)
		return (0);
	top_raw = a->top->raw;
	middle_raw = a->top->next->raw;
	bottom_raw = a->bottom->raw;
	if (top_raw < bottom_raw && bottom_raw < middle_raw)
	{
		if (ps_sa(a, ops) != 0)
			return (1);
		return (ps_ra(a, ops));
	}
	else if (middle_raw < top_raw && top_raw < bottom_raw)
		return (ps_sa(a, ops));
	else if (bottom_raw < top_raw && top_raw < middle_raw)
		return (ps_rra(a, ops));
	else if (middle_raw < bottom_raw && bottom_raw < top_raw)
		return (ps_ra(a, ops));
	if (ps_sa(a, ops) != 0)
		return (1);
	return (ps_rra(a, ops));
}

int	sort_three_b(t_ps_deque *b, t_ops_deque *ops)
{
	int	top_raw;
	int	middle_raw;
	int	bottom_raw;

	if (is_ordered(b) == 1)
		return (0);
	top_raw = b->top->raw;
	middle_raw = b->top->next->raw;
	bottom_raw = b->bottom->raw;
	if (top_raw < bottom_raw && bottom_raw < middle_raw)
	{
		if (ps_sb(b, ops) != 0)
			return (1);
		return (ps_rb(b, ops));
	}
	else if (middle_raw < top_raw && top_raw < bottom_raw)
		return (ps_sb(b, ops));
	else if (bottom_raw < top_raw && top_raw < middle_raw)
		return (ps_rrb(b, ops));
	else if (middle_raw < bottom_raw && bottom_raw < top_raw)
		return (ps_ra(b, ops));
	if (ps_sb(b, ops) != 0)
		return (1);
	return (ps_rrb(b, ops));
}
