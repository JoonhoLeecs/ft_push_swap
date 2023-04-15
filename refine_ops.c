/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refine_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 13:33:05 by joonhlee          #+#    #+#             */
/*   Updated: 2023/04/15 18:58:22 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	refine_ops(t_ops_deck *ops)
{
	if (ops->head == 0)
		return ;
	if (ops->head->next == 0)
		return ;
	combine_to_rr(ops);
	combine_to_rrr(ops);
	combine_to_ss(ops);
}

void	combine_to_rr(t_ops_deck *ops)
{
	t_op_node	*top;
	t_op_node	*bottom;
	int			ra_count;
	int			rb_count;

	top = ops->head;
	while (top)
	{
		if (!(is_op(top, "ra\n") || is_op(top, "rb\n")))
			top = top->next;
		else
		{
			ra_count = 0;
			rb_count = 0;
			bottom = top;
			while (bottom && (is_op(bottom, "ra\n") || is_op(bottom, "rb\n")))
			{
				ra_count += is_op(bottom, "ra\n");
				rb_count += is_op(bottom, "rb\n");
				bottom = bottom->next;
			}
			replace_to_rr(top, bottom, ra_count, rb_count);
			top = bottom;
		}
	}
}

int	is_op(t_op_node *op_node, char *op)
{
	if (ft_strcmp(op_node->op, op) == 0)
		return (1);
	else
		return (0);
}

void	replace_to_rr(t_op_node *top, t_op_node *bottom, int ra, int rb)
{
	t_op_node	*op_iter;
	int			i;
	int			rr;

	op_iter = top;
	rr = (ra >= rb) * rb + (ra < rb) * ra;
	if (rr == 0)
		return ;
	op_iter = overwrite_n_op(op_iter, "rr\n", rr);
	if (ra > rr)
		op_iter = overwrite_n_op(op_iter, "ra\n", ra - rr);
	if (rb > rr)
		op_iter = overwrite_n_op(op_iter, "rb\n", rb - rr);
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

t_op_node	*overwrite_n_op(t_op_node *start, char *op_str, int n)
{
	int			i;
	t_op_node	*op_iter;

	i = 0;
	op_iter = start;
	while (op_iter && i < n)
	{
		ft_strlcpy(op_iter->op, op_str, 5);
		op_iter = op_iter->next;
		i++;
	}
	return (op_iter);
}
