/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_array_helpers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msnow-be <msnow-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 15:48:33 by msnow-be          #+#    #+#             */
/*   Updated: 2019/02/18 15:29:20 by msnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

/* Counts the number of words in a string witha  given delimeter */
int			get_word_count(char const *s, char c)
{
	if ((s == NULL) || (s[0] == '\0'))
		return (0);
	int res = (s[0] != c);
	int pos = 1;
	while (s[pos])
	{
		if (s[pos - 1] == c && s[pos] != c)
			res++;
		pos++;
	}
	return (res);
}

void		clear_string_array(int size, char **tab)
{
	int pos = 0;
	while (pos < size)
	{
		free(tab[pos]);
		pos++;
	}
	free(tab);
}
