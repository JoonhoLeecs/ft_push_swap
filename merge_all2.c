/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_all2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 19:56:18 by joonhlee          #+#    #+#             */
/*   Updated: 2023/04/17 18:02:35 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	better_merge_ab(t_ps_deck *a, t_ps_deck *b, t_ops_deck *ops)
{
	int			check;
	t_ps_subseq	*top_sub;
	t_ps_subseq	*next_sub;

	top_sub = a->top_sub;
	next_sub = top_sub->next_sub;
	if (top_sub->n_node <= 2 && top_sub->top->raw < next_sub->top->raw
		&& b->top_sub->n_node + top_sub->n_node < next_sub->n_node * 2)
		return (merge_a_tops(a, ops));
	check = 0;
	if (a->top_sub->n_node < b->top_sub->n_node || b->n_subseq == 1)
	{
		check += tw_merge_ab(a, b, ops);
	}
	else
		check += double_merge(a, b, ops);
	return (check);
}

int	merge_a_tops(t_ps_deck *a, t_ops_deck *ops)
{
	int			check;
	int			count;

	check = 0;
	count = a->top_sub->n_node + a->top_sub->next_sub->n_node;
	while (0 < count && check == 0)
	{
		if (1 < count-- && find_next_inc_dec(a->top) < 0)
		{
			if (ps_sa(a, ops) == 0)
				ps_ra(a, ops);
		}
		else
			check = ps_ra(a, ops);
	}
	submerge_rasa(a);
	return (check);
}

int	better_merge_ba(t_ps_deck *a, t_ps_deck *b, t_ops_deck *ops)
{
	int			check;
	t_ps_subseq	*top_sub;
	t_ps_subseq	*next_sub;

	top_sub = b->top_sub;
	next_sub = top_sub->next_sub;
	if (top_sub->n_node <= 2 && top_sub->top->raw < next_sub->top->raw
		&& a->top_sub->n_node + top_sub->n_node > next_sub->n_node * 2)
		return (merge_b_tops(b, ops));
	check = 0;
	if (a->top_sub->n_node > b->top_sub->n_node || a->n_subseq == 1)
	{
		check += tw_merge_ba(a, b, ops);
	}
	else
		check += double_merge(a, b, ops);
	return (check);
}

int	merge_b_tops(t_ps_deck *b, t_ops_deck *ops)
{
	int			check;
	int			count;

	check = 0;
	count = b->top_sub->n_node + b->top_sub->next_sub->n_node;
	while (0 < count && check == 0)
	{
		if (1 < count-- && find_next_inc_dec(b->top) < 0)
		{
			check = ps_sb(b, ops);
			if (check == 0)
				ps_rb(b, ops);
		}
		else
			check = ps_rb(b, ops);
	}
	submerge_rasa(b);
	return (check);
}
