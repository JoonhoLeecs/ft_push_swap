/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psb_rr_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 17:51:49 by joonhlee          #+#    #+#             */
/*   Updated: 2023/04/23 15:32:27 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	psb_ra(t_ps_deque *a)
{
	t_ps_node	*top_node;

	if (a->top == 0)
		return (0);
	if (a->n_node == 1)
		return (0);
	top_node = ps_remove_top(a);
	ps_add_bottom(a, top_node);
	return (0);
}

int	psb_rb(t_ps_deque *b)
{
	t_ps_node	*top_node;

	if (b->top == 0)
		return (0);
	if (b->n_node == 1)
		return (0);
	top_node = ps_remove_top(b);
	ps_add_bottom(b, top_node);
	return (0);
}

int	psb_rr(t_ps_deque *a, t_ps_deque *b)
{
	t_ps_node	*top_node;

	if (a->top == 0 || b->top == 0)
		return (0);
	if (a->n_node == 1 || b->n_node == 1)
		return (0);
	top_node = ps_remove_top(a);
	ps_add_bottom(a, top_node);
	top_node = ps_remove_top(b);
	ps_add_bottom(b, top_node);
	return (0);
}
