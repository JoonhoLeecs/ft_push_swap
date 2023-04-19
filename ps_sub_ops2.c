/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sub_ops2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:54:23 by joonhlee          #+#    #+#             */
/*   Updated: 2023/04/19 12:40:14 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_sub_sa2(t_ps_deck *a, t_ops_deck *ops);

int	ps_sub_sa(t_ps_deck *a, t_ps_deck *b, t_ops_deck *ops)
{
	int			check;
	t_ps_node	*tmp;

	if (a->top_sub->n_node == 2)
	{
		check = sort_two_a(a, ops);
		tmp = a->top_sub->top;
		a->top_sub->top = a->top_sub->bottom;
		a->top_sub->bottom = tmp;
		return (check);
	}
	else if (a->top_sub->n_node == 3)
		return (ps_sub_sa2(a, ops));
	check = ps_sub_pb(a, b, ops);
	if (check == 0)
		check += ps_sub_para(a, b, ops);
	return (check);
}

int	ps_sub_sa2(t_ps_deck *a, t_ops_deck *ops)
{
	int			check;
	t_ps_node	*tmp;

	check = ps_sa(a, ops);
	if (check == 0)
		check = ps_ra(a, ops);
	if (check == 0)
		check = ps_sa(a, ops);
	if (check == 0)
		check = ps_rra(a, ops);
	if (check == 0)
		check = ps_sa(a, ops);
	tmp = a->top_sub->top;
	a->top_sub->top = a->top_sub->bottom;
	a->top_sub->bottom = tmp;
	return (check);
}
