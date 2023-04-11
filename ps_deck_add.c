/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_deck_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:53:16 by joonhlee          #+#    #+#             */
/*   Updated: 2023/04/11 18:05:12 by joonhlee         ###   ########.fr       */
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
