/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_ops.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 16:33:38 by joonhlee          #+#    #+#             */
/*   Updated: 2023/04/23 12:45:18 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ops_deque	*ops_new_deque(void)
{
	t_ops_deque	*new_deque;

	new_deque = (t_ops_deque *) malloc(sizeof (t_ops_deque));
	if (new_deque == 0)
		return (0);
	new_deque->head = 0;
	new_deque->tail = 0;
	return (new_deque);
}

t_op_node	*ops_new_node(char *str)
{
	t_op_node	*new_node;

	new_node = (t_op_node *)malloc(sizeof(t_op_node));
	if (new_node == 0)
		return (0);
	ft_strlcpy(new_node->op, str, 5);
	new_node->next = 0;
	new_node->prev = 0;
	return (new_node);
}

void	ops_clear_node(t_op_node *op_node)
{
	op_node->next = 0;
	op_node->prev = 0;
	ft_bzero(op_node->op, 5);
	free(op_node);
}

t_ops_deque	*ops_clear_deque(t_ops_deque *ops_deque)
{
	t_op_node	*node_iter;
	t_op_node	*node_to_clear;

	if (ops_deque == 0)
		return (0);
	node_iter = ops_deque->head;
	while (node_iter)
	{
		node_to_clear = node_iter;
		node_iter = node_iter->next;
		ops_clear_node(node_to_clear);
	}
	ops_deque->head = 0;
	ops_deque->tail = 0;
	free(ops_deque);
	return (0);
}

void	ps_print_ops(t_ops_deque *ops_deque)
{
	t_op_node	*node_iter;

	node_iter = ops_deque->head;
	if (node_iter == 0)
		return ;
	while (node_iter)
	{
		ft_putstr_fd(node_iter->op, 1);
		node_iter = node_iter->next;
	}
}
