/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_record.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:14:30 by joonhlee          #+#    #+#             */
/*   Updated: 2023/04/23 12:45:18 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ops_deque	*sort_record(t_ps_deque *a, t_ps_deque *b)
{
	t_ops_deque	*ops;
	int			check;

	check = 0;
	ops = ops_new_deque();
	if (ops == 0)
		return (0);
	if (a->n_node <= 5)
		check += sort_small(a, b, ops) * 2 - 1;
	if (check == 0)
		check += assign_subs(a);
	if (check == 0)
		check += divide_subs(a, b, ops);
	if (check == 0)
		check += merge_all(a, b, ops);
	if (check == 0)
		refine_ops(ops);
	if (check > 0)
		ops = ops_clear_deque(ops);
	return (ops);
}

int	is_ordered(t_ps_deque *a)
{
	t_ps_node	*test_node;
	t_ps_node	*next_node;

	if (a->n_node == 1)
		return (1);
	test_node = a->top;
	next_node = a->top->next;
	while (next_node)
	{
		if (next_node->raw < test_node->raw)
			return (0);
		test_node = next_node;
		next_node = next_node->next;
	}
	return (1);
}
