/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_deck_remove.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:55:42 by joonhlee          #+#    #+#             */
/*   Updated: 2023/04/12 10:28:19 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ps_node	*ps_remove_top(t_ps_deck *deck)
{
	t_ps_node	*top_to_remove;

	if (deck == 0 || deck->top == 0)
		return (0);
	top_to_remove = deck->top;
	deck->n_node -= 1;
	deck->top = top_to_remove->next;
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
	if (deck->bottom != 0)
		deck->bottom->next = 0;
	bottom_to_remove->prev = 0;
	return (bottom_to_remove);
}
