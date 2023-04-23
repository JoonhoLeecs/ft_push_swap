/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_deque2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:53:16 by joonhlee          #+#    #+#             */
/*   Updated: 2023/04/23 12:53:42 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_add_top(t_ps_deque *deque, t_ps_node *new)
{
	if (deque == 0)
		return ;
	deque->n_node += 1;
	if (deque->top == 0)
	{
		deque->top = new;
		deque->bottom = new;
	}
	else
	{
		deque->top->prev = new;
		new->next = deque->top;
		deque->top = new;
	}
}

void	ps_add_bottom(t_ps_deque *deque, t_ps_node *new)
{
	if (deque == 0)
		return ;
	deque->n_node += 1;
	if (deque->bottom == 0)
	{
		deque->top = new;
		deque->bottom = new;
	}
	else
	{
		deque->bottom->next = new;
		new->prev = deque->bottom;
		deque->bottom = new;
	}
}

t_ps_node	*ps_remove_top(t_ps_deque *deque)
{
	t_ps_node	*top_to_remove;

	if (deque == 0 || deque->top == 0)
		return (0);
	top_to_remove = deque->top;
	deque->n_node -= 1;
	deque->top = top_to_remove->next;
	if (deque->top == 0)
		deque->bottom = 0;
	if (deque->top != 0)
		deque->top->prev = 0;
	top_to_remove->next = 0;
	return (top_to_remove);
}

t_ps_node	*ps_remove_bottom(t_ps_deque *deque)
{
	t_ps_node	*bottom_to_remove;

	if (deque == 0 || deque->bottom == 0)
		return (0);
	bottom_to_remove = deque->bottom;
	deque->n_node -= 1;
	deque->bottom = bottom_to_remove->prev;
	if (deque->bottom == 0)
		deque->top = 0;
	if (deque->bottom != 0)
		deque->bottom->next = 0;
	bottom_to_remove->prev = 0;
	return (bottom_to_remove);
}
