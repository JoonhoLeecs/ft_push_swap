/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_all2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 19:56:18 by joonhlee          #+#    #+#             */
/*   Updated: 2023/04/17 08:46:06 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	better_merge_ba(t_ps_deck *a, t_ps_deck *b, t_ops_deck *ops)
{
	int	check;

	check = 0;
	if (a->top_sub->n_node > b->top_sub->n_node || a->n_subseq == 1)
		check += merge_b_to_a(a, b, ops);
	else
		check += double_merge(a, b, ops);
	return (check);
}

int	better_merge_ab(t_ps_deck *a, t_ps_deck *b, t_ops_deck *ops)
{
	int	check;

	check = 0;
	if (a->top_sub->n_node < b->top_sub->n_node || b->n_subseq == 1)
		check += merge_a_to_b(a, b, ops);
	else
		check += double_merge(a, b, ops);
	return (check);
}
