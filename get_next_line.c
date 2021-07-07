/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproesch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 13:30:17 by cproesch          #+#    #+#             */
/*   Updated: 2021/06/07 13:30:20 by cproesch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_find_new_line(char **tmp, char **line)
{
	char *var_to_free;
	int count;

	if (!*tmp)
		*tmp = ft_substr("", 0, 0);
	count = ft_find(*tmp, '\n');
	if (count || (**tmp == '\n'))
	{
		*line = ft_substr(*tmp, 0, count);
		if (!*line)
			return (-1);
		var_to_free = *tmp;
		*tmp = ft_substr(*tmp, (count + 1), (ft_find(*tmp, '\0') - count - 1));
		free(var_to_free);
		if (!*tmp)
			return (-1);
		return (1);
	}
	return (0);
}

int ft_complete_tmp(char **tmp, char *buf)
{
	char *var_to_free;

	var_to_free = *tmp;
	*tmp = ft_strjoin(*tmp, buf);
	free(var_to_free);
	if (!*tmp)
		return (-1);
	return (1);
}

int ft_read(int fd, char *buf, int *read_return, char **tmp)
{
	*read_return = read(fd, buf, BUFFER_SIZE);
	if (*read_return == -1)
	{
		free(*tmp);
		*tmp = NULL;
		return (-1);
	}
	buf[*read_return] = '\0';
	return (*read_return);
}

int get_next_line(int fd, char **line)
{
	char buf[BUFFER_SIZE + 1];
	static char *tmp;
	int read_return;
	int is_new_line;

	if ((BUFFER_SIZE <= 0) || (fd < 0) || !line)
		return (-1);
	read_return = BUFFER_SIZE;
	while (read_return > 0)
	{
		is_new_line = ft_find_new_line(&tmp, line);
		if ((is_new_line == -1) || (is_new_line == 1))
			return (is_new_line);
		read_return = ft_read(fd, buf, &read_return, &tmp);
		if (read_return == -1)
			return (-1);
		if (!read_return)
			break;
		if (ft_complete_tmp(&tmp, buf) == -1)
			return (-1);
	}
	*line = ft_substr(tmp, 0, ft_find(tmp, '\0'));
	free(tmp);
	tmp = NULL;
	return (0);
}
