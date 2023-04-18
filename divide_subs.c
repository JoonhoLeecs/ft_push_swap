/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_subs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 14:46:21 by joonhlee          #+#    #+#             */
/*   Updated: 2023/04/18 18:22:50 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	divide_subs(t_ps_deck *a, t_ps_deck *b, t_ops_deck *ops)
{
	int	check;
	int	nf_b_sub;

	if (a->n_subseq == 1 && a->top_sub->sub_ind == 1)
		return (0);
	if (a->n_subseq == 1 && a->top_sub->sub_ind == -1)
		return (ps_sub_sa(a, b, ops));
	check = 0;
	nf_b_sub = calc_divide(a);
	while ((find_sub_to_move(a, b, nf_b_sub)) && check == 0)
	{
		if (a->top_sub->divide == 0 && find_next_inc_dec(a->top) > 0)
			check += ds_merge(a, b, ops, &nf_b_sub);
			// check += ds_better_rasa(a, ops);
		else if (a->top_sub->divide == 0 && find_next_inc_dec(a->top) < 0)
			check += ps_sub_sa(a, b, ops);
		else if (a->top_sub->divide == 1 && find_next_inc_dec(a->top) < 0)
			check += ds_better_pbsa(a, b, ops);
		else
			check += ps_sub_pbrb(a, b, ops);
	}
	if (check == 0)
		refine_subs(a, b);
	return (check);
}

int	calc_divide(t_ps_deck *a)
{
	t_ps_subseq	*sub_iter;
	int			n_b_sub;
	int			n_b_node;

	n_b_sub = 0;
	n_b_node = 0;
	sub_iter = a->top_sub;
	while (sub_iter)
	{
		if (sub_iter->sub_ind < 0)
		{
			n_b_sub += 1;
			n_b_node += sub_iter->n_node;
			sub_iter->divide = 1;
		}
		sub_iter = sub_iter->next_sub;
	}
	if (n_b_sub == a->n_subseq)
		adjust_to_a(a, &n_b_node, &n_b_sub);
	else if (n_b_sub == 0)
		adjust_to_b(a, &n_b_node, &n_b_sub);
	return (n_b_sub);
}

void	adjust_to_a(t_ps_deck *a, int *n_b_node, int *n_b_sub)
{
	t_ps_subseq	*sub_iter;
	int			target_size;

	sub_iter = a->top_sub;
	target_size = 2;
	while (*n_b_sub == a->n_subseq)
	{
		if (sub_iter->divide == 1 && sub_iter->n_node == target_size)
		{
			sub_iter->divide = 0;
			*n_b_node -= sub_iter->n_node;
			*n_b_sub -= 1;
		}
		if (sub_iter->next_sub == 0)
		{
			sub_iter = a->top_sub;
			target_size += 1;
		}
		else
			sub_iter = sub_iter->next_sub;
	}
}

void	adjust_to_b(t_ps_deck *a, int *n_b_node, int *n_b_sub)
{
	t_ps_subseq	*sub_iter;
	int			target_size;

	sub_iter = a->top_sub;
	target_size = 1;
	while (*n_b_sub == 0)
	{
		if (sub_iter->divide == 0 && sub_iter->n_node == target_size)
		{
			sub_iter->divide = 1;
			*n_b_node += sub_iter->n_node;
			*n_b_sub += 1;
		}
		if (sub_iter->next_sub == 0)
		{
			sub_iter = a->top_sub;
			target_size += 1;
		}
		else
			sub_iter = sub_iter->next_sub;
	}
}

int	find_sub_to_move(t_ps_deck *a, t_ps_deck *b, int nf_b_sub)
{
	t_ps_subseq	*sub_iter;

	// if (b->n_subseq < nf_b_sub)
	// 	return (1);
	nf_b_sub = b->n_subseq;
	sub_iter = a->top_sub;
	while (sub_iter)
	{
		if (sub_iter->divide == 1)
			return (1);
		if (sub_iter->divide == 0 && sub_iter->n_node > 1
			&& find_next_inc_dec(sub_iter->top) < 0)
			return (1);
		sub_iter = sub_iter->next_sub;
	}
	return (0);
}
