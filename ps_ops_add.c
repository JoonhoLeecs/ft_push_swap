/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_ops_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 16:56:09 by joonhlee          #+#    #+#             */
/*   Updated: 2023/04/12 17:07:25 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	ops_add_front(t_ops_deck *ops_deck, t_oplst *new)
{
	if (ops_deck == 0)
		return ;
	if (ops_deck->head == 0)
	{
		ops_deck->head = new;
		ops_deck->tail = new;
	}
	else
	{
		ops_deck->head->prev = new;
		new->next = ops_deck->head;
		ops_deck->head = new;
	}
}

void	ops_add_back(t_ops_deck *ops_deck, t_oplst *new)
{
	if (ops_deck == 0)
		return ;
	if (ops_deck->tail == 0)
	{
		ops_deck->head = new;
		ops_deck->tail = new;
	}
	else
	{
		ops_deck->tail->next = new;
		new->prev = ops_deck->tail;
		ops_deck->tail = new;
	}
}