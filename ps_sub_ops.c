/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sub_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:44:22 by joonhlee          #+#    #+#             */
/*   Updated: 2023/04/21 13:57:20 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	ps_sub_rb(t_ps_deck *b, t_ops_deck *ops)
{
	t_ps_subseq	*top;
	int			check;
	int			count;
	int			n_node;

	if (b->n_subseq == 0)
		return (1);
	if (b->n_subseq == 1)
		return (0);
	check = 0;
	count = -1;
	n_node = b->top_sub->n_node;
	while (++count < n_node && check == 0)
		check += ps_rb(b, ops);
	if (check == 0)
	{
		top = sub_remove_top(b);
		sub_add_bottom(b, top);
	}
	return (check);
}

int	ps_sub_rrb(t_ps_deck *b, t_ops_deck *ops)
{
	t_ps_subseq	*bottom;
	int			check;
	int			count;
	int			n_node;

	if (b->n_subseq == 0)
		return (1);
	if (b->n_subseq == 1)
		return (0);
	check = 0;
	count = -1;
	n_node = b->bottom_sub->n_node;
	while (++count < n_node && check == 0)
		check += ps_rrb(b, ops);
	if (check == 0)
	{
		bottom = sub_remove_bottom(b);
		sub_add_top(b, bottom);
	}
	return (check);
}

int	ps_sub_pa(t_ps_deck *a, t_ps_deck *b, t_ops_deck *ops)
{
	t_ps_subseq	*top;
	t_ps_node	*tmp;
	int			check;
	int			count;
	int			n_node;

	if (b->n_subseq == 0)
		return (1);
	check = 0;
	count = -1;
	n_node = b->top_sub->n_node;
	while (++count < n_node && check == 0)
		check += ps_pa(a, b, ops);
	if (check == 0)
	{
		top = sub_remove_top(b);
		tmp = top->bottom;
		top->bottom = top->top;
		top->top = tmp;
		top->sub_ind = top->sub_ind * -1;
		sub_add_top(a, top);
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
		top->sub_ind = top->sub_ind * -1;
		sub_add_top(b, top);
	}
	return (check);
}
