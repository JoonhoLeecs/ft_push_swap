/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psb_ppss_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 17:46:58 by joonhlee          #+#    #+#             */
/*   Updated: 2023/04/23 15:27:43 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	psb_pa(t_ps_deque *a, t_ps_deque *b)
{
	t_ps_node	*top_node;

	if (b->top == 0)
		return (0);
	top_node = ps_remove_top(b);
	ps_add_top(a, top_node);
	return (0);
}

int	psb_pb(t_ps_deque *a, t_ps_deque *b)
{
	t_ps_node	*top_node;

	if (a->top == 0)
		return (0);
	top_node = ps_remove_top(a);
	ps_add_top(b, top_node);
	return (0);
}

int	psb_sa(t_ps_deque *a)
{
	t_ps_node	*top_node;
	t_ps_node	*second_node;

	if (a->top == 0)
		return (0);
	if (a->top->next == 0)
		return (0);
	top_node = ps_remove_top(a);
	second_node = ps_remove_top(a);
	ps_add_top(a, top_node);
	ps_add_top(a, second_node);
	return (0);
}

int	psb_sb(t_ps_deque *b)
{
	t_ps_node	*top_node;
	t_ps_node	*second_node;

	if (b->top == 0)
		return (0);
	if (b->top->next == 0)
		return (0);
	top_node = ps_remove_top(b);
	second_node = ps_remove_top(b);
	ps_add_top(b, top_node);
	ps_add_top(b, second_node);
	return (0);
}

int	psb_ss(t_ps_deque *a, t_ps_deque *b)
{
	t_ps_node	*top_node;
	t_ps_node	*second_node;

	if (a->top == 0 || b->top == 0)
		return (0);
	if (a->top->next == 0 || b->top->next == 0)
		return (0);
	top_node = ps_remove_top(a);
	second_node = ps_remove_top(a);
	ps_add_top(a, top_node);
	ps_add_top(a, second_node);
	top_node = ps_remove_top(b);
	second_node = ps_remove_top(b);
	ps_add_top(b, top_node);
	ps_add_top(b, second_node);
	return (0);
}
