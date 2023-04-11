/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 20:38:56 by joonhlee          #+#    #+#             */
/*   Updated: 2023/04/11 19:37:44 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(int argc, char **argv)
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
		return (1);
	ops = sort_record(a, b, ops);
	print_ops(ops);
	clear_all(a, b, ops);
}
