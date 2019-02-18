/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimisation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msnow-be <msnow-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 13:51:53 by msnow-be          #+#    #+#             */
/*   Updated: 2019/02/18 15:14:47 by msnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

/* Removes a useless command */
static char	*remove_cmd(char *commands, char *cmd)
{
	unsigned int start = ft_strstr(commands, cmd) - commands + 1;
	char *left = ft_strsub(commands, 0, start);
	char *right = ft_strsub(commands, start + ft_strlen(cmd) - 1,
		ft_strlen(commands) - start - ft_strlen(cmd) + 1);
	char *result = ft_strjoin(left, right);
	free(commands);
	free(left);
	free(right);
	return (result);
}

/* Removes old command and replaces it with a new one */
static char	*remove_and_replace(char *commands, char *old, char *new)
{
	unsigned int start = ft_strstr(commands, old) - commands;
	char *left = ft_strsub(commands, 0, start);
	left = add_instruction(left, new);
	char *right = ft_strsub(commands, start + ft_strlen(old),
		ft_strlen(commands) - start - ft_strlen(old));
	char *result = ft_strjoin(left, right);
	free(commands);
	free(left);
	free(right);
	return (result);
}

/* Checks for command combinations that negate each other
	We use quicksort for sorting which is effective but generates
	mutually exclusive commands from time to time in case of stacks*/
void		optimize_commands(char **commands)
{
	while (ft_strstr(*commands, "\npa\npb\n"))
		*commands = remove_cmd(*commands, "\npa\npb\n");
	while (ft_strstr(*commands, "\npb\npa\n"))
		*commands = remove_cmd(*commands, "\npb\npa\n");
	while (ft_strstr(*commands, "\nra\nrra\n"))
		*commands = remove_cmd(*commands, "\nra\nrra\n");
	while (ft_strstr(*commands, "\nrra\nra\n"))
		*commands = remove_cmd(*commands, "\nrra\nra\n");
	while (ft_strstr(*commands, "\nrb\nrrb\n"))
		*commands = remove_cmd(*commands, "\nrb\nrrb\n");
	while (ft_strstr(*commands, "\nrrb\nrb\n"))
		*commands = remove_cmd(*commands, "\nrrb\nrb\n");
	while (ft_strstr(*commands, "\nra\nrb\n"))
		*commands = remove_and_replace(*commands, "\nra\nrb\n", "\nrr\n");
	while (ft_strstr(*commands, "\nrb\nra\n"))
		*commands = remove_and_replace(*commands, "\nrb\nra\n", "\nrr\n");
	while (ft_strstr(*commands, "\nrra\nrrb\n"))
		*commands = remove_and_replace(*commands, "\nrra\nrrb\n", "\nrrr\n");
	while (ft_strstr(*commands, "\nrrb\nrra\n"))
		*commands = remove_and_replace(*commands, "\nrrb\nrra\n", "\nrrr\n");
	while (ft_strstr(*commands, "\nsa\nsb\n"))
		*commands = remove_and_replace(*commands, "\nsa\nsb\n", "\nss\n");
	while (ft_strstr(*commands, "\nsb\nsa\n"))
		*commands = remove_and_replace(*commands, "\nsb\nsa\n", "\nss\n");
}
