/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_right.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msnow-be <msnow-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 14:20:39 by msnow-be          #+#    #+#             */
/*   Updated: 2019/02/18 15:28:14 by msnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

/* Rotate stack back */
static void	finish_right_partition(t_stack *b_stack, int nb, char **commands,
	int offset)
{
	while (offset > 0 && (nb / 2 != b_stack->numbers_currently_in))
	{
		rotate_stack(b_stack, -1);
		*commands = add_instruction(*commands, "rrb");
		offset--;
	}
}

/* Divide stack in two parts - bigger and smaller then the median */
static void	right_partition(t_stack *a_stack, t_stack *b_stack, int nb,
	char **commands)
{
	int med = get_median(b_stack, nb);
	int i = 0;
	int offset = 0;
	while (i <= nb && ok_to_keep_parting(b_stack, med, nb, 1) != 0)
	{
		if (b_stack->nums[0] < med)
		{
			rotate_stack(b_stack, 1);
			*commands = add_instruction(*commands, "rb");
			offset++;
		}
		if (b_stack->nums[0] >= med)
		{
			push_from_to(b_stack, a_stack);
			*commands = add_instruction(*commands, "pa");
		}
		i++;
	}
	finish_right_partition(b_stack, nb, commands, offset);
}

int			quicksort_right(t_stack *a_stack, t_stack *b_stack, int nb,
	char **commands)
{
	if (nb <= 2)
	{
		if (nb == 2 && b_stack->nums[0] < b_stack->nums[1])
		{
			swap_stack_top(b_stack);
			*commands = add_instruction(*commands, "sb");
		}
		while (nb--)
		{
			push_from_to(b_stack, a_stack);
			*commands = add_instruction(*commands, "pa");
		}
		return (1);
	}
	right_partition(a_stack, b_stack, nb, commands);
	quicksort_left(a_stack, b_stack, (nb / 2 + nb % 2), commands);
	quicksort_right(a_stack, b_stack, nb / 2, commands);
	return (0);
}
