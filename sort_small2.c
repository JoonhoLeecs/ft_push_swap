/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 09:17:00 by joonhlee          #+#    #+#             */
/*   Updated: 2023/04/13 09:29:33 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_four(t_ps_deck *a, t_ps_deck *b, t_ops_deck *ops)
{
	int	check;

	if (is_ordered(a) == 1)
		return (0);
	check = 0;
	check += ps_pb(a, b, ops);
	if (check == 0)
		check += sort_three_a(a, ops);
	if (check == 0)
		check += merge_b_to_a(a, b, ops);
	return (check);
}

int	merge_b_to_a(t_ps_deck *a, t_ps_deck *b, t_ops_deck *ops)
{
	int	check;
	int	max;

	check = 0;
	max = (a->bottom->raw > b->bottom->raw) * (a->bottom->raw)
		+ (a->bottom->raw < b->bottom->raw) * (b->bottom->raw);
	while (b->n_node != 0 && check == 0)
	{
		pstest_print_decks(a, b);
		if ((a->bottom->raw < b->top->raw && is_ordered(a))
			|| a->top->raw > b->top->raw)
		{
			check += ps_pa(a, b, ops);
			if (check == 0)
				check += ps_ra(a, ops);
		}
		else if (a->top->raw < b->top->raw)
			check += ps_ra(a, ops);
	}
	while (a->bottom->raw != max && check == 0)
		check += ps_ra(a, ops);
	pstest_print_decks(a, b);
	return (check);
}

int	sort_five(t_ps_deck *a, t_ps_deck *b, t_ops_deck *ops)
{
	int	check;

	if (is_ordered(a) == 1)
		return (0);
	check = ps_pb(a, b, ops);
	if (check == 0)
	{
		if (is_ordered(a) == 1)
			return (merge_b_to_a(a, b, ops));
		check += ps_pb(a, b, ops);
	}
	if (check == 0)
		check += sort_three_a(a, ops);
	if (check == 0)
		check += sort_two_b(b, ops);
	if (check == 0)
		check += merge_b_to_a(a, b, ops);
	return (check);
}
