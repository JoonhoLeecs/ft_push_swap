/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 20:38:56 by joonhlee          #+#    #+#             */
/*   Updated: 2023/04/14 18:01:06 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_ps_deck	*a;
	t_ps_deck	*b;
	t_ops_deck	*ops;

	if (argc == 1)
		return (0);
	a = parse_input(argc, argv);
	if (a == 0)
		return (1);
	b = ps_new_deck();
	if (b == 0)
		exit (1);
	ops = sort_record(a, b);
	if (ops != 0)
		ps_print_ops(ops);
	// clear_all(a, b, ops);
	return (0);
}

// the following functions are temporary to check variables in process
#include <stdio.h>

void	pstest_print_decks(t_ps_deck *a, t_ps_deck *b)
{
	int			i;
	int			na;
	int			nb;
	int			max;
	t_ps_node	*a_iter;
	t_ps_node	*b_iter;

	na = a->n_node;
	nb = b->n_node;
	max = (na >= nb) * na + (na < nb) * nb;
	i = 0;
	a_iter = a->top;
	b_iter = b->top;
	while (i < max)
	{
		if (i >= max - na && i < max - nb)
		{
			printf("|%15d|%10d|%15s|%10s|\n", a_iter->raw, a_iter->sub_ind, "", "");
			a_iter = a_iter->next;
		}
		else if (i < max - na && i >= max - nb)
		{
			printf("|%15s|%10s|%15d|%10d|\n", "", "", b_iter->raw, b_iter->sub_ind);
			b_iter = b_iter->next;
		}
		else if (i >= max - na && i >= max - nb)
		{
			printf("|%15d|%10d|%15d|%10d|\n", a_iter->raw, a_iter->sub_ind, b_iter->raw, b_iter->sub_ind);
			a_iter = a_iter->next;
			b_iter = b_iter->next;
		}
		i++;
	}
	printf("|a:%11dea|a:%5dsub|b:%11dea|b:%5dsub|\n", na, a->n_subseq, nb, b->n_subseq);
}

void	pstest_print_subs(t_ps_deck *a, t_ps_deck *b)
{
	int i;
	int na;
	int nb;
	int max;
	t_ps_subseq *a_iter;
	t_ps_subseq *b_iter;

	na = a->n_subseq;
	nb = b->n_subseq;
	max = (na >= nb) * na + (na < nb) * nb;
	i = 0;
	a_iter = a->top_sub;
	b_iter = b->top_sub;
	while (i < max)
	{
		if (i >= max - na && i < max - nb)
		{
			printf("|%5d|%5d|%5d|%10d|%10d|%5s|%5s|%5s|%10s|%10s|\n",
				   a_iter->sub_ind, a_iter->n_node, a_iter->divide, a_iter->top->raw, a_iter->bottom->raw,
				   "", "", "", "", "");
			a_iter = a_iter->next_sub;
		}
		else if (i < max - na && i >= max - nb)
		{
			printf("|%5s|%5s|%5s|%10s|%10s|%5d|%5d|%5d|%10d|%10d|\n",
				   "", "", "", "", "",
				    b_iter->sub_ind, b_iter->n_node, b_iter->divide, b_iter->top->raw, b_iter->bottom->raw);
			b_iter = b_iter->next_sub;
		}
		else if (i >= max - na && i >= max - nb)
		{
			printf("|%5d|%5d|%5d|%10d|%10d|%5d|%5d|%5d|%10d|%10d|\n",
				   a_iter->sub_ind, a_iter->n_node, a_iter->divide, a_iter->top->raw, a_iter->bottom->raw,
				   b_iter->sub_ind, b_iter->n_node, b_iter->divide, b_iter->top->raw, b_iter->bottom->raw);
			a_iter = a_iter->next_sub;
			b_iter = b_iter->next_sub;
		}
		i++;
	}
	printf("|a ind|    n|  div|%10s|%10s|b ind|    n|  div|%10s|%10s\n", "top", "bottom", "top", "bottom");
	printf("|a:%11dea|a:%5dsub|b:%11dea|b:%5dsub|\n", a->n_node, a->n_subseq, b->n_node, b->n_subseq);
}
// ps_sa(a, ops);
// pstest_print_decks(a, b);
// ps_pb(a, b, ops);
// pstest_print_decks(a, b);
// ps_pb(a, b, ops);
// pstest_print_decks(a, b);
// ps_pb(a, b, ops);
// pstest_print_decks(a, b);
// ps_sb(b, ops);
// pstest_print_decks(a, b);
// ps_ra(a, ops);
// pstest_print_decks(a, b);
// ps_rb(b, ops);
// pstest_print_decks(a, b);
// ps_rr(a, b, ops);
// pstest_print_decks(a, b);
// ps_rra(a, ops);
// pstest_print_decks(a, b);
// ps_rrb(b, ops);
// pstest_print_decks(a, b);
// ps_rrr(a, b, ops);
// pstest_print_decks(a, b);
// ps_pa(a, b, ops);

// from sort_record.c test
//  printf("sort_record.c|after assign_subs\n");
//  pstest_print_decks(a, b);
//  pstest_print_subs(a, b);
// printf("sort_record.c|after divide_subs\n");
// pstest_print_decks(a, b);
// pstest_print_subs(a, b);
// printf("check:%d", check);

// from divide_subs.c test
//  printf("divide_subs.c|before calc_divide\n");
//  pstest_print_decks(a, b);
//  pstest_print_subs(a, b);

// printf("divide_subs.c|after calc_divide\n");
// pstest_print_decks(a, b);
// pstest_print_subs(a, b);
// printf("n_dec_node:%d\n", n_dec_node);

// printf("divide_subs.c|in the while of calc_divide\n");
// printf("subind:%d|top:%d|\n", sub_iter->sub_ind, sub_iter->top->raw);
// pstest_print_decks(a, a);
// pstest_print_subs(a, a);

// printf("divide_subs.c|after the while of calc_divide\n");
// printf("ndec_sub:%d|ndec_node:%d|\n", n_dec_sub, n_dec_node);

// printf("divide_subs.c|in the while of adjust_to_b\n");
// printf("subind:%d|top:%d|target:%d|\n", sub_iter->sub_ind, sub_iter->top->raw, target_size);
// printf("ndec_sub:%d|ndec_node:%d|\n", n_dec_sub, n_dec_node);
// pstest_print_subs(a, a);

// printf("divide_subs.c|in the if of adjust_to_b\n");
// printf("ndec_sub:%d|ndec_node:%d|\n", n_dec_sub, n_dec_node);
// pstest_print_subs(a, a);

// from ps_sub_ops.c test
// printf("ps_sub_ops.c|ps_sub_pbrb in the while\n");
// pstest_print_decks(a, b);
// pstest_print_subs(a, b);

// printf("ps_sub_ops.c|ps_sub_pbrb after while\n");
// pstest_print_decks(a, b);
// pstest_print_subs(a, b);


// from merge_all.c test

// printf("merge_all.c|front of merge_all\n");
// pstest_print_decks(a, b);
// pstest_print_subs(a, b);

// printf("merge_all.c|before while in merge_a_to_b\n");
// pstest_print_decks(a, b);
// pstest_print_subs(a, b);
// printf("%d, %d", a_top_sub_n, b_top_sub_n);

// printf("merge_all.c|before submerge in merge_a_to_b\n");
// pstest_print_decks(a, b);
// pstest_print_subs(a, b);
