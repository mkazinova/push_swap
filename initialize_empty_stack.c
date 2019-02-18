/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_empty_stack.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msnow-be <msnow-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 15:44:12 by msnow-be          #+#    #+#             */
/*   Updated: 2019/02/18 15:09:39 by msnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

t_stack			*initialize_empty_stack(int size)
{
	t_stack	*result = (t_stack *)malloc(sizeof(t_stack));
	if (!result)
		return (NULL);
	result->nums = (int *)malloc(sizeof(int) * size);
	if (!(result->nums))
		return (NULL);
	ft_bzero((*result).nums, sizeof(int) * size);
	result->numbers_currently_in = 0;
	result->name = 'B';
	return (result);
}
