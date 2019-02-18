/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_for_small_stack.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msnow-be <msnow-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 13:48:43 by msnow-be          #+#    #+#             */
/*   Updated: 2019/02/18 15:18:50 by msnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_index_of_min_e(t_stack *a_stack)
{
	int result = 0;
	int min_value = (a_stack->nums)[0];
	int pos = 0;
	while (++pos < a_stack->numbers_currently_in)
	{
		if ((a_stack->nums)[pos] < min_value)
		{
			result = pos;
			min_value = (a_stack->nums)[pos];
		}
	}
	return (result);
}

static void	bring_min_e_up_from_front(t_stack *stack, int index_of_min,
	char **commands)
{
	int counter = 0;
	if (stack->numbers_currently_in == 3 && stack->nums[0] > stack->nums[1]
		&& stack->nums[stack->numbers_currently_in - 1] > stack->nums[0])
	{
		swap_stack_top(stack);
		*commands = add_instruction(*commands, "sa");
	}
	while (!is_sorted(stack) && index_of_min - counter != 0)
	{
		rotate_stack(stack, 1);
		*commands = add_instruction(*commands, "ra");
		counter++;
		if (index_of_min - counter == 1 &&
			stack->nums[0] < stack->nums[stack->numbers_currently_in - 1])
		{
			swap_stack_top(stack);
			*commands = add_instruction(*commands, "sa");
			counter++;
		}
	}
	return ;
}

static void	bring_min_e_up_from_end(t_stack *stack, int index_of_min,
	char **commands)
{
	int counter = 0;
	if (stack->numbers_currently_in == 3 && stack->nums[0] > stack->nums[1]
		&& stack->nums[stack->numbers_currently_in - 1] < stack->nums[0])
	{
		swap_stack_top(stack);
		*commands = add_instruction(*commands, "sa");
	}
	while (counter++ + index_of_min < stack->numbers_currently_in)
	{
		rotate_stack(stack, -1);
		*commands = add_instruction(*commands, "rra");
	}
}

/* Sorts small stack by bringing minimum elements to the secons stack
	until the first one is sorted */
void		sort_little_stack(t_stack *a_stack, t_stack *b_stack,
	char **commands)
{
	while (a_stack->numbers_currently_in > 1)
	{
		//we check whether the minimum is closer to end or front
		int index_of_min = get_index_of_min_e(a_stack);
		if (index_of_min <= a_stack->numbers_currently_in / 2)
			bring_min_e_up_from_front(a_stack, index_of_min, commands);
		else
			bring_min_e_up_from_end(a_stack, index_of_min, commands);
		if (is_sorted(a_stack))
			break ;
		push_from_to(a_stack, b_stack);
		*commands = add_instruction(*commands, "pb");
	}
	while (b_stack->numbers_currently_in > 0)
	{
		push_from_to(b_stack, a_stack);
		*commands = add_instruction(*commands, "pa");
	}
}
