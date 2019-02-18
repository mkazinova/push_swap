/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msnow-be <msnow-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 15:01:15 by msnow-be          #+#    #+#             */
/*   Updated: 2019/02/18 15:15:35 by msnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

_Bool	perform_swaps(char *command, t_stack *a_stack, t_stack *b_stack)
{
	if (command[1] == 'a' && command[2] == '\0')
		swap_stack_top(a_stack);
	else if (command[1] == 'b' && command[2] == '\0')
		swap_stack_top(b_stack);
	else if (command[1] == 's' && command[2] == '\0')
	{
		swap_stack_top(a_stack);
		swap_stack_top(b_stack);
	}
	else
		return (0);
	return (1);
}

_Bool	perform_pushes(char *command, t_stack *a_stack, t_stack *b_stack)
{
	if (command[1] == 'a' && command[2] == '\0')
		push_from_to(b_stack, a_stack);
	else if (command[1] == 'b' && command[2] == '\0')
		push_from_to(a_stack, b_stack);
	else
		return (0);
	return (1);
}

_Bool	perform_rotations(char *command, t_stack *a_stack, t_stack *b_stack)
{
	if (command[1] == 'a' && command[2] == '\0')
		rotate_stack(a_stack, 1);
	else if (command[1] == 'b' && command[2] == '\0')
		rotate_stack(b_stack, 1);
	else if (command[1] == 'r' && command[2] == '\0')
	{
		rotate_stack(a_stack, 1);
		rotate_stack(b_stack, 1);
	}
	else if (command[1] == 'r' && command[2] == 'a' && command[3] == '\0')
		rotate_stack(a_stack, -1);
	else if (command[1] == 'r' && command[2] == 'b' && command[3] == '\0')
		rotate_stack(b_stack, -1);
	else if (command[1] == 'r' && command[2] == 'r' && command[3] == '\0')
	{
		rotate_stack(a_stack, -1);
		rotate_stack(b_stack, -1);
	}
	else
		return (0);
	return (1);
}

/* Checks for the type of command to use and tries to perform it */
_Bool	perform_command(char *command, t_stack *a_stack, t_stack *b_stack)
{
	_Bool success;

	if (command[0] == 's')
		success = perform_swaps(command, a_stack, b_stack);
	else if (command[0] == 'p')
		success = perform_pushes(command, a_stack, b_stack);
	else if (command[0] == 'r')
		success = perform_rotations(command, a_stack, b_stack);
	else
		success = 0;
	return (success);
}
