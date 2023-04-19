/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 20:38:56 by joonhlee          #+#    #+#             */
/*   Updated: 2023/04/19 17:09:49 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	print_error_exit(void);

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
	{
		clear_all(a, 0, 0);
		print_error_exit();
	}
	ops = sort_record(a, b);
	if (ops == 0)
	{
		clear_all(a, 0, 0);
		print_error_exit();
	}
	ps_print_ops(ops);
	clear_all(a, b, ops);
	return (0);
}

void	clear_all(t_ps_deck *a, t_ps_deck *b, t_ops_deck *ops)
{
	ps_clear_deck(a);
	ps_clear_deck(b);
	ops_clear_deck(ops);
}

int	print_error_exit(void)
{
	ft_putstr_fd("Error\n", 2);
	exit (1);
}
