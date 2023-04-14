/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_subs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 14:46:21 by joonhlee          #+#    #+#             */
/*   Updated: 2023/04/14 08:50:38 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// #include <stdio.h>

int		calc_divide(t_ps_deck *a);
void	adjust_to_a(t_ps_deck *a, int *n_dec_node, int *n_dec_sub);
void	adjust_to_b(t_ps_deck *a, int *n_dec_node, int *n_dec_sub);
int		find_last_raw(t_ps_deck *a);

int	divide_subs(t_ps_deck *a, t_ps_deck *b, t_ops_deck *ops)
{
	int	check;
	int	n_dec_node;

	if (a->n_subseq == 1 && a->top_sub->sub_ind == 1)
		return (0);
	if (a->n_subseq == 1 && a->top_sub->sub_ind == -1)
		return (ps_reverse_ra(a, b, ops));
	check = 0;

	// printf("divide_subs.c|before calc_divide\n");
	// pstest_print_decks(a, b);
	// pstest_print_subs(a, b);

	n_dec_node = calc_divide(a);

	// printf("divide_subs.c|after calc_divide\n");
	// pstest_print_decks(a, b);
	// pstest_print_subs(a, b);
	// printf("n_dec_node:%d\n", n_dec_node);

	while (b->n_node < n_dec_node && check == 0)
	{
		if (a->top_sub->divide == 0 && a->top_sub->sub_ind > 0)
			check += ps_sub_ra(a, ops);
		else if (a->top_sub->divide == 0 && a->top_sub->sub_ind < 0)
			check += ps_reverse_ra(a, b, ops);
		else if (a->top_sub->divide == 1 && a->top_sub->sub_ind < 0)
			check += ps_sub_pb(a, b, ops);
		else
			check += ps_sub_pbrb(a, b, ops);
	}

	if (a->n_subseq == 1 && a->top_sub->sub_ind < 0 && check == 0)
		check += ps_reverse_ra(a, b, ops);
	return (check);
}

int	calc_divide(t_ps_deck *a)
{
	t_ps_subseq	*sub_iter;
	int			n_dec_sub;
	int			n_dec_node;

	n_dec_sub = 0;
	n_dec_node = 0;
	sub_iter = a->top_sub;
	while (sub_iter)
	{
		// printf("divide_subs.c|in the while of calc_divide\n");
		// printf("subind:%d|top:%d|\n", sub_iter->sub_ind, sub_iter->top->raw);
		// pstest_print_decks(a, a);
		// pstest_print_subs(a, a);
		if (sub_iter->sub_ind < 0)
		{
			n_dec_sub += 1;
			n_dec_node += sub_iter->n_node;
			sub_iter->divide = 1;
		}
		sub_iter = sub_iter->next_sub;
	}
	// printf("divide_subs.c|after the while of calc_divide\n");
	// printf("ndec_sub:%d|ndec_node:%d|\n", n_dec_sub, n_dec_node);
	if (7 * a->n_node < n_dec_node * 10 && 7 * a->n_subseq < n_dec_sub * 10)
		adjust_to_a(a, &n_dec_node, &n_dec_sub);
	else if (3 * a->n_node >= n_dec_node * 10 && 3 * a->n_subseq > n_dec_sub * 10)
		adjust_to_b(a, &n_dec_node, &n_dec_sub);
	return (n_dec_node);
}

void	adjust_to_a(t_ps_deck *a, int *n_dec_node, int *n_dec_sub)
{
	t_ps_subseq	*sub_iter;
	int			target_size;

	sub_iter = a->top_sub;
	target_size = 2;
	while (7 * a->n_node < *n_dec_node * 10 && 7 * a->n_subseq < *n_dec_sub * 10)
	{
		if (sub_iter->divide == 1 && sub_iter->n_node == target_size)
		{
			sub_iter->divide = 0;
			*n_dec_node -= sub_iter->n_node;
			*n_dec_sub -= 1;
		}
		if (sub_iter->next_sub == 0)
		{
			sub_iter = a->top_sub;
			target_size += 1;
		}
		else
			sub_iter = sub_iter->next_sub;
	}
}

void	adjust_to_b(t_ps_deck *a, int *n_dec_node, int *n_dec_sub)
{
	t_ps_subseq	*sub_iter;
	int			target_size;

	sub_iter = a->top_sub;
	target_size = 1;
	// printf("divide_subs.c|before the while of adjust_to_b\n");

	while (3 * a->n_node >= *n_dec_node * 10 && 3 * a->n_subseq > *n_dec_sub * 10)
	{
		// printf("divide_subs.c|in the while of adjust_to_b\n");
		// printf("subind:%d|top:%d|target:%d|\n", sub_iter->sub_ind, sub_iter->top->raw, target_size);
		// printf("ndec_sub:%d|ndec_node:%d|\n", n_dec_sub, n_dec_node);
		// pstest_print_subs(a, a);

		if (sub_iter->divide == 0 && sub_iter->n_node == target_size)
		{
			sub_iter->divide = 1;
			*n_dec_node += sub_iter->n_node;
			*n_dec_sub += 1;
			// printf("divide_subs.c|in the if of adjust_to_b\n");
			// printf("ndec_sub:%d|ndec_node:%d|\n", n_dec_sub, n_dec_node);
			// pstest_print_subs(a, a);
		}
		if (sub_iter->next_sub == 0)
		{
			sub_iter = a->top_sub;
			target_size += 1;
		}
		else
			sub_iter = sub_iter->next_sub;
	}
}

int	find_last_raw(t_ps_deck *a)
{
	t_ps_subseq	*sub_iter;

	sub_iter = a->bottom_sub;
	while (sub_iter)
	{
		if (sub_iter->divide == 1)
			break ;
		sub_iter = sub_iter->prev_sub;
	}
	return (sub_iter->bottom->raw);
}
