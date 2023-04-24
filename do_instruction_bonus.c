/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_instruction_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 14:14:10 by joonhlee          #+#    #+#             */
/*   Updated: 2023/04/24 09:37:51 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	do_instruction(t_ps_deque *a, t_ps_deque *b)
{
	int		check;
	char	*ins;

	check = 0;
	while (check == 0)
	{
		ins = get_next_line(0);
		if (ins == 0)
			break ;
		else if (is_valid_ins(ins))
			move_node(ins, a, b);
		else
			check = print_error();
	}
	if (check == 0)
	{
		if (b->n_node == 0 && is_ordered(a))
			ft_putstr_fd("OK\n", 1);
		else
			ft_putstr_fd("KO\n", 1);
	}
}

int	is_valid_ins(char *ins)
{
	if (ft_strcmp(ins, "pa\n") == 0 || ft_strcmp(ins, "pb\n") == 0
		|| ft_strcmp(ins, "sa\n") == 0 || ft_strcmp(ins, "sb\n") == 0
		|| ft_strcmp(ins, "ss\n") == 0 || ft_strcmp(ins, "ra\n") == 0
		|| ft_strcmp(ins, "rb\n") == 0 || ft_strcmp(ins, "rr\n") == 0
		|| ft_strcmp(ins, "rra\n") == 0 || ft_strcmp(ins, "rrb\n") == 0
		|| ft_strcmp(ins, "rrr\n") == 0 || ft_strcmp(ins, "\n") == 0)
		return (1);
	else
		return (0);
}

void	move_node(char *ins, t_ps_deque *a, t_ps_deque *b)
{
	if (ft_strcmp(ins, "pa\n") == 0)
		psb_pa(a, b);
	else if (ft_strcmp(ins, "pb\n") == 0)
		psb_pb(a, b);
	else if (ft_strcmp(ins, "sa\n") == 0)
		psb_sa(a);
	else if (ft_strcmp(ins, "sb\n") == 0)
		psb_sb(b);
	else if (ft_strcmp(ins, "ss\n") == 0)
		psb_ss(a, b);
	else if (ft_strcmp(ins, "ra\n") == 0)
		psb_ra(a);
	else if (ft_strcmp(ins, "rb\n") == 0)
		psb_rb(b);
	else if (ft_strcmp(ins, "rr\n") == 0)
		psb_rr(a, b);
	else if (ft_strcmp(ins, "rra\n") == 0)
		psb_rra(a);
	else if (ft_strcmp(ins, "rrb\n") == 0)
		psb_rrb(b);
	else if (ft_strcmp(ins, "rrr\n") == 0)
		psb_rrr(a, b);
}

int	print_error(void)
{
	ft_putstr_fd("Error\n", 2);
	return (1);
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
