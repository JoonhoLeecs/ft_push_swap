/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_deck2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:53:16 by joonhlee          #+#    #+#             */
/*   Updated: 2023/04/14 09:58:38 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_add_top(t_ps_deck *deck, t_ps_node *new)
{
	if (deck == 0)
		return ;
	deck->n_node += 1;
	if (deck->top == 0)
	{
		deck->top = new;
		deck->bottom = new;
	}
	else
	{
		deck->top->prev = new;
		new->next = deck->top;
		deck->top = new;
	}
}

void	ps_add_bottom(t_ps_deck *deck, t_ps_node *new)
{
	if (deck == 0)
		return ;
	deck->n_node += 1;
	if (deck->bottom == 0)
	{
		deck->top = new;
		deck->bottom = new;
	}
	else
	{
		deck->bottom->next = new;
		new->prev = deck->bottom;
		deck->bottom = new;
	}
}

t_ps_node	*ps_remove_top(t_ps_deck *deck)
{
	t_ps_node	*top_to_remove;

	if (deck == 0 || deck->top == 0)
		return (0);
	top_to_remove = deck->top;
	deck->n_node -= 1;
	deck->top = top_to_remove->next;
	if (deck->top == 0)
		deck->bottom = 0;
	if (deck->top != 0)
		deck->top->prev = 0;
	top_to_remove->next = 0;
	return (top_to_remove);
}

t_ps_node	*ps_remove_bottom(t_ps_deck *deck)
{
	t_ps_node	*bottom_to_remove;

	if (deck == 0 || deck->bottom == 0)
		return (0);
	bottom_to_remove = deck->bottom;
	deck->n_node -= 1;
	deck->bottom = bottom_to_remove->prev;
	if (deck->bottom == 0)
		deck->top = 0;
	if (deck->bottom != 0)
		deck->bottom->next = 0;
	bottom_to_remove->prev = 0;
	return (bottom_to_remove);
}
