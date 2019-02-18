/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msnow-be <msnow-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 15:44:12 by msnow-be          #+#    #+#             */
/*   Updated: 2019/01/21 14:22:10 by msnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

/* Checks if argument is a number that fits withing an integer*/
static _Bool	is_valid_arg(char *arg)
{
	if (ft_strlen(arg) > 11 || ft_atol(arg) > 2147483647 ||
		ft_atol(arg) < -2147483648)
		return (0);
	int char_pos = 0;
	if (arg[0] == '-')
		char_pos++;
	if (arg[char_pos] == '\0')
		return (0);
	while (arg[char_pos] != '\0')
	{
		if (!ft_isdigit(arg[char_pos]))
			return (0);
		char_pos++;
	}
	return (1);
}

/* Checks if argument is unique */
static _Bool	is_dulpicate(int *nums, int how_many_to_check, int value)
{
	int pos = 0;
	while (pos < how_many_to_check)
	{
		if (value == nums[pos])
			return (1);
		pos++;
	}
	return (0);
}

/* Writes numbers into a stack */
static _Bool	write_num_array(int argc, char **argv, t_stack *result)
{
	int pos = 0;
	while (pos < argc)
	{
		int new_num = ft_atoi(argv[pos]);
		if (is_valid_arg(argv[pos]) &&
			!is_dulpicate(result->nums, pos, new_num))
			result->nums[pos] = new_num;
		else
		{
			clear_stack(result);
			return (0);
		}
		pos++;
	}
	return (1);
}

/* Creates a new stack */
t_stack			*build_stack_from_args(int *argc, char **argv, t_mode *mode)
{
	*argc -= 1;
	if (mode)
		get_mode(argc, argv, mode);
	t_stack	*result = (t_stack *)malloc(sizeof(t_stack));
	if (!(*argc) || !result)
		return (NULL);
	_Bool multiargument_enabled = (get_word_count(argv[0], ' ') > 1);
	if (multiargument_enabled)
	{
		*argc = get_word_count(argv[0], ' ');
		argv = ft_strsplit(argv[0], ' ');
	}
	if (!(result->nums = (int *)malloc(sizeof(int) * *argc)))
		return (NULL);
	if (!(write_num_array(*argc, argv, result)))
		return (NULL);
	result->numbers_currently_in = *argc;
	result->name = 'A';
	if (multiargument_enabled)
		clear_string_array(*argc, argv);
	return (result);
}
