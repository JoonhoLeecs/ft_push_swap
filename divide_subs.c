/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_subs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 14:46:21 by joonhlee          #+#    #+#             */
/*   Updated: 2023/04/21 14:40:58 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	divide_subs(t_ps_deck *a, t_ps_deck *b, t_ops_deck *ops)
{
	int	check;

	// pstest_print_subs(a, b, ops);
	if (a->n_subseq == 1 && a->top_sub->sub_ind > 0)
		return (0);
	if (a->n_subseq == 1 && a->top_sub->sub_ind < 0)
		return (ps_sub_sa(a, b, ops));
	check = move_seed(a, b, ops);
	// printf("after move seed check = %d\n", check);
	// pstest_print_subs(a, b, ops);

	if (a->n_subseq == 1 && b->n_subseq == 1 && check == 0)
		return (merge_b_to_a_inc(a, b, ops));
	else if (a->n_subseq > 0 && b->n_subseq == 2 && check == 0)
		return (ds_move_s(a, b, ops));
	else if (a->n_subseq > 0 && b->n_subseq > 2 && check == 0)
		return (ds_move_l(a, b, ops));
	return (check);
}

// printf("a->n_sub=%d|nf_seed=%d\n", a->n_subseq, nf_seed);
// nf_seed = b->n_subseq;
// nf_seed = n_ops(ops);

int	move_seed(t_ps_deck *a, t_ps_deck *b, t_ops_deck *ops)
{
	int	nf_seed;

	nf_seed = greatest_power_a(a->n_subseq, 9);
	if (nf_seed < 9)
		nf_seed = 2 + (a->n_subseq == 2) * (-1);
	else if (a->n_subseq / nf_seed >= 3)
		nf_seed = nf_seed * 3;
	else
		nf_seed = (nf_seed / 3);
	if (nf_seed == 1)
		return (move_seed_two(a, b, ops));
	else if (nf_seed == 2)
		return (move_seed_s(a, b, ops));
	return (move_seed_l(a, b, ops, nf_seed));
}

int	greatest_power_a(int n, unsigned int a)
{
	int	power;

	if (n < 1)
		return (-1);
	power = 1;
	while (a * power <= (unsigned int)n)
		power = power * a;
	return (power);
}

int	move_seed_two(t_ps_deck *a, t_ps_deck *b, t_ops_deck *ops)
{
	int			check;

	if (a->top_sub->sub_ind > 0 && a->bottom_sub->sub_ind > 0)
		return (ps_sub_pb(a, b, ops));
	else if (a->top_sub->sub_ind < 0 && a->bottom_sub->sub_ind > 0)
		return (ps_sub_pb(a, b, ops));
	else if (a->top_sub->sub_ind > 0 && a->bottom_sub->sub_ind < 0)
	{
		check = ps_sub_ra(a, ops);
		if (check == 0)
			check = ps_sub_pb(a, b, ops);
	}
	else
	{
		check = ps_sub_pb(a, b, ops);
		if (check == 0)
			check = ps_sub_sa(a, b, ops);
	}
	return (check);
}

int	move_seed_s(t_ps_deck *a, t_ps_deck *b, t_ops_deck *ops)
{
	int	check;

	if (a->top_sub->sub_ind > 0)
		check = ps_sub_pbrb(a, b, ops);
	else
		check = ps_sub_pb(a, b, ops);
	if (a->top_sub->sub_ind > 0 && check == 0)
		check = ps_sub_pb(a, b, ops);
	else if (a->top_sub->sub_ind < 0 && check == 0
		&& (a->top_sub->next_sub->sub_ind > 0))
	{
		check = ps_sub_ra(a, ops);
		if (check == 0)
			check = ps_sub_pb(a, b, ops);
	}
	else if (a->top_sub->sub_ind < 0 && check == 0)
	{
		check = ps_sub_pbrb(a, b, ops);
		if (check == 0)
			check = ps_sub_rb(b, ops);
	}
	b->top_sub->divide = 1;
	return (check);
}
