/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_ss.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 17:26:39 by joonhlee          #+#    #+#             */
/*   Updated: 2023/04/12 19:10:09 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_sa(t_ps_deck *a, t_ops_deck *ops)
{
	t_oplst		*new_oplst;
	t_ps_node	*top_node;
	t_ps_node	*second_node;

	new_oplst = ps_new_oplst("sa\n");
	if (new_oplst == 0)
		return (1);
	if (a->top == 0)
		return (1);
	if (a->top->next == 0)
		return (1);
	top_node = ps_remove_top(a);
	second_node = ps_remove_top(a);
	ps_add_top(a, top_node);
	ps_add_top(a, second_node);
	ops_add_back(ops, new_oplst);
	return (0);
}

int	ps_sb(t_ps_deck *b, t_ops_deck *ops)
{
	t_oplst		*new_oplst;
	t_ps_node	*top_node;
	t_ps_node	*second_node;

	new_oplst = ps_new_oplst("sb\n");
	if (new_oplst == 0)
		return (1);
	if (b->top == 0)
		return (1);
	if (b->top->next == 0)
		return (1);
	top_node = ps_remove_top(b);
	second_node = ps_remove_top(b);
	ps_add_top(b, top_node);
	ps_add_top(b, second_node);
	ops_add_back(ops, new_oplst);
	return (0);
}

int	ps_ss(t_ps_deck *a, t_ps_deck *b, t_ops_deck *ops)
{
	t_oplst		*new_oplst;
	t_ps_node	*top_node;
	t_ps_node	*second_node;

	new_oplst = ps_new_oplst("ss\n");
	if (new_oplst == 0)
		return (1);
	if (a->top == 0 || b->top == 0)
		return (1);
	if (a->top->next == 0 || b->top->next == 0)
		return (1);
	top_node = ps_remove_top(a);
	second_node = ps_remove_top(a);
	ps_add_top(a, top_node);
	ps_add_top(a, second_node);
	top_node = ps_remove_top(b);
	second_node = ps_remove_top(b);
	ps_add_top(b, top_node);
	ps_add_top(b, second_node);
	ops_add_back(ops, new_oplst);
	return (0);
}
