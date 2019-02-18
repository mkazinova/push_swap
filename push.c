/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msnow-be <msnow-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 16:32:56 by msnow-be          #+#    #+#             */
/*   Updated: 2018/12/26 14:47:00 by msnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	push_from_to(t_stack *from, t_stack *to)
{
	if ((*from).numbers_currently_in > 0)
	{
		ft_memmove(to->nums + 1, to->nums,
			sizeof(int) * to->numbers_currently_in);
		to->nums[0] = from->nums[0];
		to->numbers_currently_in += 1;
		from->numbers_currently_in -= 1;
		ft_memmove(from->nums, from->nums + 1,
			sizeof(int) * from->numbers_currently_in);
		from->nums[from->numbers_currently_in] = 0;
	}
}
