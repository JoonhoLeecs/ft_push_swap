/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_subs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 10:26:48 by joonhlee          #+#    #+#             */
/*   Updated: 2023/04/13 17:31:13 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_next_inc_dec(t_ps_node *a);
t_ps_subseq	*as_next(t_ps_node **top, t_ps_node **bottom, int *inc, int *dec);

int	assign_subs(t_ps_deck *a)
{
	t_ps_node	*sub_top;
	t_ps_node	*sub_bottom;
	int			inc_sub_ind;
	int			dec_sub_ind;
	t_ps_subseq	*new_sub;

	sub_top = a->top;
	sub_bottom = a->top;
	inc_sub_ind = 0;
	dec_sub_ind = 0;
	while (sub_top != 0)
	{
		new_sub = as_next(&sub_top, &sub_bottom, &inc_sub_ind, &dec_sub_ind);
		if (new_sub == 0)
			return (1);
		sub_add_bottom(a, new_sub);
		sub_top = sub_bottom->next;
		sub_bottom = sub_bottom->next;
	}
	return (0);
}

t_ps_subseq	*as_next(t_ps_node **top, t_ps_node **bottom, int *inc, int *dec)
{
	int	current;

	current = find_next_inc_dec(*bottom);
	while ((*bottom)->next)
	{
		if (current * find_next_inc_dec(*bottom) > 0)
		{
			current += find_next_inc_dec(*bottom);
			*bottom = (*bottom)->next;
		}
		else
			break ;
	}
	if (current > 0)
	{
		*inc += 1;
		return (sub_new(*top, *bottom, current, *inc));
	}
	else if (current < 0)
	{
		*dec += 1;
		return (sub_new(*top, *bottom, -1 * current, -1 * (*dec)));
	}
	else
		return (sub_new(*top, *bottom, 1, ++(*inc)));
}

static int	find_next_inc_dec(t_ps_node *a)
{
	if (a->next == 0)
		return (0);
	if (a->next->raw > a->raw)
		return (1);
	else
		return (-1);
}
