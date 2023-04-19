/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_all5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 09:08:31 by joonhlee          #+#    #+#             */
/*   Updated: 2023/04/19 09:38:21 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_greatest_power_two(int n)
{
	int	power;

	if (n < 1)
		return (-1);
	power = 1;
	while (2 * power <= n)
		power = power * 2;
	return (power);
}

int	get_exponent(int n)
{
	int	power;
	int	exponet;

	if (n < 1)
		return (-1);
	power = 1;
	exponet = 0;
	while (2 * power <= n)
	{
		power = power * 2;
		exponet++;
	}
	return (exponet);
}

int	max(int a, int b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}
