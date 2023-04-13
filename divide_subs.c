/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_subs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 14:46:21 by joonhlee          #+#    #+#             */
/*   Updated: 2023/04/13 18:00:24 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	divide_subs(t_ps_deck *a, t_ps_deck *b, t_ops_deck *ops)
{
	int	check;
	int	last_raw;

	if (a->n_subseq == 1 && a->top_sub->sub_ind == 1)
		return (0);
	if (a->n_subseq == 1 && a->top_sub->sub_ind == -1)
		return (ps_reverse_ra(a, b, ops));
	check = 0;
	last_raw = calc_divide(a);
	while (b->top->raw != last_raw && b->bottom->raw != last_raw && check == 0)
	{
		if (a->top_sub->divide == 0 && a->top_sub->sub_ind > 0)
			check += ps_sub_ra(a, ops);
		else if (a->top_sub->divide == 0 && a->top_sub->sub_ind < 0)
			check += ps_reverse_ra(a, b, ops);
		else if (a->top_sub->divide == 1 && a->top_sub->sub_ind < 0)
			check += ps_sub_pb(a, b, ops);
		else
			check += ps_sub_pbrb(a, b, ops);
	}
	if (a->n_subseq == 1 && a->top_sub->sub_ind < 0 && check == 0)
		check += ps_reverse_ra(a, b, ops);
	return (check);
}

int	calc_divide(t_ps_deck *a)
{

}

int	ps_reverse_ra(t_ps_deck *a, t_ps_deck *b, t_ops_deck *ops)
{
	int	check;

	if (a->n_subseq == 0)
		return (1);
	check = ps_sub_pb(a, b, ops);
	if (check == 0)
		check += ps_sub_para(a, b, ops);
	return (check);


}
