/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sub_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:44:22 by joonhlee          #+#    #+#             */
/*   Updated: 2023/04/13 17:51:23 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// check += ps_sub_ra(a, ops);
// else if (a->top_sub->divide == 0 && a->top_sub->sub_ind < 0)
// 	check += ps_sub_sa(a, b, ops);
// else if (a->top_sub->divide == 1 && a->top_sub->sub_ind < 0)
// 	check += ps_sub_pb(a, b, ops);
// else check += ps_sub_pbrb(a, b, ops);
// }
// if (a->n_subseq == 1 && a->top_sub->sub_ind < 0 && check == 0)
// 	check += ps_sub_sa(a, b, ops);

#include "push_swap.h"

int	ps_sub_ra(t_ps_deck *a, t_ops_deck *ops)
{
	t_ps_subseq	*top;
	int			check;
	int			count;
	int			n_node;

	if (a->n_subseq == 0)
		return (1);
	if (a->n_subseq == 1)
		return (0);
	check = 0;
	count = -1;
	n_node = a->top_sub->n_node;
	while (++count < n_node && check == 0)
		check += ps_ra(a, ops);
	if (check == 0)
	{
		top = sub_remove_top(a);
		sub_add_bottom(a, top);
	}
	return (check);
}

int	ps_sub_pb(t_ps_deck *a, t_ps_deck *b, t_ops_deck *ops)
{
	t_ps_subseq	*top;
	t_ps_node	*tmp;
	int			check;
	int			count;
	int			n_node;

	if (a->n_subseq == 0)
		return (1);
	check = 0;
	count = -1;
	n_node = a->top_sub->n_node;
	while (++count < n_node && check == 0)
		check += ps_pb(a, b, ops);
	if (check == 0)
	{
		top = sub_remove_top(a);
		tmp = top->bottom;
		top->bottom = top->top;
		top->top = tmp;
		sub_add_top(b, top);
	}
	return (check);
}

int	ps_sub_pbrb(t_ps_deck *a, t_ps_deck *b, t_ops_deck *ops)
{
	t_ps_subseq	*top;
	t_ps_node	*tmp;
	int			check;
	int			count;
	int			n_node;

	if (a->n_subseq == 0)
		return (1);
	check = 0;
	count = 0;
	n_node = a->top_sub->n_node;
	while (count < n_node && check == 0)
	{
		check += ps_pb(a, b, ops);
		if (check == 0)
			check += ps_rb(b, ops);
		count++;
	}
	if (check == 0)
	{
		top = sub_remove_top(a);
		sub_add_bottom(b, top);
	}
	return (check);
}

int	ps_sub_para(t_ps_deck *a, t_ps_deck *b, t_ops_deck *ops)
{
	t_ps_subseq	*top;
	t_ps_node	*tmp;
	int			check;
	int			count;
	int			n_node;

	if (b->n_subseq == 0)
		return (1);
	check = 0;
	count = 0;
	n_node = b->top_sub->n_node;
	while (count < n_node && check == 0)
	{
		check += ps_pa(a, b, ops);
		if (check == 0)
			check += ps_ra(a, ops);
		count++;
	}
	if (check == 0)
	{
		top = sub_remove_top(b);
		sub_add_bottom(a, top);
	}
	return (check);
}
