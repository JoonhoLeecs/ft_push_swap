/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_papb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 17:46:58 by joonhlee          #+#    #+#             */
/*   Updated: 2023/04/14 11:01:27 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_pa(t_ps_deck *a, t_ps_deck *b, t_ops_deck *ops)
{
	t_op_node	*new_op_node;
	t_ps_node	*top_node;

	new_op_node = ops_new_node("pa\n");
	if (new_op_node == 0)
		return (1);
	if (b->top == 0)
		return (ps_free_error(new_op_node));
	top_node = ps_remove_top(b);
	ps_add_top(a, top_node);
	ops_add_back(ops, new_op_node);
	return (0);
}

int	ps_pb(t_ps_deck *a, t_ps_deck *b, t_ops_deck *ops)
{
	t_op_node	*new_op_node;
	t_ps_node	*top_node;

	new_op_node = ops_new_node("pb\n");
	if (new_op_node == 0)
		return (1);
	if (a->top == 0)
		return (ps_free_error(new_op_node));
	top_node = ps_remove_top(a);
	ps_add_top(b, top_node);
	ops_add_back(ops, new_op_node);
	return (0);
}
