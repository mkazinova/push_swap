/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msnow-be <msnow-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 16:46:34 by msnow-be          #+#    #+#             */
/*   Updated: 2019/02/18 15:28:29 by msnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	rotate_stack(t_stack *stack, short direction)
{
	if (stack->numbers_currently_in <= 1)
		return ;
	if (direction == 1)
	{
		int temp = stack->nums[0];
		ft_memmove(stack->nums, stack->nums + 1,
			sizeof(int) * (stack->numbers_currently_in - 1));
		stack->nums[stack->numbers_currently_in - 1] = temp;
	}
	else
	{
		int temp = stack->nums[stack->numbers_currently_in - 1];
		ft_memmove(stack->nums + 1, stack->nums,
			sizeof(int) * (stack->numbers_currently_in - 1));
		stack->nums[0] = temp;
	}
}
