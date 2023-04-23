/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_subs2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 14:46:21 by joonhlee          #+#    #+#             */
/*   Updated: 2023/04/23 12:45:18 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	move_seed_l(t_ps_deque *a, t_ps_deque *b, t_ops_deque *ops, int nf)
{
	int			*sign;
	int			i;
	int			check;

	sign = (int *) malloc ((nf + 1) * sizeof (int));
	if (sign == 0)
		return (1);
	check = set_sign(sign, nf);
	i = 0;
	while (i < nf && check == 0)
	{
		if ((sign[i++]) * (a->top_sub->sub_ind) < 0)
			check = ps_sub_pb(a, b, ops);
		else if (a->top_sub->n_node <= 3 || !find_sub_sign(a, sign[i - 1] * -1))
			check = ps_sub_sa(a, b, ops) + ps_sub_pb(a, b, ops);
		else
		{
			check = ps_sub_ra(a, ops);
			i--;
		}
		if (b->top_sub && i > 0)
			b->top_sub->divide = i - 1;
	}
	free(sign);
	return (check);
}

int	set_sign(int *sign, int nf)
{
	int	i;
	int	size;

	if (nf != greatest_power_a(nf, 3))
		return (1);
	sign[0] = 1;
	size = 1;
	while (size * 3 <= nf)
	{
		i = 0;
		while (i < size)
		{
			sign[i + 2 * size] = (sign[size - 1 - i]) * -1;
			sign[i + size] = (sign[size - 1 - i]) * -1;
			i++;
		}
		size = size * 3;
	}
	return (0);
}

int	find_sub_sign(t_ps_deque *a, int sign)
{
	t_ps_subseq	*sub_iter;
	int			count;

	sub_iter = a->top_sub;
	count = 0;
	sign = (sign > 0) * 1 + (sign < 0) * -1;
	while (sub_iter)
	{
		if (sub_iter-> n_node <= 3)
			count++;
		if (sub_iter->sub_ind * sign > 0 && sub_iter->n_node > 3)
			count++;
		sub_iter = sub_iter->next_sub;
	}
	return (count);
}

int	ds_move_s(t_ps_deque *a, t_ps_deque *b, t_ops_deque *ops)
{
	int	check;

	check = 0;
	while (a->n_subseq > 1 && check == 0)
	{
		if (same_order(a->bottom_sub, b->bottom_sub) < 0)
		{
			if (same_order(a->top_sub, b->bottom_sub) > 0)
				check = ps_sub_ra(a, ops);
		}
		if (a->n_subseq > 1 && a->top_sub->n_node <= 3 && check == 0
			&& same_order(a->top_sub, b->bottom_sub) > 0)
			check = ps_sub_sa(a, b, ops);
		if (check == 0)
			check = merge_a_to_b(a, b, ops);
	}
	check = ds_realign(b, ops);
	return (check);
}

int	ds_move_l(t_ps_deque *a, t_ps_deque *b, t_ops_deque *ops)
{
	int	check;

	check = 0;
	while (a->n_subseq > 0 && check == 0)
	{
		if (same_order(a->bottom_sub, b->bottom_sub) < 0)
		{
			if (same_order(a->top_sub, b->bottom_sub) > 0)
				check = ps_sub_ra(a, ops);
		}
		if (a->n_subseq > 1 && a->top_sub->n_node <= 3 && check == 0
			&& same_order(a->top_sub, b->bottom_sub) > 0)
			check = ps_sub_sa(a, b, ops);
		if (check == 0)
			check = merge_a_to_b(a, b, ops);
		if (insertion_better(a, b))
			check = insert_to_b(a, b, ops);
	}
	check = ds_realign(b, ops);
	return (check);
}
