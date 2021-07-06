/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproesch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 14:10:18 by cproesch          #+#    #+#             */
/*   Updated: 2021/06/07 14:10:20 by cproesch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_count(char *str, char c)
{
	int	i;

	i = 0;
	if (!str || !*str)
		return (0);
	if (c == '\0')
	{
		while (str[i] != '\0')
			i++;
		return (i);
	}
	while (str[i])
	{	
		if (str[i] == c)
			return (i);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	if ((!s1) && (!s2))
		return (NULL);
	if (!s1)
		return (s2);
	str = malloc(sizeof(char) * (ft_count(s1, '\0') + ft_count(s2, '\0') + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = 0;
	return (str);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	strlen;

	if (!s)
		return (NULL);
	if (start >= ft_count(s, '\0'))
		strlen = 0;
	else if (len > (ft_count(s, '\0') - start))
		strlen = ft_count(s, '\0') - start;
	else
		strlen = len;
	str = (char *)malloc(sizeof(*s) * (strlen + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i] && (i < strlen))
	{
		*(str + i) = *((char *)s + start + i);
		i++;
	}
	*(str + strlen) = 0;
	return (str);
}
