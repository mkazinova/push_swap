/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_median.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msnow-be <msnow-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 14:20:39 by msnow-be          #+#    #+#             */
/*   Updated: 2019/02/18 15:22:03 by msnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Find the median value in an array */
int	get_median(t_stack *stack, int nbelem)
{
	int i = 0;
	while (i < nbelem)
	{
		int med = 0;
		int j = 0;
		int nb = stack->nums[i];
		while (j < nbelem)
		{
			if (nb != stack->nums[j])
				(stack->nums[j] > nb) ? med++ : med--;
			j++;
		}
		if (med == (nbelem % 2 == 0 ? -1 : 0))
			return (stack->nums[i]);
		i++;
	}
	return (0);
}

int	ok_to_keep_parting(t_stack *stack, int med, int nb, _Bool right)
{
	int i = 0;
	while (i < nb && i < stack->numbers_currently_in)
	{
		if (stack->nums[i] < med && right == 0)
			return (1);
		if (stack->nums[i] >= med && right == 1)
			return (1);
		i++;
	}
	return (0);
}
