/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_debug_mode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msnow-be <msnow-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 13:35:57 by msnow-be          #+#    #+#             */
/*   Updated: 2019/02/18 15:02:45 by msnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

/* Checks whether we need to enable visualization */
void	get_mode(int *argc, char **argv, t_mode *mode)
{
	char *last_arg = argv[*argc - 1];
	if (last_arg[0] == '-' && last_arg[1] == 'v'
		&& (last_arg[2] == 'c' || last_arg[2] == '\0')
		&& (ft_strlen(last_arg) == 2 || last_arg[3] == '\0'))
	{
		mode->debug_enabled = 1;
		if (last_arg[2] == 'c')
			mode->colors_enabled = 1;
	}
	if (mode->debug_enabled == 1)
		*argc -= 1;
}
