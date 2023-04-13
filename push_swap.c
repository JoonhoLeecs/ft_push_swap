/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 20:38:56 by joonhlee          #+#    #+#             */
/*   Updated: 2023/04/12 21:29:03 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pstest_print_decks(t_ps_deck *a, t_ps_deck *b);

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
	ops = ps_sort_record(a, b);
	pstest_print_decks(a, b);
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
			printf("|%15d|%15s|\n", a_iter->raw, "");
			a_iter = a_iter->next;
		}
		else if (i < max - na && i >= max - nb)
		{
			printf("|%15s|%15d|\n", "", b_iter->raw);
			b_iter = b_iter->next;
		}
		else if (i >= max - na && i >= max - nb)
		{
			printf("|%15d|%15d|\n", a_iter->raw, b_iter->raw);
			a_iter = a_iter->next;
			b_iter = b_iter->next;
		}
		i++;
	}
	printf("|a:%11dea|b:%11dea|\n", na, nb);

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
