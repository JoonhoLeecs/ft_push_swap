/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rrr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 17:59:04 by joonhlee          #+#    #+#             */
/*   Updated: 2023/04/12 19:11:47 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_rra(t_ps_deck *a, t_ops_deck *ops)
{
	t_oplst		*new_oplst;
	t_ps_node	*bottom_node;

	new_oplst = ps_new_oplst("rra\n");
	if (new_oplst == 0)
		return (1);
	if (a->top == 0)
		return (1);
	if (a->n_node == 1)
		return (1);
	bottom_node = ps_remove_bottom(a);
	ps_add_top(a, bottom_node);
	ops_add_back(ops, new_oplst);
	return (0);
}

int	ps_rrb(t_ps_deck *b, t_ops_deck *ops)
{
	t_oplst		*new_oplst;
	t_ps_node	*bottom_node;

	new_oplst = ps_new_oplst("rrb\n");
	if (new_oplst == 0)
		return (1);
	if (b->top == 0)
		return (1);
	if (b->n_node == 1)
		return (1);
	bottom_node = ps_remove_bottom(b);
	ps_add_top(b, bottom_node);
	ops_add_back(ops, new_oplst);
	return (0);
}

int	ps_rrr(t_ps_deck *a, t_ps_deck *b, t_ops_deck *ops)
{
	t_oplst		*new_oplst;
	t_ps_node	*bottom_node;

	new_oplst = ps_new_oplst("rrr\n");
	if (new_oplst == 0)
		return (1);
	if (a->top == 0 || b->top == 0)
		return (1);
	if (a->n_node == 1 || b->n_node == 1)
		return (1);
	bottom_node = ps_remove_bottom(a);
	ps_add_top(a, bottom_node);
	bottom_node = ps_remove_bottom(b);
	ps_add_top(b, bottom_node);
	ops_add_back(ops, new_oplst);
	return (0);
}
