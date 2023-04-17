/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_all3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:20:06 by joonhlee          #+#    #+#             */
/*   Updated: 2023/04/17 22:27:20 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_a_tops(t_ps_deck *a, t_ps_deck *b)
{
	t_ps_subseq	*top_sub;
	t_ps_subseq	*next_sub;

	top_sub = a->top_sub;
	next_sub = top_sub->next_sub;
	if (top_sub->n_node <= 2 && top_sub->top->raw < next_sub->top->raw
		&& b->top_sub->n_node + top_sub->n_node < next_sub->n_node * 2)
		return (1);
	else
		return (0);
}

int	tw_merge_ba(t_ps_deck *a, t_ps_deck *b, t_ops_deck *ops)
{
	int		check;
	int		second;
	int		n_first;

	check = 0;
	second = 0;
	n_first = count_first(b->top_sub, b);
	if (n_first < b->top_sub->n_node && 0 < n_first)
	{
		// printf("before split count_first:\n");
		// pstest_print_decks(a, b);
		// pstest_print_subs(a, b, ops);
		check = split_top_sub(b);
		second = 1;
		// printf("after split\n");
		// pstest_print_decks(a, b);
		// pstest_print_subs(a, b, ops);
	}
	if (0 < n_first && b->top->raw > a->bottom->raw && check == 0)
	{
		check += ps_sub_para(a, b, ops);
		submerge_two_bottoms(a);
	}
	else if (0 < n_first && check == 0)
		check += merge_b_to_a(a, b, ops);
	if ((n_first == 0 || second != 0) && check == 0)
	{
		check += ps_sub_rb(b, ops);
		submerge_two_bottoms(b);
	}
	return (check);
}

int	tw_merge_ab(t_ps_deck *a, t_ps_deck *b, t_ops_deck *ops)
{
	int		check;
	int		second;
	int		n_first;

	check = 0;
	second = 0;
	n_first = count_first(a->top_sub, a);
	if (n_first < a->top_sub->n_node && 0 < n_first)
	{
	// printf("before split\n");
	// pstest_print_decks(a, b);
	// pstest_print_subs(a, b, ops);
		check = split_top_sub(a);
		second = 1;
		// printf("after split\n");
		// pstest_print_decks(a, b);
		// pstest_print_subs(a, b, ops);
	}
	if (0 < n_first && a->top->raw > b->bottom->raw && check == 0)
	{
		check += ps_sub_pbrb(a, b, ops);
		submerge_two_bottoms(b);
	}
	else if (0 < n_first && check == 0)
		check += merge_a_to_b(a, b, ops);
		// printf("after merge\n");
		// pstest_print_decks(a, b);
		// pstest_print_subs(a, b, ops);
	if ((n_first == 0 || second != 0) && check == 0)
	{
		check += ps_sub_ra(a, ops);
		submerge_two_bottoms(a);
	}
	return (check);
}

int	count_first(t_ps_subseq *sub, t_ps_deck *a)
{
	t_ps_subseq	*prev_sub;
	t_ps_node	*node_iter;
	int			n_first;

	if (a->n_subseq == 1)
		return (sub->n_node);
	if (sub->prev_sub == 0)
		prev_sub = a->bottom_sub;
	else
		prev_sub = sub->prev_sub;
	n_first = 0;
	node_iter = sub->top;
	while (n_first < sub->n_node && node_iter)
	{
		if (node_iter->raw < prev_sub->bottom->raw)
		{
			n_first++;
			node_iter = node_iter->next;
		}
		else
			break ;
	}
	return (n_first);
}

int	split_top_sub(t_ps_deck *a)
{
	t_ps_node	*node_iter;
	int			n_first;
	int			i;
	t_ps_subseq	*first;
	t_ps_subseq	*second;

	n_first = count_first(a->top_sub, a);
	first = sub_remove_top(a);
	i = 1;
	node_iter = first->top;
	while (i < n_first)
	{
		node_iter = node_iter->next;
		i++;
	}
	second = sub_new(node_iter->next, first->bottom, first->n_node - n_first, 0);
	if (second == 0)
		return (1);
	first->n_node = n_first;
	first->bottom = node_iter;
	sub_add_top(a, second);
	sub_add_top(a, first);
	return (0);
}
