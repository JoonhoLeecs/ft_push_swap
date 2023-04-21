/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_all2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 21:05:41 by joonhlee          #+#    #+#             */
/*   Updated: 2023/04/21 14:46:24 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	merge_a_to_b_inc(t_ps_deck *a, t_ps_deck *b, t_ops_deck *ops)
{
	int	na_top;
	int	na_bot;
	int	nb_bot;
	int	check;

	na_top = (a->top_sub->sub_ind * b->bottom_sub->sub_ind < 0)
		* a->top_sub->n_node;
	na_bot = (a->bottom_sub->sub_ind * b->bottom_sub->sub_ind > 0)
		* a->bottom_sub->n_node;
	nb_bot = b->bottom_sub->n_node;
	check = 0;
	while ((na_top > 0 || na_bot > 0 || nb_bot > 0) && check == 0)
	{
		if (na_top > 0 && (na_bot == 0 || a->top->raw > a->bottom->raw)
			&& (nb_bot == 0 || a->top->raw > b->bottom->raw))
		{
			check += ps_pb(a, b, ops);
			na_top--;
		}
		else if (na_bot > 0 && (na_top == 0 || a->bottom->raw > a->top->raw)
			&& (nb_bot == 0 || a->bottom->raw > b->bottom->raw))
		{
			check += ps_rra(a, ops) + ps_pb(a, b, ops);
			na_bot--;
		}
		else if (nb_bot > 0 && (na_top == 0 || b->bottom->raw > a->top->raw)
			&& (na_bot == 0 || b->bottom->raw > a->bottom->raw))
		{
			check += ps_rrb(b, ops);
			nb_bot--;
		}
	}
	submerge_three_to_b(a, b);
	return (check);
}

int	merge_a_to_b_dec(t_ps_deck *a, t_ps_deck *b, t_ops_deck *ops)
{
	int	na_top;
	int	na_bot;
	int	nb_bot;
	int	check;

	na_top = (a->top_sub->sub_ind * b->bottom_sub->sub_ind < 0)
		* a->top_sub->n_node;
	na_bot = (a->bottom_sub->sub_ind * b->bottom_sub->sub_ind > 0)
		* a->bottom_sub->n_node;
	nb_bot = b->bottom_sub->n_node;
	check = 0;
	while ((na_top > 0 || na_bot > 0 || nb_bot > 0) && check == 0)
	{
		if (na_top > 0 && (na_bot == 0 || a->top->raw < a->bottom->raw)
			&& (nb_bot == 0 || a->top->raw < b->bottom->raw))
		{
			check += ps_pb(a, b, ops);
			na_top--;
		}
		else if (na_bot > 0 && (na_top == 0 || a->bottom->raw < a->top->raw)
			&& (nb_bot == 0 || a->bottom->raw < b->bottom->raw))
		{
			check += ps_rra(a, ops) + ps_pb(a, b, ops);
			na_bot--;
		}
		else if (nb_bot > 0 && (na_top == 0 || b->bottom->raw < a->top->raw)
			&& (na_bot == 0 || b->bottom->raw < a->bottom->raw))
		{
			check += ps_rrb(b, ops);
			nb_bot--;
		}
	}
	submerge_three_to_b(a, b);
	return (check);
}

int	merge_b_to_a_inc(t_ps_deck *a, t_ps_deck *b, t_ops_deck *ops)
{
	int	nb_top;
	int	nb_bot;
	int	na_bot;
	int	check;

	nb_top = (b->top_sub->sub_ind * a->bottom_sub->sub_ind < 0)
		* b->top_sub->n_node;
	nb_bot = (b->bottom_sub->sub_ind * a->bottom_sub->sub_ind > 0)
		* b->bottom_sub->n_node;
	na_bot = a->bottom_sub->n_node;
	check = 0;
	while ((nb_top > 0 || nb_bot > 0 || na_bot > 0) && check == 0)
	{
		if (nb_top > 0 && (nb_bot == 0 || b->top->raw > b->bottom->raw)
			&& (na_bot == 0 || b->top->raw > a->bottom->raw))
		{
			check += ps_pa(a, b, ops);
			nb_top--;
		}
		else if (nb_bot > 0 && (nb_top == 0 || b->bottom->raw > b->top->raw)
			&& (na_bot == 0 || b->bottom->raw > a->bottom->raw))
		{
			check += ps_rrb(b, ops) + ps_pa(a, b, ops);
			nb_bot--;
		}
		else if (na_bot > 0 && (nb_top == 0 || a->bottom->raw > b->top->raw)
			&& (nb_bot == 0 || a->bottom->raw > b->bottom->raw))
		{
			check += ps_rra(a, ops);
			na_bot--;
		}
	}
	submerge_three_to_b(b, a);
	return (check);
}

int	merge_b_to_a_dec(t_ps_deck *a, t_ps_deck *b, t_ops_deck *ops)
{
	int	nb_top;
	int	nb_bot;
	int	na_bot;
	int	check;

	nb_top = (b->top_sub->sub_ind * a->bottom_sub->sub_ind < 0)
		* b->top_sub->n_node;
	nb_bot = (b->bottom_sub->sub_ind * a->bottom_sub->sub_ind > 0)
		* b->bottom_sub->n_node;
	na_bot = a->bottom_sub->n_node;
	check = 0;
	while ((nb_top > 0 || nb_bot > 0 || na_bot > 0) && check == 0)
	{
		if (nb_top > 0 && (nb_bot == 0 || b->top->raw < b->bottom->raw)
			&& (na_bot == 0 || b->top->raw < a->bottom->raw))
		{
			check += ps_pa(a, b, ops);
			nb_top--;
		}
		else if (nb_bot > 0 && (nb_top == 0 || b->bottom->raw < b->top->raw)
			&& (na_bot == 0 || b->bottom->raw < a->bottom->raw))
		{
			check += ps_rrb(b, ops) + ps_pa(a, b, ops);
			nb_bot--;
		}
		else if (na_bot > 0 && (nb_top == 0 || a->bottom->raw < b->top->raw)
			&& (nb_bot == 0 || a->bottom->raw < b->bottom->raw))
		{
			check += ps_rra(a, ops);
			na_bot--;
		}
	}
	submerge_three_to_b(b, a);
	return (check);
}
