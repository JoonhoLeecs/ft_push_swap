/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_ss.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 17:26:39 by joonhlee          #+#    #+#             */
/*   Updated: 2023/04/14 11:01:06 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_sa(t_ps_deck *a, t_ops_deck *ops)
{
	t_op_node	*new_op_node;
	t_ps_node	*top_node;
	t_ps_node	*second_node;

	new_op_node = ops_new_node("sa\n");
	if (new_op_node == 0)
		return (1);
	if (a->top == 0)
		return (ps_free_error(new_op_node));
	if (a->top->next == 0)
		return (ps_free_error(new_op_node));
	top_node = ps_remove_top(a);
	second_node = ps_remove_top(a);
	ps_add_top(a, top_node);
	ps_add_top(a, second_node);
	ops_add_back(ops, new_op_node);
	return (0);
}

int	ps_sb(t_ps_deck *b, t_ops_deck *ops)
{
	t_op_node	*new_op_node;
	t_ps_node	*top_node;
	t_ps_node	*second_node;

	new_op_node = ops_new_node("sb\n");
	if (new_op_node == 0)
		return (1);
	if (b->top == 0)
		return (ps_free_error(new_op_node));
	if (b->top->next == 0)
		return (ps_free_error(new_op_node));
	top_node = ps_remove_top(b);
	second_node = ps_remove_top(b);
	ps_add_top(b, top_node);
	ps_add_top(b, second_node);
	ops_add_back(ops, new_op_node);
	return (0);
}

int	ps_ss(t_ps_deck *a, t_ps_deck *b, t_ops_deck *ops)
{
	t_op_node	*new_op_node;
	t_ps_node	*top_node;
	t_ps_node	*second_node;

	new_op_node = ops_new_node("ss\n");
	if (new_op_node == 0)
		return (1);
	if (a->top == 0 || b->top == 0)
		return (ps_free_error(new_op_node));
	if (a->top->next == 0 || b->top->next == 0)
		return (ps_free_error(new_op_node));
	top_node = ps_remove_top(a);
	second_node = ps_remove_top(a);
	ps_add_top(a, top_node);
	ps_add_top(a, second_node);
	top_node = ps_remove_top(b);
	second_node = ps_remove_top(b);
	ps_add_top(b, top_node);
	ps_add_top(b, second_node);
	ops_add_back(ops, new_op_node);
	return (0);
}

int	ps_free_error(t_op_node *new)
{
	ops_clear_node(new);
	return (1);
}
