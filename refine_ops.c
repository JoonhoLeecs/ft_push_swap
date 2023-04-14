/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refine_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 13:33:05 by joonhlee          #+#    #+#             */
/*   Updated: 2023/04/14 13:51:57 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	refine_ops(t_ops_deck *ops)
{
	int	check;

	if (ops->head == 0)
		return (0);
	if (ops->head->next == 0)
		return (0);
	check = combine_to_rr(ops);
	if (check == 0)
		check = combine_to_rrr(ops);
	if (check == 0)
		check = combine_to_ss(ops);
	if (check != 0)
		return (1);
}

int	combine_to_rr(t_ops_deck *ops)
{
	t_op_node	*top_node;
	t_op_node	*bottom_node;
	int			check;
	int			count;

	top_node = ops->head;
	bottom_node = top_node->next;

}
