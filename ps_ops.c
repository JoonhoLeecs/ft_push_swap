/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_ops.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 16:33:38 by joonhlee          #+#    #+#             */
/*   Updated: 2023/04/12 20:37:37 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

t_ops_deck	*ps_new_ops_deck(void)
{
	t_ops_deck	*new_deck;

	new_deck = (t_ops_deck *) malloc(sizeof (t_ops_deck));
	if (new_deck == 0)
		return (0);
	new_deck->head = 0;
	new_deck->tail = 0;
	return (new_deck);
}

t_oplst	*ps_new_oplst(char *str)
{
	t_oplst	*new_oplst;

	new_oplst = (t_oplst *)malloc(sizeof(t_oplst));
	if (new_oplst == 0)
		return (0);
	ft_strlcpy(new_oplst->op, str, 5);
	new_oplst->next = 0;
	new_oplst->prev = 0;
	return (new_oplst);
}

void	ps_clear_oplst(t_oplst *oplst)
{
	oplst->next = 0;
	oplst->prev = 0;
	ft_bzero(oplst->op, 5);
	free(oplst);
}

t_ops_deck	*ps_clear_ops_deck(t_ops_deck *ops_deck)
{
	t_oplst	*node_to_clear;
	t_oplst	*tmp_node;

	node_to_clear = ops_deck->head;
	while (node_to_clear)
	{
		tmp_node = node_to_clear->next;
		ps_clear_oplst(node_to_clear);
		node_to_clear = tmp_node;
	}
	ops_deck->head = 0;
	ops_deck->tail = 0;
	free(ops_deck);
	return (0);
}

void	ps_print_ops(t_ops_deck *ops_deck)
{
	t_oplst	*node;

	node = ops_deck->head;
	if (node == 0)
		return ;
	while (node)
	{
		ft_putstr_fd(node->op, 1);
		node = node->next;
	}
}
