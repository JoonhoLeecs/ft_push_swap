/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_subseq.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 10:51:54 by joonhlee          #+#    #+#             */
/*   Updated: 2023/04/19 12:44:00 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	print_sub_info(t_ps_node *top, t_ps_node *bottom, int n, int ind);

t_ps_subseq	*sub_new(t_ps_node *top, t_ps_node *bottom, int n, int ind)
{
	t_ps_subseq	*new_sub;
	t_ps_node	*tmp;

	new_sub = (t_ps_subseq *)malloc(sizeof(t_ps_subseq));
	if (new_sub == 0)
		return (0);
	new_sub->sub_ind = ind;
	new_sub->n_node = n;
	new_sub->divide = 0;
	new_sub->top = top;
	new_sub->bottom = bottom;
	new_sub->next_sub = 0;
	new_sub->prev_sub = 0;
	tmp = top;
	while (tmp->raw != bottom->raw)
	{
		tmp->sub_ind = ind;
		tmp = tmp->next;
	}
	bottom->sub_ind = ind;
	return (new_sub);
}

void	sub_add_top(t_ps_deck *a, t_ps_subseq *sub)
{
	a->n_subseq += 1;
	if (a->top_sub == 0)
	{
		a->top_sub = sub;
		a->bottom_sub = sub;
	}
	else
	{
		a->top_sub->prev_sub = sub;
		sub->next_sub = a->top_sub;
		a->top_sub = sub;
	}
}

void	sub_add_bottom(t_ps_deck *a, t_ps_subseq *sub)
{
	a->n_subseq += 1;
	if (a->bottom_sub == 0)
	{
		a->top_sub = sub;
		a->bottom_sub = sub;
	}
	else
	{
		a->bottom_sub->next_sub = sub;
		sub->prev_sub = a->bottom_sub;
		a->bottom_sub = sub;
	}
}

t_ps_subseq	*sub_remove_top(t_ps_deck *deck)
{
	t_ps_subseq	*top_to_remove;

	if (deck == 0 || deck->top_sub == 0)
		return (0);
	top_to_remove = deck->top_sub;
	deck->n_subseq -= 1;
	deck->top_sub = top_to_remove->next_sub;
	if (deck->top_sub == 0)
		deck->bottom_sub = 0;
	if (deck->top_sub != 0)
		deck->top_sub->prev_sub = 0;
	top_to_remove->next_sub = 0;
	return (top_to_remove);
}

t_ps_subseq	*sub_remove_bottom(t_ps_deck *deck)
{
	t_ps_subseq	*bottom_to_remove;

	if (deck == 0 || deck->bottom_sub == 0)
		return (0);
	bottom_to_remove = deck->bottom_sub;
	deck->n_subseq -= 1;
	deck->bottom_sub = bottom_to_remove->prev_sub;
	if (deck->bottom_sub == 0)
		deck->top_sub = 0;
	if (deck->bottom_sub != 0)
		deck->bottom_sub->next_sub = 0;
	bottom_to_remove->prev_sub = 0;
	return (bottom_to_remove);
}
