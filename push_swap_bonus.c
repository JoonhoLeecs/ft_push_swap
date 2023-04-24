/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 20:38:56 by joonhlee          #+#    #+#             */
/*   Updated: 2023/04/24 09:38:48 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	print_error_exit(void);

int	main(int argc, char **argv)
{
	t_ps_deque	*a;
	t_ps_deque	*b;

	if (argc == 1)
		return (0);
	a = parse_input(argc, argv);
	if (a == 0)
		return (1);
	b = ps_new_deque();
	if (b == 0)
	{
		clear_all(a, 0);
		print_error_exit();
	}
	do_instruction(a, b);
	clear_all(a, b);
	return (0);
}

void	clear_all(t_ps_deque *a, t_ps_deque *b)
{
	ps_clear_deque(a);
	ps_clear_deque(b);
}

int	print_error_exit(void)
{
	ft_putstr_fd("Error\n", 2);
	exit (1);
}
