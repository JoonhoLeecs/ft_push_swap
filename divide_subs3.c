/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_subs3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 17:09:49 by joonhlee          #+#    #+#             */
/*   Updated: 2023/04/19 08:00:53 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ds_merge(t_ps_deck *a, t_ps_deck *b, t_ops_deck *ops, int *nf)
{
	int	diff_n_sub;
	int	check;
	int	count;

	check = 0;
	count = 0;
	diff_n_sub = a->n_subseq + b->n_subseq - *nf * 2;
	if (a->n_subseq > 1 && b->n_subseq > 1 && find_next_inc_dec(a->top) >= 0
		&& find_next_inc_dec(b->top) >= 0 && find_next_inc_dec(b->bottom_sub->top) >= 0
		&& find_next_inc_dec(a->bottom_sub->top) >= 0
		&& find_next_inc_dec(a->top_sub->next_sub->top) > 0
		&& find_next_inc_dec(b->top_sub->next_sub->top) > 0)
		{
			// if (count_ba(b, a) < count_ba(a, b) && diff_n_sub > 0)
			// if (check_a_tops(b, a) && count == 0 && check == 0 && diff_n_sub < 0)
			if (check_a_tops(b, a))
			{
				check += merge_b_tops(b, ops);
				*nf -= 1;
				count += 1;
			}
			// if (check_a_tops(a, b) && find_next_inc_dec(a->top_sub->next_sub->top) > 0 && diff_n_sub > 0)
			if (count == 0 && check == 0 && check_a_tops(a, b))
			{
				check += merge_a_tops(a, ops);
				count += 1;
			}
			// if (count_ba(b, a) <= count_ba(a, b) && count == 0 && check == 0 && diff_n_sub > 0)
			if (count == 0 && check == 0 && count_ba(b, a) <= count_ba(a, b))
			{
				check += tw_merge_ab(a, b, ops);
				count += 1;
			}
			// if (count_ba(b, a) > count_ba(a, b) && diff_n_sub < 0)
			// if (count_ba(b, a) > count_ba(a, b) && count == 0 && check == 0 && diff_n_sub < 0)
			if (count == 0 && check == 0 && count_ba(b, a) > count_ba(a, b))
			{
				check += tw_merge_ba(a, b, ops);
				*nf -= 1;
				count += 1;
			}
	}
	if (count == 0 && check == 0)
		check += ds_better_rasa(a, ops);
	return (check);
}
