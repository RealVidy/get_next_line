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

int ft_build_new_line(char **pointer_to_next_line, char **line)
{
	int idx;

	if (!*pointer_to_next_line)
		*pointer_to_next_line = "";

	idx = ft_find(*pointer_to_next_line, '\n');
	if (idx > 0 || (**pointer_to_next_line == '\n'))
	{
		// printf("idx: %d\n", idx);
		// We found a \n at index `idx`
		*line = ft_substr(*pointer_to_next_line, 0, idx);
		if (!*line)
			return (-1);

		*pointer_to_next_line += (idx + 1);
		if (!*pointer_to_next_line)
			return (-1);
		return (1);
	}
	return (0);
}

int get_next_line(int fd, char **line)
{
	char buf[BUFFER_SIZE + 1];
	static char *persistent_buf;
	static char *pointer_to_next_line;
	int read_return;
	int is_new_line;

	if ((BUFFER_SIZE <= 0) || (fd < 0) || !line)
		return (-1);

	do
	{
		is_new_line = ft_build_new_line(&pointer_to_next_line, line);
		if ((is_new_line == -1) || (is_new_line == 1))
			return (is_new_line);

		read_return = read(fd, buf, BUFFER_SIZE);
		if (!read_return)
			break;
		buf[read_return] = '\0';

		free(persistent_buf);
		persistent_buf = ft_strjoin("", buf);
		pointer_to_next_line = persistent_buf;
	} while (read_return > 0);

	*line = ft_substr(pointer_to_next_line, 0, ft_find(pointer_to_next_line, '\0'));
	pointer_to_next_line = NULL;
	return (0);
}
