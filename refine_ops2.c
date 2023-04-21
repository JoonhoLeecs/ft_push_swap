/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refine_ops2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 14:35:16 by joonhlee          #+#    #+#             */
/*   Updated: 2023/04/21 09:17:30 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	combine_to_rrr(t_ops_deck *ops)
{
	t_op_node	*top;
	t_op_node	*bottom;
	int			ra_count;
	int			rb_count;

	top = ops->head;
	while (top)
	{
		if (is_op(top, "rra\n") == 0 && is_op(top, "rrb\n") == 0)
			top = top->next;
		else
		{
			ra_count = 0;
			rb_count = 0;
			bottom = top;
			while (bottom && (is_op(bottom, "rra\n") || is_op(bottom, "rrb\n")))
			{
				ra_count += is_op(bottom, "rra\n");
				rb_count += is_op(bottom, "rrb\n");
				bottom = bottom->next;
			}
			replace_to_rrr(top, bottom, ra_count, rb_count);
			top = bottom;
		}
	}
}

void	replace_to_rrr(t_op_node *top, t_op_node *bottom, int ra, int rb)
{
	t_op_node	*op_iter;
	int			i;
	int			rr;

	op_iter = top;
	rr = (ra >= rb) * rb + (ra < rb) * ra;
	if (rr == 0)
		return ;
	op_iter = overwrite_n_op(op_iter, "rrr\n", rr);
	if (ra > rr)
		op_iter = overwrite_n_op(op_iter, "rra\n", ra - rr);
	if (rb > rr)
		op_iter = overwrite_n_op(op_iter, "rrb\n", rb - rr);
	(op_iter->prev)->next = bottom;
	if (bottom)
		bottom->prev = op_iter->prev;
	i = 0;
	while (op_iter && i < rr)
	{
		bottom = op_iter;
		ops_clear_node(bottom);
		op_iter = op_iter->next;
		i++;
	}
}

void	combine_to_ss(t_ops_deck *ops)
{
	t_op_node	*top;
	t_op_node	*bottom;
	int			ra_count;
	int			rb_count;

	top = ops->head;
	while (top)
	{
		if ((is_op(top, "sa\n") == 0 && is_op(top, "sb\n") == 0)
			|| top->next == 0)
			top = top->next;
		else
		{
			ra_count = is_op(top, "sa\n") + is_op(top->next, "sa\n");
			rb_count = is_op(top, "sb\n") + is_op(top->next, "sb\n");
			bottom = top->next->next;
			if (ra_count == 1 && rb_count == 1)
			{
				replace_to_ss(top, bottom, ra_count, rb_count);
				top = bottom;
			}
			else
				top = top->next;
		}
	}
}

void	replace_to_ss(t_op_node *top, t_op_node *bottom, int ra, int rb)
{
	t_op_node	*op_iter;
	int			i;
	int			rr;

	op_iter = top;
	rr = (ra >= rb) * rb + (ra < rb) * ra;
	if (rr == 0)
		return ;
	op_iter = overwrite_n_op(op_iter, "ss\n", rr);
	if (ra > rr)
		op_iter = overwrite_n_op(op_iter, "sa\n", ra - rr);
	if (rb > rr)
		op_iter = overwrite_n_op(op_iter, "sb\n", rb - rr);
	(op_iter->prev)->next = bottom;
	if (bottom)
		bottom->prev = op_iter->prev;
	i = 0;
	while (op_iter && i < rr)
	{
		bottom = op_iter;
		ops_clear_node(bottom);
		op_iter = op_iter->next;
		i++;
	}
}
