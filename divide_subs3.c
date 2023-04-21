/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_subs3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 14:46:21 by joonhlee          #+#    #+#             */
/*   Updated: 2023/04/21 14:24:26 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ds_realign(t_ps_deck *b, t_ops_deck *ops)
{
	int	check;
	int	direction;

	if (b->bottom_sub->divide == 0)
		return (0);
	direction = ds_find_rb_rrb(b);
	check = 0;
	while (direction > 0 && b->bottom_sub->divide != 0 && check == 0)
		check = ps_sub_rb(b, ops);
	while (direction <= 0 && b->bottom_sub->divide != 0 && check == 0)
		check = ps_sub_rrb(b, ops);
	return (check);
}

int	ds_find_rb_rrb(t_ps_deck *b)
{
	t_ps_subseq	*sub_iter;
	int			rb;
	int			rrb;

	sub_iter = b->top_sub;
	rb = 0;
	while (sub_iter)
	{
		rb += sub_iter->n_node;
		if (sub_iter->divide == 0)
			break ;
		sub_iter = sub_iter->next_sub;
	}
	sub_iter = b->bottom_sub;
	rrb = 0;
	while (sub_iter)
	{
		if (sub_iter->divide == 0)
			break ;
		rrb += sub_iter->n_node;
		sub_iter = sub_iter->prev_sub;
	}
	return (rrb - rb);
}
