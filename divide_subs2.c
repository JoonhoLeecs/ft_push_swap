/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_subs2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 14:46:21 by joonhlee          #+#    #+#             */
/*   Updated: 2023/04/22 20:37:54 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	move_seed_l(t_ps_deck *a, t_ps_deck *b, t_ops_deck *ops, int nf)
{
	int			*sign;
	int			i;
	int			check;

	sign = (int *) malloc ((nf + 1) * sizeof (int));
	if (sign == 0)
		return (1);
	check = set_sign(sign, nf);
	// i = 0;
	// while (i < nf)
	// 	printf("|%d", sign[i++]);
	// printf("|\n");
	i = 0;
	while (i < nf && check == 0)
	{
		if ((sign[i]) * (a->top_sub->sub_ind) < 0)
			check = ps_sub_pb(a, b, ops);
		else if (a->top_sub->n_node <= 3
			|| find_sub_sign(a, sign[i] * -1) == 0)
			check = ps_sub_sa(a, b, ops) + ps_sub_pb(a, b, ops);
		else
		{
			check = ps_sub_ra(a, ops);
			i--;
		}
		i++;
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

int	find_sub_sign(t_ps_deck *a, int sign)
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

int	ds_move_s(t_ps_deck *a, t_ps_deck *b, t_ops_deck *ops)
{
	int	check;

	check = 0;
	while (a->n_subseq > 1 && check == 0)
	{
		if (a->bottom_sub->sub_ind * b->bottom_sub->sub_ind < 0)
		{
			if (a->top_sub->sub_ind * b->bottom_sub->sub_ind > 0)
				check = ps_sub_ra(a, ops);
		}
		if (a->n_subseq > 1 && a->top_sub->n_node <= 3 && check == 0
			&& a->top_sub->sub_ind * b->bottom_sub->sub_ind > 0)
			check = ps_sub_sa(a, b, ops);
		if (b->bottom_sub->sub_ind > 0 && check == 0)
			check = merge_a_to_b_inc(a, b, ops);
		else if (b->bottom_sub->sub_ind < 0 && check == 0)
			check = merge_a_to_b_dec(a, b, ops);
	}
	check = ds_realign(b, ops);
	return (check);
}

int	ds_move_l(t_ps_deck *a, t_ps_deck *b, t_ops_deck *ops)
{
	int	check;

	check = 0;
	while (a->n_subseq > 0 && check == 0)
	{
		if (a->bottom_sub->sub_ind * b->bottom_sub->sub_ind < 0)
		{
			if (a->top_sub->sub_ind * b->bottom_sub->sub_ind > 0)
				check = ps_sub_ra(a, ops);
		}
		if (a->n_subseq > 1 && a->top_sub->n_node <= 3 && check == 0
			&& a->top_sub->sub_ind * b->bottom_sub->sub_ind > 0)
			check = ps_sub_sa(a, b, ops);
		if (b->bottom_sub->sub_ind > 0 && check == 0)
			check = merge_a_to_b_inc(a, b, ops);
		else if (b->bottom_sub->sub_ind < 0 && check == 0)
			check = merge_a_to_b_dec(a, b, ops);
		// pstest_print_subs(a, b, ops);

		if (insertion_better(a, b))
			check = insert_to_b(a, b, ops);
	}
	// pstest_print_subs(a, b, ops);
	check = ds_realign(b, ops);
	return (check);
}

int insertion_better(t_ps_deck *a, t_ps_deck *b)
{
	long long	current;
	long long	next;
	long long	an_node;
	long long	bn_node;
	long long	an_sub;
	long long	bn_sub;

	an_node = (long long)a->n_node;
	bn_node = (long long)b->n_node;
	an_sub = (long long)a->n_subseq;
	bn_sub = (long long)b->n_subseq;
	if (9 * an_node * bn_sub >= bn_node * an_sub || an_node < 4 || an_sub < 3)
		return (0);
	current = (8 * bn_node * (an_sub - 1) - bn_sub * an_node * (3 * an_node + 1))
		/ (8 * bn_sub);
	if (a->bottom_sub->sub_ind * b->bottom_sub->sub_ind > 0)
	{
		an_node -= a->bottom_sub->n_node;
		bn_node += a->bottom_sub->n_node;
		an_sub -= 1;
		bn_sub += 1;
	}
	if (a->top_sub->sub_ind * b->bottom_sub->sub_ind < 0
		|| (a->top_sub->sub_ind * b->bottom_sub->sub_ind > 0 && a->top_sub->n_node <= 3))
	{
		an_node -= a->top_sub->n_node;
		bn_node += a->top_sub->n_node;
		an_sub -= 1;
		bn_sub += 1;
	}
	next = (8 * bn_node * (an_sub - 1) - bn_sub * an_node * (3 * an_node + 1))
		/ (8 * bn_sub);
	// next = (2 * bn_node * (an_sub - 1) - bn_sub * an_node * (an_node - 2))
	// 	/ 2 / bn_sub;
	// next = (2 * bn_node * (an_sub - 1) - bn_sub * an_node * (an_node - 2))
	// 	/ 2 / bn_sub - (a->bottom_sub->n_node * 2 + a->top_sub->n_node + b->bottom_sub->n_node);
	// if (10 * current > 3 * (an_node + bn_node))
	// printf("current=%lld|next=%lld\n", current, next);
	if (current > 0 && current >= next)
		return (1);
	else
		return (0);
}

int	insert_to_b(t_ps_deck *a, t_ps_deck *b, t_ops_deck *ops)
{
	int	direction;
	int	check;

	// printf("insert start\n");
	// pstest_print_subs(a, b, ops);
	direction = ds_find_rb_rrb(b);
	if (direction > 0)
		check = insert_by_rb(a, b, ops, b->top_sub->sub_ind);
	else
		check = insert_by_rrb(a, b, ops, b->bottom_sub->sub_ind);
	// printf("insert end\n");
	// pstest_print_decks(a, b);
	// pstest_print_subs(a, b, ops);
	return (check);
}

int	insert_by_rb(t_ps_deck *a, t_ps_deck *b, t_ops_deck *ops, int s)
{
	int	raw;
	int	check;
	// printf("insert_rb start\n");
	// pstest_print_subs(a, b, ops);
	check = 0;
	while (s > 0 && a->n_node > 0 && check == 0)
	{
		raw = find_min(a);
		check = move_rb(a, b, ops, raw);
	}
	while (s < 0 && a->n_node > 0 && check == 0)
	{
		raw = find_max(a);
		check = move_rb(a, b, ops, raw);
	}
	// printf("insert_rb end check = %d\n", check);
	// pstest_print_subs(a, b, ops);

	sub_add_bottom(b, sub_remove_top(b));
	ps_clear_all_subseq(a);
	while (b->top->raw != b->top_sub->top->raw && check == 0)
		check = ps_rb(b, ops);
	// pstest_print_subs(a, b, ops);
	return (check);
}

int	insert_by_rrb(t_ps_deck *a, t_ps_deck *b, t_ops_deck *ops, int s)
{
	int	raw;
	int	check;
	// printf("insert_rrb start\n");
	// pstest_print_subs(a, b, ops);
	check = 0;
	while (s > 0 && a->n_node > 0 && check == 0)
	{
		raw = find_max(a);
		check = move_rrb(a, b, ops, raw);
	}
	while (s < 0 && a->n_node > 0 && check == 0)
	{
		raw = find_min(a);
		check = move_rrb(a, b, ops, raw);
	}
	// printf("insert_rrb end check=%d\n", check);
	// pstest_print_subs(a, b, ops);

	sub_add_top(b, sub_remove_bottom(b));
	ps_clear_all_subseq(a);
	while (b->bottom->raw != b->bottom_sub->bottom->raw && check == 0)
		check = ps_rrb(b, ops);
	// pstest_print_subs(a, b, ops);
	return (check);
}

int	find_max(t_ps_deck *a)
{
	t_ps_node	*node;
	int			max;

	node = a->top;
	max = a->top->raw;
	while (node)
	{
		if (max < node->raw)
			max = node->raw;
		node = node->next;
	}
	return (max);
}

int	find_min(t_ps_deck *a)
{
	t_ps_node	*node;
	int			min;

	node = a->top;
	min = a->top->raw;
	while (node)
	{
		if (min > node->raw)
			min = node->raw;
		node = node->next;
	}
	return (min);
}

int	raw_find_ra_rra(t_ps_deck *a, int raw)
{
	t_ps_node	*node;
	int			ra;
	int			rra;

	node = a->top;
	if (node->raw == 0)
		return (0);
	ra = 0;
	while (node)
	{
		if (node->raw == raw)
			break ;
		ra++;
		node = node->next;
	}
	node = a->bottom;
	rra = 0;
	while (node)
	{
		rra++;
		if (node->raw == raw)
			break ;
		node = node->prev;
	}
	return (rra - ra);
}

int move_rb(t_ps_deck *a, t_ps_deck *b, t_ops_deck *ops, int raw)
{
	int	a_direction;
	int	check;
	int	sign;

	a_direction = raw_find_ra_rra(a, raw);
	sign = (b->top_sub->sub_ind > 0) * 1 + (b->top_sub->sub_ind < 0) * -1;
	check = 0;
	while (a_direction >= 0 && a->top->raw != raw && check == 0)
		check = ps_ra(a, ops);
	while (a_direction < 0 && a->top->raw != raw && check == 0)
		check = ps_rra(a, ops);
	while (sign * raw > sign * b->top->raw
		&& b->top->raw != b->top_sub->next_sub->top->raw && check == 0)
		check = ps_rb(b, ops);
	if (check == 0)
		check = ps_pb(a, b, ops);
	// if (b->top->raw == b->top_sub->next_sub->top->raw && check == 0)
	// 	check = ps_rrb(b, ops);
	insert_submerge(b, b->top_sub);
	return (check);
}

int move_rrb(t_ps_deck *a, t_ps_deck *b, t_ops_deck *ops, int raw)
{
	int	a_direction;
	int	check;
	int	sign;

	a_direction = raw_find_ra_rra(a, raw);
	sign = (b->bottom_sub->sub_ind > 0) * 1 + (b->bottom_sub->sub_ind < 0) * -1;
	check = 0;
	while (a_direction > 0 && a->top->raw != raw && check == 0)
		check = ps_ra(a, ops);
	while (a_direction <= 0 && a->top->raw != raw && check == 0)
		check = ps_rra(a, ops);
	while (sign * raw < sign * b->bottom->raw
		&& b->bottom->raw != b->bottom_sub->prev_sub->bottom->raw && check == 0)
		check = ps_rrb(b, ops);
	if (check == 0)
		check = ps_pb(a, b, ops);
	// if (b->bottom->raw == b->bottom_sub->prev_sub->bottom->raw && check == 0)
	// 	check = ps_rb(b, ops);
	insert_submerge(b, b->bottom_sub);
	return (check);
}

void	insert_submerge(t_ps_deck *b, t_ps_subseq *sub)
{
	int	raw;

	raw = b->top->raw;
	sub->n_node += 1;
	if (sub->sub_ind > 0 && raw < sub->top->raw)
		sub->top = b->top;
	if (sub->sub_ind > 0 && raw > sub->bottom->raw)
		sub->bottom = b->top;
	if (sub->sub_ind < 0 && raw > sub->top->raw)
		sub->top = b->top;
	if (sub->sub_ind < 0 && raw < sub->bottom->raw)
		sub->bottom = b->top;
}
