/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_subseq2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 22:11:41 by joonhlee          #+#    #+#             */
/*   Updated: 2023/04/14 11:21:30 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clear_sub(t_ps_subseq *a)
{
	a->top = 0;
	a->bottom = 0;
	a->next_sub = 0;
	a->prev_sub = 0;
	free(a);
}
