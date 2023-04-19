/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_subs3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 17:09:49 by joonhlee          #+#    #+#             */
/*   Updated: 2023/04/19 09:44:01 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ds_merge(t_ps_deck *a, t_ps_deck *b, t_ops_deck *ops, int *nf)
{
	if (ds_merge_condition(a, b) == 1)
	{
		if (check_a_tops(b, a))
		{
			*nf -= 1;
			return (merge_b_tops(b, ops));
		}
		else if (check_a_tops(a, b))
			return (merge_a_tops(a, ops));
		else if (count_ba(b, a) <= count_ba(a, b))
			return (tw_merge_ab(a, b, ops));
		else if (count_ba(b, a) > count_ba(a, b))
		{
			*nf -= 1;
			return (tw_merge_ba(a, b, ops));
		}
	}
	return (ds_better_rasa(a, ops));
}

int	ds_merge_condition(t_ps_deck *a, t_ps_deck *b)
{
	if (a->n_subseq > 1 && b->n_subseq > 1 && find_next_inc_dec(a->top) >= 0
		&& find_next_inc_dec(b->bottom_sub->top) >= 0
		&& find_next_inc_dec(b->top) >= 0
		&& find_next_inc_dec(a->bottom_sub->top) >= 0
		&& find_next_inc_dec(a->top_sub->next_sub->top) > 0
		&& find_next_inc_dec(b->top_sub->next_sub->top) > 0)
		return (1);
	else
		return (0);
}
