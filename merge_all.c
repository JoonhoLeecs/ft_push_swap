/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 21:05:41 by joonhlee          #+#    #+#             */
/*   Updated: 2023/04/14 18:01:20 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	merge_all(t_ps_deck *a, t_ps_deck *b, t_ops_deck *ops)
{
	int	check;

	check = 0;
	if (a->n_subseq == 1 && b->n_subseq == 1)
		return (fmerge_b_to_a(a, b, ops));
	while (a->n_subseq < b->n_subseq && b->n_subseq > 1 && check == 0)
		check += merge_b_to_a(a, b, ops);
	while (a->n_subseq > b->n_subseq && a->n_subseq > 1 && check == 0)
		check += merge_a_to_b(a, b, ops);
	while (a->n_subseq == b->n_subseq && a->n_subseq > 1 && check == 0)
	{
		check += merge_b_to_a(a, b, ops);
		if (check == 0)
			check += merge_a_to_b(a, b, ops);
	}
	if (check != 0)
		return (check);
	else
		return (merge_all(a, b, ops));
}

int	merge_b_to_a(t_ps_deck *a, t_ps_deck *b, t_ops_deck *ops)
{
	int	a_count;
	int	b_count;
	int	check;

	a_count = a->top_sub->n_node;
	b_count = b->top_sub->n_node;
	check = 0;
	while ((0 < a_count || 0 < b_count) && check == 0)
	{
		if ((a->top->raw < b->top->raw && 0 < a_count) || b_count == 0)
		{
			check += ps_ra(a, ops);
			a_count--;
		}
		else if ((a->top->raw > b->top->raw && 0 < b_count) || a_count == 0)
		{
			check += ps_pa(a, b, ops);
			if (check == 0)
			check += ps_ra(a, ops);
			b_count--;
		}
	}
	if (check == 0)
		submerge_b_to_a(a, b);
	return (check);
}

void	submerge_b_to_a(t_ps_deck *a, t_ps_deck *b)
{
	t_ps_subseq	*a_top_sub;
	t_ps_subseq	*b_top_sub;
	t_ps_node	*node_iter;

	a_top_sub = sub_remove_top(a);
	b_top_sub = sub_remove_top(b);
	a_top_sub->n_node = a_top_sub->n_node + b_top_sub->n_node;
	if (a_top_sub->top->raw > b_top_sub->top->raw)
		a_top_sub->top = b_top_sub->top;
	if (a_top_sub->bottom->raw < b_top_sub->bottom->raw)
		a_top_sub->bottom = b_top_sub->bottom;
	clear_sub(b_top_sub);
	node_iter = a_top_sub->top;
	while (node_iter)
	{
		node_iter->sub_ind = a_top_sub->sub_ind;
		node_iter = node_iter->next;
	}
	sub_add_bottom(a, a_top_sub);
}

int	merge_a_to_b(t_ps_deck *a, t_ps_deck *b, t_ops_deck *ops)
{
	int	a_count;
	int	b_count;
	int	check;

	a_count = a->top_sub->n_node;
	b_count = b->top_sub->n_node;
	check = 0;
	while ((0 < a_count || 0 < b_count) && check == 0)
	{
		if ((a->top->raw > b->top->raw && 0 < b_count) || a_count == 0)
		{
			check += ps_rb(b, ops);
			b_count--;
		}
		else if ((a->top->raw < b->top->raw && 0 < a_count) || b_count == 0)
		{
			check += ps_pb(a, b, ops);
			if (check == 0)
				check += ps_rb(b, ops);
			a_count--;
		}
	}
	if (check == 0)
		submerge_b_to_a(b, a);
	return (check);
}
