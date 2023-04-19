/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_all6.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 21:05:41 by joonhlee          #+#    #+#             */
/*   Updated: 2023/04/19 12:44:19 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_ba(t_ps_deck *a, t_ps_deck *b)
{
	int	n_first;
	int	n_second;
	int	count;

	n_first = count_first(b->top_sub, b);
	n_second = b->top_sub->n_node - n_first;
	count = n_second;
	if (n_first > 0 && b->top->raw > a->bottom->raw)
	{
		count = n_first * 2 + count;
	}
	else if (n_first > 0 && b->top->raw < a->bottom->raw)
	{
		count = n_first * 2 + a->top_sub->n_node + count;
	}
	return (count);
}

int	count_baab(t_ps_deck *a, t_ps_deck *b)
{
	int			n_first;
	int			n_second;
	t_ps_subseq	*a_top;
	int			a_bot;
	int			b_bot;

	a_top = a->top_sub;
	n_first = count_first(b->top_sub, b);
	n_second = b->top_sub->n_node - n_first;
	b_bot = (n_second <= 0) * (b->bottom->raw)
		+ (n_second > 0) * (b->top_sub->bottom->raw);
	a_bot = a->bottom->raw;
	if (n_first > 0 && b->top->raw > a->bottom->raw)
		a_bot = bottom_of_first(b->top_sub, b->bottom->raw);
	else if (n_first > 0 && b->top->raw < a->bottom->raw)
	{
		a_bot = max(bottom_of_first(b->top_sub, b->bottom->raw),
				a_top->bottom->raw);
		a_top = a_top->next_sub;
	}
	n_first = count_first_raw(a_top, a_bot);
	n_second = count_ba(a, b) + a_top->n_node - n_first;
	n_second += add_count_baab(n_first, a_top->top->raw, b_bot,
			b->top_sub->next_sub->n_node);
	return (n_second);
}

int	add_count_baab(int n_first, int a_top_raw, int b_bot, int bn)
{
	int	add;

	add = 0;
	if (n_first > 0 && a_top_raw > b_bot)
		add += n_first * 2;
	else if (n_first > 0 && a_top_raw < b_bot)
		add += n_first * 2 + bn;
	return (add);
}

int	bottom_of_first(t_ps_subseq *sub, int raw)
{
	t_ps_node	*node;

	node = sub->bottom;
	while (node)
	{
		if (node->raw < raw)
			return (node->raw);
		node = node->prev;
	}
	return (sub->top->raw);
}

int	count_first_raw(t_ps_subseq *sub, int raw)
{
	t_ps_node	*node;
	int			n_first;

	if (sub->prev_sub == 0 && sub->next_sub == 0)
		return (sub->n_node);
	node = sub->top;
	n_first = 0;
	while (n_first < sub->n_node && node)
	{
		if (node->raw < raw)
		{
			n_first++;
			node = node->next;
		}
		else
			break ;
	}
	return (n_first);
}
