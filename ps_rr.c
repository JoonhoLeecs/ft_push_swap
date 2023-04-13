/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 17:51:49 by joonhlee          #+#    #+#             */
/*   Updated: 2023/04/12 19:11:09 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_ra(t_ps_deck *a, t_ops_deck *ops)
{
	t_oplst		*new_oplst;
	t_ps_node	*top_node;

	new_oplst = ps_new_oplst("ra\n");
	if (new_oplst == 0)
		return (1);
	if (a->top == 0)
		return (1);
	if (a->n_node == 1)
		return (1);
	top_node = ps_remove_top(a);
	ps_add_bottom(a, top_node);
	ops_add_back(ops, new_oplst);
	return (0);
}

int	ps_rb(t_ps_deck *b, t_ops_deck *ops)
{
	t_oplst		*new_oplst;
	t_ps_node	*top_node;

	new_oplst = ps_new_oplst("rb\n");
	if (new_oplst == 0)
		return (1);
	if (b->top == 0)
		return (1);
	if (b->n_node == 1)
		return (1);
	top_node = ps_remove_top(b);
	ps_add_bottom(b, top_node);
	ops_add_back(ops, new_oplst);
	return (0);
}

int	ps_rr(t_ps_deck *a, t_ps_deck *b, t_ops_deck *ops)
{
	t_oplst		*new_oplst;
	t_ps_node	*top_node;

	new_oplst = ps_new_oplst("rr\n");
	if (new_oplst == 0)
		return (1);
	if (a->top == 0 || b->top == 0)
		return (1);
	if (a->n_node == 1 || b->n_node == 1)
		return (1);
	top_node = ps_remove_top(a);
	ps_add_bottom(a, top_node);
	top_node = ps_remove_top(b);
	ps_add_bottom(b, top_node);
	ops_add_back(ops, new_oplst);
	return (0);
}
