/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_single_fd.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msnow-be <msnow-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 11:27:21 by msnow-be          #+#    #+#             */
/*   Updated: 2019/02/18 15:23:47 by msnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

static char	*extract_line(char **text, int *status)
{
	size_t end = 0;
	char *str = *text;
	while ((str[end] != '\n') && (str[end] != '\0'))
		end++;
	if (str[end] == '\n')
		*status = 1;

	char *result = ft_strsub(str, 0, end);
	if (!result)
		return (NULL);

	char *str_end = ft_strsub(str, end + 1, ft_strlen(str) - end);
	if (!str_end)
	{
		free(result);
		return (NULL);
	}
	free(str);
	*text = str_end;
	return (result);
}

/* Reads next line from the standart input */
int			get_next_line_single_fd(const int fd, char **line)
{
	static char	*read_registry;
	char		buf[BUFF_SIZE + 1];
	int			status;

	if (!line || (fd < 0))
		return (-1);
	while ((status = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[status] = '\0';
		if (!read_registry)
			read_registry = ft_strnew(1);
		char *tmp = ft_strjoin(read_registry, buf);
		free(read_registry);
		read_registry = tmp;
		if (ft_strchr(read_registry, '\n'))
			break ;
	}
	if ((status > 0) || (!status && ((read_registry != (NULL))
		&& (read_registry[0] != '\0'))))
	{
		*line = extract_line(&read_registry, &status);
		status = (!(*line) ? -1 : 1);
	}
	return (status);
}
