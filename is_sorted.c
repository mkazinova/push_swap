/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msnow-be <msnow-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 15:00:38 by msnow-be          #+#    #+#             */
/*   Updated: 2019/02/18 15:09:56 by msnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

_Bool	is_sorted(t_stack *stack)
{
	int pos = 0;
	while (pos < (*stack).numbers_currently_in - 1)
	{
		if ((*stack).nums[pos] > (*stack).nums[pos + 1])
			return (0);
		pos++;
	}
	return (1);
}
