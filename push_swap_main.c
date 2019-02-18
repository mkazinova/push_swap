/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msnow-be <msnow-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 14:20:39 by msnow-be          #+#    #+#             */
/*   Updated: 2019/02/18 15:35:47 by msnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

char		*add_instruction(char *current, char *new)
{
	char	*result;

	if (new[ft_strlen(new) - 1] != '\n')
		new = ft_strjoin(new, "\n");
	else
		new = ft_strdup(new);
	result = ft_strjoin(current, new);
	free(current);
	free(new);
	return (result);
}

static void	give_sorting_instructions(t_stack *a_stack, t_stack *b_stack,
	char **commands)
{
	if (a_stack->numbers_currently_in > 0 && !is_sorted(a_stack))
	{
		if (a_stack->numbers_currently_in <= 10)
			sort_little_stack(a_stack, b_stack, commands);
		else
			quicksort_left(a_stack, b_stack, a_stack->numbers_currently_in,
				commands);
	}
}

int			main(int argc, char **argv)
{
	t_stack	*a_stack = build_stack_from_args(&argc, argv + 1, 0);
	if (!a_stack)
	{
		ft_putendl_fd("Error", 2);
		return (0);
	}
	t_stack	*b_stack = initialize_empty_stack(argc);
	if (!b_stack)
	{
		ft_putendl_fd("Error", 2);
		clear_stack(a_stack);
		return (0);
	}
	char *commands = ft_strnew(0);
	give_sorting_instructions(a_stack, b_stack, &commands);
	optimize_commands(&commands);
	ft_putstr(commands);
	clear_stacks(a_stack, b_stack);
	free(commands);
	return (0);
}
