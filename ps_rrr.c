/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rrr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 17:59:04 by joonhlee          #+#    #+#             */
/*   Updated: 2023/04/23 12:45:18 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_rra(t_ps_deque *a, t_ops_deque *ops)
{
	t_op_node	*new_op_node;
	t_ps_node	*bottom_node;

	new_op_node = ops_new_node("rra\n");
	if (new_op_node == 0)
		return (1);
	if (a->top == 0)
		return (ps_free_error(new_op_node));
	if (a->n_node == 1)
		return (0);
	bottom_node = ps_remove_bottom(a);
	ps_add_top(a, bottom_node);
	ops_add_back(ops, new_op_node);
	return (0);
}

int	ps_rrb(t_ps_deque *b, t_ops_deque *ops)
{
	t_op_node	*new_op_node;
	t_ps_node	*bottom_node;

	new_op_node = ops_new_node("rrb\n");
	if (new_op_node == 0)
		return (1);
	if (b->top == 0)
		return (ps_free_error(new_op_node));
	if (b->n_node == 1)
		return (0);
	bottom_node = ps_remove_bottom(b);
	ps_add_top(b, bottom_node);
	ops_add_back(ops, new_op_node);
	return (0);
}

int	ps_rrr(t_ps_deque *a, t_ps_deque *b, t_ops_deque *ops)
{
	t_op_node	*new_op_node;
	t_ps_node	*bottom_node;

	new_op_node = ops_new_node("rrr\n");
	if (new_op_node == 0)
		return (1);
	if (a->top == 0 || b->top == 0)
		return (ps_free_error(new_op_node));
	if (a->n_node == 1 || b->n_node == 1)
		return (ps_free_error(new_op_node));
	bottom_node = ps_remove_bottom(a);
	ps_add_top(a, bottom_node);
	bottom_node = ps_remove_bottom(b);
	ps_add_top(b, bottom_node);
	ops_add_back(ops, new_op_node);
	return (0);
}
