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
#include <stdio.h>

#define BUFFER_SIZE 70

// sera definit pendant la compilation pr l'evaluateur

// int	ft_if_error(int fd, char **line, char *buf)
// {
// 	int	x;
	
// 	x = 0;
// 	while(buf[x])
// 	{
// 		if ((buf[x] < 0) || (buf[x] >= 127))
// 			return (1);
// 	}
// 	return (0);
// }

int	get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*temp;
	int			read_return;
	int			count;

	if ((BUFFER_SIZE <= 0) || (fd < 0) || !line)
		return (-1);
	read_return = BUFFER_SIZE;
	while (read_return != -1)
	{
		if (!temp)
			temp = ft_strdup("");
		count = ft_count_until_newline(temp);
		if (count || (*temp == '\n'))
		{
			*line = ft_substr(temp, 0, count);
			temp = ft_substr(temp, (count + 1), (ft_strlen(temp) - count));
			return (1);
		}
		read_return = read (fd, buf, BUFFER_SIZE);
		if (read_return == -1)
			return (-1);
		buf[read_return] = '\0';
		if (!read_return)
		{
			*line = temp;
			return (0);
		}
		temp = ft_strjoin(temp, buf);
	}
	*line = temp;
	free(temp);
	return (0);
}

int	main(void)
{
	int fd;
	char **line;
	int	i;
//	line = NULL;
	fd = open("fichiertxt",O_RDONLY);

i = 0;
while(get_next_line(fd, line) > 0)
{
	i++;
	printf("Ligne %d : %s\n", i, *line);	
}
i++;
printf("Ligne %d : %s\n", i, *line);

	if (close(fd) == -1)
	{
		printf("Close failed\n");
		return (-1);
	}
	return (0);
}
