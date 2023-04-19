/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_all4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 09:08:31 by joonhlee          #+#    #+#             */
/*   Updated: 2023/04/19 09:57:26 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	gpt_merge(t_ps_deck *a, t_ps_deck *b, t_ops_deck *ops)
{
	int			check;
	int			count;
	int			misalign;

	gpt_divide(a, b);
	count = a->n_subseq;
	check = 0;
	misalign = 0;
	while (count > 0 && check == 0 && misalign == 0)
	{
		if (a->top_sub->divide > b->top_sub->divide)
		{
			if (count_first(a->top_sub, a) == 0 || a->top->raw > b->bottom->raw)
				misalign = 1;
			check = tw_merge_ab(a, b, ops);
		}
		else
		{
			if (count_first(b->top_sub, b) == 0 || b->top->raw > a->bottom->raw)
				misalign = 1;
			check = tw_merge_ba(a, b, ops);
		}
		count--;
	}
	return (check);
}

void	gpt_divide(t_ps_deck *a, t_ps_deck *b)
{
	int	e;
	int	k;
	int	i;

	gpt_divide_reset(a, b);
	e = get_exponent(a->n_subseq);
	if (e == 0)
		return ;
	k = 0;
	while (k < e)
	{
		i = k;
		while (i >= 0)
		{
			find_divide(i, a, b);
			i--;
		}
		k++;
	}
}

void	gpt_divide_reset(t_ps_deck *a, t_ps_deck *b)
{
	t_ps_subseq	*a_sub;
	t_ps_subseq	*b_sub;

	a_sub = a->top_sub;
	b_sub = b->top_sub;
	while (a_sub)
	{
		a_sub->divide = 0;
		b_sub->divide = 1;
		a_sub = a_sub->next_sub;
		b_sub = b_sub->next_sub;
	}
}

void	find_divide(int i, t_ps_deck *a, t_ps_deck *b)
{
	int			n_pair;
	t_ps_subseq	*a_sub;
	t_ps_subseq	*b_sub;
	int			j;

	a_sub = a->top_sub;
	b_sub = b->top_sub;
	n_pair = 0;
	while (a_sub)
	{
		if (i % 2 == 0 && a_sub->divide == i && b_sub->divide == i + 1)
			n_pair++;
		if (i % 2 == 1 && a_sub->divide == i + 1 && b_sub->divide == i)
			n_pair++;
		a_sub = a_sub->next_sub;
		b_sub = b_sub->next_sub;
	}
	if (n_pair == 1)
		return ;
	j = 0;
	while (j < n_pair / 2)
	{
		find_min_update(i, a, b, 0);
		j++;
	}
}

void	find_min_update(int i, t_ps_deck *a, t_ps_deck *b, int min)
{
	t_ps_subseq	*a_sub;
	t_ps_subseq	*b_sub;
	t_ps_subseq	*min_sub;

	a_sub = a->top_sub;
	b_sub = b->top_sub;
	min = -1;
	while (a_sub)
	{
		if (i % 2 == 0 && a_sub->divide == i && b_sub->divide == i + 1
			&& (min < 0 || count_first(a_sub, a) < min))
		{
			min = count_first(a_sub, a);
			min_sub = a_sub;
		}
		if (i % 2 == 1 && a_sub->divide == i + 1 && b_sub->divide == i
			&& (min < 0 || count_first(b_sub, b) < min))
		{
			min = count_first(b_sub, b);
			min_sub = b_sub;
		}
		a_sub = a_sub->next_sub;
		b_sub = b_sub->next_sub;
	}
	min_sub->divide = i + 2;
}
