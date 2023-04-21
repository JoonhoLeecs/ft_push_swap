/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 21:05:41 by joonhlee          #+#    #+#             */
/*   Updated: 2023/04/21 14:45:17 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	merge_all(t_ps_deck *a, t_ps_deck *b, t_ops_deck *ops)
{
	int	check;

	check = 0;
	if (a->n_subseq == 1 && b->n_subseq == 0 && is_ordered(a))
		return (0);
	if (b->n_subseq == 2)
		return (merge_small(a, b, ops));
	while (a->n_subseq + b->n_subseq > 1 && check == 0)
	{
		// pstest_print_subs(a, b, ops);
		// if (a->n_subseq > 0 && b->n_subseq)
		// 	printf("wrong!!!!!\n");
		if (a->n_subseq == 0)
			check = merge_allb_to_a(a, b, ops);
		else
			check = merge_alla_to_b(a, b, ops);
	}
	return (check);
}

int	merge_small(t_ps_deck *a, t_ps_deck *b, t_ops_deck *ops)
{
	int	check;
	// pstest_print_subs(a, b, ops);

	check = 0;
	if (a->n_subseq == 0)
	{
		check = ps_sub_pa(a, b, ops);
		if (check == 0)
			check = merge_b_to_a_inc(a, b, ops);
		return (0);
	}
	if (a->n_subseq == 1 && a->top_sub->sub_ind < 0)
		check = ps_sub_sa(a, b, ops);
	if (check == 0)
		check = merge_b_to_a_inc(a, b, ops);
	// pstest_print_subs(a, b, ops);

	return (0);
}

int	merge_allb_to_a(t_ps_deck *a, t_ps_deck *b, t_ops_deck *ops)
{
	int	count;
	int	check;

	// pstest_print_subs(a, b, ops);
	check = 0;
	count = b->n_subseq / 3;
	while (count-- > 0 && check == 0)
		check = ps_sub_pa(a, b, ops);
	// pstest_print_subs(a, b, ops);
	while (b->n_subseq > 0)
	{
		if (a->bottom_sub->sub_ind > 0 && check == 0)
			check = merge_b_to_a_inc(a, b, ops);
		else if (a->bottom_sub->sub_ind < 0 && check == 0)
			check = merge_b_to_a_dec(a, b, ops);
	}
	return (check);
}

int	merge_alla_to_b(t_ps_deck *a, t_ps_deck *b, t_ops_deck *ops)
{
	int	count;
	int	check;

	// pstest_print_subs(a, b, ops);
	check = 0;
	count = a->n_subseq / 3;
	while (count-- > 0 && check == 0)
		check = ps_sub_pb(a, b, ops);
	// pstest_print_subs(a, b, ops);
	while (a->n_subseq > 0)
	{
		if (b->bottom_sub->sub_ind > 0 && check == 0)
			check = merge_a_to_b_inc(a, b, ops);
		else if (b->bottom_sub->sub_ind < 0 && check == 0)
			check = merge_a_to_b_dec(a, b, ops);
	}
	return (check);
}
