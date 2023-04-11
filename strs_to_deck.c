/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strs_to_deck.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:24:31 by joonhlee          #+#    #+#             */
/*   Updated: 2023/04/11 19:31:49 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

static t_ps_deck	*free_nbrs_deck(char **nbrs, t_ps_deck *a);

t_ps_deck	*strs_to_deck(char **nbrs)
{
	t_ps_deck	*a;
	t_ps_node	*new_node;
	int			i;
	int			check;
	int			raw;

	a = ps_new_deck();
	if (a == 0)
		return (free_nbrs_deck(nbrs, 0));
	i = 0;
	while (nbrs[i])
	{
		check = 0;
		raw = ps_atoi(nbrs[i], &check);
		if (check < 0)
			return (free_nbrs_deck(nbrs, a));
		new_node = ps_new_node(raw);
		if (new_node == 0 || check < 0)
			return (free_nbrs_deck(nbrs, a));
		ps_add_bottom(a, new_node);
		i++;
	}
	return (a);
}

static t_ps_deck	*free_nbrs_deck(char **nbrs, t_ps_deck *a)
{
	int	i;

	i = 0;
	if (a != 0)
		ps_clear_deck(a);
	if (nbrs == 0)
		return (0);
	while (nbrs[i])
	{
		free (nbrs[i]);
		nbrs[i] = 0;
		i++;
	}
	return (0);
}

int	ps_atoi(const char *str, int *check)
{
	int		i;
	int		sign;
	long	nbr;

	i = 0;
	sign = 1;
	nbr = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '+' || str[i] == '-')
		sign = 44 - str[i++];
	while (str[i] >= '0' && str[i] <= '9' && *check >= 0)
	{
		if (sign > 0 && ((nbr > INT_MAX / 10) || (nbr == INT_MAX / 10
					&& str[i] - '0' > INT_MAX % 10)))
			*check = -1;
		if (sign < 0 && ((nbr < INT_MIN / 10) || (nbr == INT_MIN / 10
					&& sign * (str[i] - '0') < INT_MIN % 10)))
			*check = -1;
		nbr = nbr * 10 + sign * (str[i++] - '0');
	}
	return ((int)nbr);
}

int	have_duplicate(t_ps_deck *a)
{
	t_ps_node	*node_i;
	t_ps_node	*node_j;

	if (a == 0)
		return (1);
	if (a->n_node == 1)
		return (0);
	node_i = a->top;
	while (node_i)
	{
		node_j = node_i->next;
		while (node_j)
		{
			if (node_i->raw == node_j->raw)
				return (1);
			node_j = node_j->next;
		}
		node_i = node_i->next;
	}
	return (0);
}
