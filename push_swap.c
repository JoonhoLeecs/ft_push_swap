/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 20:38:56 by joonhlee          #+#    #+#             */
/*   Updated: 2023/04/12 10:17:16 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_ps_deck	*a;
	t_ps_deck	*b;
	char		**ops;

	if (argc == 1)
		return (0);
	a = parse_input(argc, argv);
	if (a == 0)
		return (1);
	b = ps_new_deck();
	if (b == 0)
		exit (1);
	pstest_print_decks(a, b);
	// ops = sort_record(a, b, ops);
	// print_ops(ops);
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
			printf("|%15d|%15 |\n", a_iter->raw);
			a_iter = a_iter->next;
		}
		else if (i < max - na && i >= max - nb)
		{
			printf("|%15 |%15d|\n", b_iter->raw);
			b_iter = b_iter->next;
		}
		else if (i >= max - na && i >= max - nb)
		{
			printf("|%15d|%15d|\n", a_iter->raw, b_iter->raw);
			a_iter = a_iter->next;
			b_iter = b_iter->next;
		}
	}
	printf("|a:%11dea|b:%11dea|\n", a->n_node, b->n_node);

}
