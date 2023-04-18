/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_all4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 09:08:31 by joonhlee          #+#    #+#             */
/*   Updated: 2023/04/18 13:16:18 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_greatest_power_two(int n)
{
	int	power;

	if (n < 1)
		return (-1);
	power = 1;
	while (2 * power <= n)
		power = power * 2;
	return (power);
}

int	get_exponent(int n)
{
	int	power;
	int	exponet;

	if (n < 1)
		return (-1);
	power = 1;
	exponet = 0;
	while (2 * power <= n)
	{
		power = power * 2;
		exponet++;
	}
	return (exponet);
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
			// printf("gpt_divide|e=%d|k=%d|i=%d\n", e, k, i);
			find_divide(i, a, b);
			i--;
			// pstest_print_subs(a, b, 0);
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
		// printf("find_divide|i=%d|n_pair=%d|j=%d\n", i, n_pair, j);
		find_min_update(i, a, b);
		j++;
	}
}

void	find_min_update(int i, t_ps_deck *a, t_ps_deck *b)
{
	int			min;
	t_ps_subseq	*a_sub;
	t_ps_subseq	*b_sub;
	t_ps_subseq	*min_a_sub;
	t_ps_subseq	*min_b_sub;


	a_sub = a->top_sub;
	b_sub = b->top_sub;
	min = -1;
	while (a_sub)
	{
		if (i % 2 == 0 && a_sub->divide == i && b_sub->divide == i + 1
			&& (min < 0 || a_sub->n_node < min))
		{
			min = a_sub->n_node;
			min_a_sub = a_sub;
		}
		if (i % 2 == 1 && a_sub->divide == i + 1 && b_sub->divide == i
			&& (min < 0 || b_sub->n_node < min))
		{
			min = b_sub->n_node;
			min_b_sub = b_sub;
		}
		a_sub = a_sub->next_sub;
		b_sub = b_sub->next_sub;
	}
	// printf("find_min_update|i=%d|min=%d\n", i, min);
	if (i % 2 == 0)
		min_a_sub->divide = i + 2;
	if (i % 2 == 1)
		min_b_sub->divide = i + 2;
}

int	gpt_merge(t_ps_deck *a, t_ps_deck *b, t_ops_deck *ops)
{
	int			check;
	int			count;
	int			misalign;

	count = a->n_subseq;
	check = 0;
	misalign = 0;
	if (a->n_subseq == 1)
		return (fmerge_b_to_a(a, b, ops));
	while (count > 0 && check == 0)
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

// void	double_divide(t_ps_deck *a, t_ps_deck *b)
// {
// 	int	gpt;
// 	int	k;
// 	int	i;

// 	gpt_divide_reset(a, b);
// 	gpt = get_greatest_power_two(a->n_subseq);
// 	if (e == 0)
// 		return ;
// 	k = 0;
// 	while (k < e)
// 	{
// 		i = k;
// 		while (i >= 0)
// 		{
// 			find_divide(i, a, b);
// 			i--;
// 		}
// 		k++;
// 	}
// }
