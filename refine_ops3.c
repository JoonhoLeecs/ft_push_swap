/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refine_ops3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 14:35:16 by joonhlee          #+#    #+#             */
/*   Updated: 2023/04/23 13:02:41 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	erase_ra_rra(t_ops_deque *ops)
{
	t_op_node	*top;
	t_op_node	*bottom;
	int			n_ra;
	int			n_rra;

	top = ops->head;
	while (top && top->next)
	{
		if ((is_op(top->next, "ra\n") == 0 && is_op(top->next, "rra\n") == 0)
			|| top->next->next == 0)
			top = top->next;
		else
		{
			n_ra = is_op(top->next, "ra\n") + is_op(top->next->next, "ra\n");
			n_rra = is_op(top->next, "rra\n") + is_op(top->next->next, "rra\n");
			bottom = top->next->next->next;
			if (n_ra == 1 && n_rra == 1)
			{
				erase_r_rr(top, bottom);
				top = bottom;
			}
			else
				top = top->next;
		}
	}
}

void	erase_rb_rrb(t_ops_deque *ops)
{
	t_op_node	*top;
	t_op_node	*bottom;
	int			n_ra;
	int			n_rra;

	top = ops->head;
	while (top && top->next)
	{
		if ((is_op(top->next, "rb\n") == 0 && is_op(top->next, "rrb\n") == 0)
			|| top->next->next == 0)
			top = top->next;
		else
		{
			n_ra = is_op(top->next, "rb\n") + is_op(top->next->next, "rb\n");
			n_rra = is_op(top->next, "rrb\n") + is_op(top->next->next, "rrb\n");
			bottom = top->next->next->next;
			if (n_ra == 1 && n_rra == 1)
			{
				erase_r_rr(top, bottom);
				top = bottom;
			}
			else
				top = top->next;
		}
	}
}

void	erase_r_rr(t_op_node *top, t_op_node *bottom)
{
	t_op_node	*op_iter;

	op_iter = top->next->next;
	ops_clear_node(op_iter);
	op_iter = top->next;
	ops_clear_node(op_iter);
	if (bottom)
		bottom->prev = top;
	top->next = bottom;
}
