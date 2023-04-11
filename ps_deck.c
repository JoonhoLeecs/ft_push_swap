/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_deck.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:04:18 by joonhlee          #+#    #+#             */
/*   Updated: 2023/04/11 17:55:21 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ps_node	*ps_new_node(int raw)
{
	t_ps_node	*new_node;

	new_node = (t_ps_node *) malloc(sizeof (t_ps_node));
	if (new_node == 0)
		return (0);
	new_node->raw = raw;
	new_node->sub_ind = 0;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

t_ps_deck	*ps_new_deck(void)
{
	t_ps_deck	*new_deck;

	new_deck = (t_ps_deck *) malloc(sizeof (t_ps_deck));
	if (new_deck == 0)
		return (0);
	new_deck->n_node = 0;
	new_deck->top = 0;
	new_deck->bottom = 0;
	new_deck->ref = 0;
	new_deck->n_subseq = 0;
	new_deck->top_sub = 0;
	new_deck->bottom_sub = 0;
	new_deck->ref_sub = 0;
	return (new_deck);
}

void	ps_clear_deck(t_ps_deck *deck)
{
	t_ps_node	*tmp_node;
	t_ps_node	*node_to_clear;

	tmp_node = deck->top;
	while (tmp_node)
	{
		node_to_clear = tmp_node;
		tmp_node = tmp_node->next;
		node_to_clear->next = 0;
		node_to_clear->prev = 0;
		free(node_to_clear);
		node_to_clear = 0;
	}
	ps_clear_subseq(deck);
	deck->top = 0;
	deck->bottom = 0;
	deck->ref = 0;
	free(deck);
	deck = 0;
}

void	ps_clear_subseq(t_ps_deck *deck)
{
	t_ps_subseq	*tmp_subseq;
	t_ps_subseq	*subseq_to_clear;

	tmp_subseq = deck->top_sub;
	while (tmp_subseq)
	{
		subseq_to_clear = tmp_subseq;
		tmp_subseq = tmp_subseq->next_sub;
		subseq_to_clear->top = 0;
		subseq_to_clear->bottom = 0;
		subseq_to_clear->next_sub = 0;
		subseq_to_clear->prev_sub = 0;
		free(subseq_to_clear);
		subseq_to_clear = 0;
	}
	deck->top_sub = 0;
	deck->bottom_sub = 0;
	deck->ref_sub = 0;
}
