/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msnow-be <msnow-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 17:56:30 by msnow-be          #+#    #+#             */
/*   Updated: 2019/01/11 18:06:16 by msnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	clear_stack(t_stack *s)
{
	ft_memdel((void *)&(s->nums));
	ft_memdel((void *)&s);
}

void	clear_stacks(t_stack *a, t_stack *b)
{
	clear_stack(a);
	clear_stack(b);
}
