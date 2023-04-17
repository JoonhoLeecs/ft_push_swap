/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_ops.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 16:33:38 by joonhlee          #+#    #+#             */
/*   Updated: 2023/04/17 08:51:56 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ops_deck	*ops_new_deck(void)
{
	t_ops_deck	*new_deck;

	new_deck = (t_ops_deck *) malloc(sizeof (t_ops_deck));
	if (new_deck == 0)
		return (0);
	new_deck->head = 0;
	new_deck->tail = 0;
	return (new_deck);
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

t_ops_deck	*ops_clear_deck(t_ops_deck *ops_deck)
{
	t_op_node	*node_iter;
	t_op_node	*node_to_clear;

	if (ops_deck == 0)
		return (0);
	node_iter = ops_deck->head;
	while (node_iter)
	{
		node_to_clear = node_iter;
		node_iter = node_iter->next;
		ops_clear_node(node_to_clear);
	}
	ops_deck->head = 0;
	ops_deck->tail = 0;
	free(ops_deck);
	return (0);
}

void	ps_print_ops(t_ops_deck *ops_deck)
{
	t_op_node	*node_iter;

	node_iter = ops_deck->head;
	if (node_iter == 0)
		return ;
	while (node_iter)
	{
		ft_putstr_fd(node_iter->op, 1);
		node_iter = node_iter->next;
	}
}
