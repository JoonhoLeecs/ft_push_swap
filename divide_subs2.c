/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_subs2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 16:45:42 by joonhlee          #+#    #+#             */
/*   Updated: 2023/04/17 20:07:50 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ds_better_rasa(t_ps_deck *a, t_ops_deck *ops)
{
	int			check;
	int			count;
	t_ps_subseq	*top_sub;
	t_ps_subseq	*next_sub;

	top_sub = a->top_sub;
	next_sub = top_sub->next_sub;
	if (next_sub->divide == 1 || top_sub->top->raw > next_sub->top->raw
		|| top_sub->n_node > 2 || top_sub->bottom->raw < next_sub->top->raw)
		return (ps_sub_ra(a, ops));
	check = 0;
	count = top_sub->n_node + next_sub->n_node;
	while (0 < count && check == 0)
	{
		if (1 < count-- && find_next_inc_dec(a->top) < 0)
		{
			check = ps_sa(a, ops);
			if (check == 0)
				ps_ra(a, ops);
		}
		else
			check = ps_ra(a, ops);
	}
	submerge_rasa(a);
	return (check);
}

int	ds_better_pbsa(t_ps_deck *a, t_ps_deck *b, t_ops_deck *ops)
{
	int			check;
	int			count;
	t_ps_subseq	*top_sub;
	t_ps_subseq	*next_sub;

	top_sub = a->top_sub;
	next_sub = top_sub->next_sub;
	if (next_sub->divide == 0 || top_sub->bottom->raw > next_sub->top->raw
		|| top_sub->n_node > 2 || top_sub->top->raw < next_sub->top->raw)
		return (ps_sub_pb(a, b, ops));
	check = 0;
	count = top_sub->n_node + next_sub->n_node;
	while (0 < count && check == 0)
	{
		if (1 < count-- && find_next_inc_dec(a->top) > 0)
		{
			check = ps_sa(a, ops);
			if (check == 0)
				ps_pb(a, b, ops);
		}
		else
			check = ps_pb(a, b, ops);
	}
	submerge_pbsa(a, b);
	return (check);
}

void	submerge_rasa(t_ps_deck *a)
{
	t_ps_subseq	*top_sub;
	t_ps_subseq	*next_sub;
	t_ps_node	*node_iter;

	top_sub = sub_remove_top(a);
	next_sub = sub_remove_top(a);
	top_sub->n_node = top_sub->n_node + next_sub->n_node;
	if (top_sub->top->raw > next_sub->top->raw)
		top_sub->top = next_sub->top;
	if (top_sub->bottom->raw < next_sub->bottom->raw)
		top_sub->bottom = next_sub->bottom;
	clear_sub(next_sub);
	node_iter = top_sub->top;
	while (node_iter)
	{
		node_iter->sub_ind = top_sub->sub_ind;
		node_iter = node_iter->next;
	}
	sub_add_bottom(a, top_sub);
}

void	submerge_pbsa(t_ps_deck *a, t_ps_deck *b)
{
	t_ps_subseq	*top_sub;
	t_ps_subseq	*next_sub;
	t_ps_node	*node_iter;

	top_sub = sub_remove_top(a);
	next_sub = sub_remove_top(a);
	top_sub->n_node = top_sub->n_node + next_sub->n_node;
	if (top_sub->bottom->raw < next_sub->bottom->raw)
		node_iter = top_sub->bottom;
	else
		node_iter = next_sub->bottom;
	if (top_sub->top->raw > next_sub->top->raw)
		top_sub->bottom = top_sub->top;
	else
		top_sub->bottom = next_sub->top;
	top_sub->top = node_iter;
	clear_sub(next_sub);
	while (node_iter->raw < top_sub->bottom->raw)
	{
		node_iter->sub_ind = top_sub->sub_ind;
		node_iter = node_iter->next;
	}
	node_iter->sub_ind = top_sub->sub_ind;
	sub_add_top(b, top_sub);
}

void	submerge_two_bottoms(t_ps_deck *a)
{
	t_ps_subseq	*top_sub;
	t_ps_subseq	*next_sub;
	t_ps_node	*node_iter;

	next_sub = sub_remove_bottom(a);
	top_sub = sub_remove_bottom(a);
	top_sub->n_node = top_sub->n_node + next_sub->n_node;
	if (top_sub->top->raw > next_sub->top->raw)
		top_sub->top = next_sub->top;
	if (top_sub->bottom->raw < next_sub->bottom->raw)
		top_sub->bottom = next_sub->bottom;
	clear_sub(next_sub);
	node_iter = top_sub->top;
	while (node_iter)
	{
		node_iter->sub_ind = top_sub->sub_ind;
		node_iter = node_iter->next;
	}
	sub_add_bottom(a, top_sub);
}

// void	submerge_pbrb(t_ps_deck *b)
// {
// 	t_ps_subseq	*top_sub;
// 	t_ps_subseq	*next_sub;
// 	t_ps_node	*node_iter;

// 	next_sub = sub_remove_bottom(b);
// 	top_sub = sub_remove_bottom(b);
// 	top_sub->n_node = top_sub->n_node + next_sub->n_node;
// 	if (top_sub->bottom->raw < next_sub->bottom->raw)
// 		node_iter = top_sub->bottom;
// 	else
// 		node_iter = next_sub->bottom;
// 	if (top_sub->top->raw > next_sub->top->raw)
// 		top_sub->bottom = top_sub->top;
// 	else
// 		top_sub->bottom = next_sub->top;
// 	top_sub->top = node_iter;
// 	clear_sub(next_sub);
// 	while (node_iter->raw < top_sub->bottom->raw)
// 	{
// 		node_iter->sub_ind = top_sub->sub_ind;
// 		node_iter = node_iter->next;
// 	}
// 	node_iter->sub_ind = top_sub->sub_ind;
// 	sub_add_bottom(b, top_sub);
// }
