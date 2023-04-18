/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 21:05:41 by joonhlee          #+#    #+#             */
/*   Updated: 2023/04/18 16:32:43 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	merge_all(t_ps_deck *a, t_ps_deck *b, t_ops_deck *ops)
{
	int	check;

	// pstest_print_subs(a, b, ops);
	check = 0;
	if (a->n_subseq == b->n_subseq && check == 0 && a->n_subseq > 1
		&& a->n_subseq == get_greatest_power_two(a->n_subseq))
	{
		gpt_divide(a, b);
	// printf("after gpt_divide\n");
	// pstest_print_subs(a, b, ops);
	}
	// printf("after gpt_divide\n");
	// pstest_print_subs(a, b, ops);
	while (a->n_subseq == b->n_subseq && check == 0 && a->n_subseq > 1
		&& a->n_subseq == get_greatest_power_two(a->n_subseq))
	{
		check += gpt_merge(a, b, ops);
		// printf("after gpt_merge\n");
		// pstest_print_subs(a, b, ops);
	}
	if (a->n_subseq == 1 && b->n_subseq == 1)
		return (fmerge_b_to_a(a, b, ops));
	while (a->n_subseq < b->n_subseq && check == 0)
		check += better_merge_ba(a, b, ops);
	while (a->n_subseq > b->n_subseq && check == 0)
		check += better_merge_ab(a, b, ops);
	// pstest_print_subs(a, b, ops);
	while (a->n_subseq == b->n_subseq && check == 0
		&& a->n_subseq > get_greatest_power_two(a->n_subseq))
		check += double_merge(a, b, ops);
	if (check != 0)
		return (check);
	else
		return (merge_all(a, b, ops));
}

int	merge_b_to_a(t_ps_deck *a, t_ps_deck *b, t_ops_deck *ops)
{
	int	a_count;
	int	b_count;
	int	check;

	a_count = a->top_sub->n_node;
	b_count = b->top_sub->n_node;
	check = 0;
	while ((0 < a_count || 0 < b_count) && check == 0)
	{
		if ((a->top->raw < b->top->raw && 0 < a_count) || b_count == 0)
		{
			check += ps_ra(a, ops);
			a_count--;
		}
		else if ((a->top->raw > b->top->raw && 0 < b_count) || a_count == 0)
		{
			check += ps_pa(a, b, ops);
			if (check == 0)
			check += ps_ra(a, ops);
			b_count--;
		}
	}
	if (check == 0)
		submerge_b_to_a(a, b);
	return (check);
}

void	submerge_b_to_a(t_ps_deck *a, t_ps_deck *b)
{
	t_ps_subseq	*a_top_sub;
	t_ps_subseq	*b_top_sub;
	t_ps_node	*node_iter;

	a_top_sub = sub_remove_top(a);
	b_top_sub = sub_remove_top(b);
	a_top_sub->n_node = a_top_sub->n_node + b_top_sub->n_node;
	if (a_top_sub->top->raw > b_top_sub->top->raw)
		a_top_sub->top = b_top_sub->top;
	if (a_top_sub->bottom->raw < b_top_sub->bottom->raw)
		a_top_sub->bottom = b_top_sub->bottom;
	clear_sub(b_top_sub);
	node_iter = a_top_sub->top;
	while (node_iter)
	{
		node_iter->sub_ind = a_top_sub->sub_ind;
		node_iter = node_iter->next;
	}
	sub_add_bottom(a, a_top_sub);
}

int	merge_a_to_b(t_ps_deck *a, t_ps_deck *b, t_ops_deck *ops)
{
	int	a_count;
	int	b_count;
	int	check;

	a_count = a->top_sub->n_node;
	b_count = b->top_sub->n_node;
	check = 0;
	while ((0 < a_count || 0 < b_count) && check == 0)
	{
		if ((a->top->raw > b->top->raw && 0 < b_count) || a_count == 0)
		{
			check += ps_rb(b, ops);
			b_count--;
		}
		else if ((a->top->raw < b->top->raw && 0 < a_count) || b_count == 0)
		{
			check += ps_pb(a, b, ops);
			if (check == 0)
				check += ps_rb(b, ops);
			a_count--;
		}
	}
	if (check == 0)
		submerge_b_to_a(b, a);
	return (check);
}

int	double_merge(t_ps_deck *a, t_ps_deck *b, t_ops_deck *ops)
{
	int			check;

	check = 0;
	// if (check_a_tops(a, b) + check_a_tops(b, a) > 0)
	// {
	// 	if (check_a_tops(a, b) > 0)
	// 		check += merge_a_tops (a, ops);
	// 	if (check_a_tops(b, a) > 0 && check == 0)
	// 		merge_b_tops (b, ops);
	// 	return (check);
	// }
		// pstest_print_subs(a, b, ops);
		// printf("count_ba=%d, count_ab=%d\n", count_ba(a, b), count_ba(b, a));
		// printf("count_baab=%d, count_abba=%d\n", count_baab(a, b), count_baab(b, a));
	if (count_baab(a, b) >= count_baab(b, a))
	{
		check += tw_merge_ba(a, b, ops);
		if (check == 0)
			check += tw_merge_ab(a, b, ops);
	}
	else
	{
		check += tw_merge_ab(a, b, ops);
		if (check == 0)
			check += tw_merge_ba(a, b, ops);
	}
	return (check);
}

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
	int	n_first;
	int	n_second;
	t_ps_subseq	*a_top;
	int	a_bot;
	int	b_bot;
	int	count;

	a_top = a->top_sub;
	n_first = count_first(b->top_sub, b);
	n_second = b->top_sub->n_node - n_first;
	b_bot = b->bottom->raw;
	if (n_second > 0)
		b_bot = b->top_sub->bottom->raw;
	a_bot = a->bottom->raw;
	if (n_first > 0 && b->top->raw > a->bottom->raw)
		a_bot = bottom_of_first(b->top_sub, b->bottom->raw);
	else if (n_first > 0 && b->top->raw < a->bottom->raw)
	{
		a_bot = max(bottom_of_first(b->top_sub, b->bottom->raw), a_top->bottom->raw);
		a_top = a_top->next_sub;
	}
	n_first = count_first_raw(a_top, a_bot);
	n_second = a_top->n_node - n_first;
	// printf("a_bot=%d|b_bot=%d|n_first=%d|n_second=%d\n", a_bot, b_bot, n_first, n_second);
	count = count_ba(a, b) + n_second;
	if (n_first > 0 && a_top->top->raw > b_bot)
		count += n_first * 2;
	else if (n_first > 0 && a_top->top->raw < b_bot)
		count += n_first * 2 + b->top_sub->next_sub->n_node;
	return (count);
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

int count_first_raw(t_ps_subseq *sub, int raw)
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

int	max(int a, int b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}
