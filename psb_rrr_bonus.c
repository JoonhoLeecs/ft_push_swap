/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psb_rrr_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 17:59:04 by joonhlee          #+#    #+#             */
/*   Updated: 2023/04/23 15:32:39 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	psb_rra(t_ps_deque *a)
{
	t_ps_node	*bottom_node;

	if (a->top == 0)
		return (0);
	if (a->n_node == 1)
		return (0);
	bottom_node = ps_remove_bottom(a);
	ps_add_top(a, bottom_node);
	return (0);
}

int	psb_rrb(t_ps_deque *b)
{
	t_ps_node	*bottom_node;

	if (b->top == 0)
		return (0);
	if (b->n_node == 1)
		return (0);
	bottom_node = ps_remove_bottom(b);
	ps_add_top(b, bottom_node);
	return (0);
}

int	psb_rrr(t_ps_deque *a, t_ps_deque *b)
{
	t_ps_node	*bottom_node;

	if (a->top == 0 || b->top == 0)
		return (0);
	if (a->n_node == 1 || b->n_node == 1)
		return (0);
	bottom_node = ps_remove_bottom(a);
	ps_add_top(a, bottom_node);
	bottom_node = ps_remove_bottom(b);
	ps_add_top(b, bottom_node);
	return (0);
}
