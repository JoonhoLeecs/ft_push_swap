/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_papb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 17:46:58 by joonhlee          #+#    #+#             */
/*   Updated: 2023/04/12 19:08:31 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_pa(t_ps_deck *a, t_ps_deck *b, t_ops_deck *ops)
{
	t_oplst		*new_oplst;
	t_ps_node	*top_node;

	new_oplst = ps_new_oplst("pa\n");
	if (new_oplst == 0)
		return (1);
	if (b->top == 0)
		return (1);
	top_node = ps_remove_top(b);
	ps_add_top(a, top_node);
	ops_add_back(ops, new_oplst);
	return (0);
}

int	ps_pb(t_ps_deck *a, t_ps_deck *b, t_ops_deck *ops)
{
	t_oplst		*new_oplst;
	t_ps_node	*top_node;

	new_oplst = ps_new_oplst("pb\n");
	if (new_oplst == 0)
		return (1);
	if (a->top == 0)
		return (1);
	top_node = ps_remove_top(a);
	ps_add_top(b, top_node);
	ops_add_back(ops, new_oplst);
	return (0);
}
