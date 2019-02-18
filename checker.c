/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msnow-be <msnow-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 15:34:39 by msnow-be          #+#    #+#             */
/*   Updated: 2019/02/18 15:29:40 by msnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "push_swap.h"

/* Checks if the number was involed in the lat operation
	(for visualization purposes) */
_Bool	is_recently_moved(char stack_name, int stack_size, int pos,
			char *last_cmd)
{
	int cmd_size = ft_strlen(last_cmd);
	stack_name = ft_tolower(stack_name);
	if (last_cmd[0] == 's' && (last_cmd[1] == stack_name ||
		last_cmd[1] == 's') && pos < 2 && stack_size > 1)
		return (1);
	else if (last_cmd[0] == 'p' && last_cmd[1] == stack_name && pos == 0)
		return (1);
	else if (last_cmd[0] == 'r' && (last_cmd[cmd_size - 1] == stack_name ||
		last_cmd[cmd_size - 1] == 'r') && stack_size > 1)
		return (1);
	return (0);
}

void	print_stack(t_stack *stack, _Bool colors, char *last_cmd,
			_Bool cmd_makes_sense)
{
	ft_putchar(stack->name);
	ft_putstr(": ");
	int pos = 0;
	while (pos < stack->numbers_currently_in)
	{
		if (!colors || !cmd_makes_sense || !is_recently_moved(stack->name, \
			stack->numbers_currently_in, pos, last_cmd))
			ft_putnbr((stack->nums)[pos]);
		else
		{
			write(1, "\033[32m", 5);
			ft_putnbr((stack->nums)[pos]);
			write(1, "\033[0m", 4);
		}
		ft_putchar(' ');
		pos++;
	}
	ft_putchar('\n');
}

/* Checks if the command makes sense */
_Bool	is_sensible_command(t_stack *a_stack, t_stack *b_stack, char *cmd)
{
	if (cmd[0] == 's' && ((cmd[1] == 'a' &&
		a_stack->numbers_currently_in > 1) ||
		(cmd[1] == 'b' && b_stack->numbers_currently_in > 1) ||
		(cmd[1] == 's' && (a_stack->numbers_currently_in > 1 ||
		b_stack->numbers_currently_in > 1))))
		return (1);
	else if (cmd[0] == 'p' && ((cmd[1] == 'a' &&
		b_stack->numbers_currently_in > 0) || (cmd[1] == 'b'
		&& a_stack->numbers_currently_in > 1)))
		return (1);
	else if (cmd[0] == 'r')
	{
		if ((!ft_strncmp(cmd, "ra", 2) || !ft_strncmp(cmd, "rra", 3))
			&& a_stack->numbers_currently_in > 1)
			return (1);
		else if ((!ft_strncmp(cmd, "rb", 2) || !ft_strncmp(cmd, "rrb", 3))
			&& b_stack->numbers_currently_in > 1)
			return (1);
		else if ((!ft_strncmp(cmd, "rr", 2) || !ft_strncmp(cmd, "rrr", 3))
			&& (a_stack->numbers_currently_in > 1 ||
			b_stack->numbers_currently_in > 1))
			return (1);
	}
	return (0);
}

/* Reads a command from the standard inout and performs it */
_Bool	work_with_commands(t_stack *a_stack, t_stack *b_stack, t_mode mode)
{
	char	*command;
	int		read_status;

	while ((read_status = get_next_line_single_fd(0, &command)) > 0)
	{
		_Bool cmd_makes_sense = is_sensible_command(a_stack, b_stack, command);
		if (!(perform_command(command, a_stack, b_stack)))
		{
			ft_putendl_fd("Error", 2);
			free(command);
			return (0);
		}
		if (mode.debug_enabled)
		{
			ft_putendl(command);
			print_stack(a_stack, mode.colors_enabled, command, cmd_makes_sense);
			print_stack(b_stack, mode.colors_enabled, command, cmd_makes_sense);
			ft_putchar('\n');
		}
		free(command);
	}
	return (1);
}

int		main(int argc, char **argv)
{
	t_stack	*a_stack;
	t_stack	*b_stack;
	t_mode	mode;

	if (argc == 1)
		return (0);
	mode.debug_enabled = 0;
	mode.colors_enabled = 0;
	//Reads the first stack
	if (!(a_stack = build_stack_from_args(&argc, argv + 1, &mode)))
		ft_putendl_fd("Error", 2);
	//Initializes empty second stack
	if (a_stack && !(b_stack = initialize_empty_stack(argc)))
	{
		ft_putendl_fd("Error", 2);
		clear_stack(a_stack);
	}
	if (a_stack && b_stack && work_with_commands(a_stack, b_stack, mode))
	{
		if (is_sorted(a_stack) && (*b_stack).numbers_currently_in == 0)
			ft_putendl("OK");
		else
			ft_putendl("KO");
	}
	if (a_stack && b_stack)
		clear_stacks(a_stack, b_stack);
	return (0);
}
