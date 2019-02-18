/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msnow-be <msnow-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 15:11:36 by msnow-be          #+#    #+#             */
/*   Updated: 2019/02/18 15:01:43 by msnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	ft_atol(char *str)
{
	int pos = 0;
	int sign = 1;
	while (((str[pos] >= '\t') && (str[pos] <= '\r')) || (str[pos] == ' '))
		pos++;
	if (str[pos] == '-')
	{
		sign = -1;
		pos++;
	}
	else if (str[pos] == '+')
		pos++;

	long ans = 0;
	while ((str[pos] >= '0') && (str[pos] <= '9'))
	{
		ans *= 10;
		ans += str[pos] - '0';
		pos++;
	}
	return (ans * sign);
}
