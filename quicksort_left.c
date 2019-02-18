/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_left.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msnow-be <msnow-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 14:20:39 by msnow-be          #+#    #+#             */
/*   Updated: 2019/02/18 15:28:07 by msnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

/* Rotate stack back */
static void	finish_left_partition(t_stack *a_stack, int nb, char **commands,
	int offset)
{
	while (offset > 0 && (nb / 2 + nb % 2) != a_stack->numbers_currently_in)
	{
		rotate_stack(a_stack, -1);
		*commands = add_instruction(*commands, "rra");
		offset--;
	}
}

/* Divide stack in two parts - bigger and smaller then the median */
static void	left_partition(t_stack *a_stack, t_stack *b_stack, int nb,
	char **commands)
{
	int med = get_median(a_stack, nb);
	int i = 0;
	int offset = 0;
	while (i <= nb && ok_to_keep_parting(a_stack, med, nb, 0))
	{
		if (a_stack->nums[0] >= med)
		{
			rotate_stack(a_stack, 1);
			*commands = add_instruction(*commands, "ra");
			offset++;
		}
		else
		{
			push_from_to(a_stack, b_stack);
			*commands = add_instruction(*commands, "pb");
		}
		i++;
	}
	finish_left_partition(a_stack, nb, commands, offset);
}

int			quicksort_left(t_stack *a_stack, t_stack *b_stack, int nb,
	char **commands)
{
	if (nb <= 2)
	{
		if (nb == 2 && a_stack->nums[0] > a_stack->nums[1])
		{
			swap_stack_top(a_stack);
			*commands = add_instruction(*commands, "sa");
		}
		return (1);
	}
	left_partition(a_stack, b_stack, nb, commands);
	quicksort_left(a_stack, b_stack, nb / 2 + nb % 2, commands);
	quicksort_right(a_stack, b_stack, nb / 2, commands);
	return (0);
}
