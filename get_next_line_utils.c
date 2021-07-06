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

size_t ft_count(char *str, char c)
{
	if (!str)
		return 0;

	int i = 0;
	while (str[i] != '\0' && str[i] != c)
		i++;

	return (str[i] == c) ? i : 0;
}

int ft_strlen(char *s)
{
	return ft_count(s, '\0');
}

char *ft_strjoin(char *s1, char *s2)
{
	char *str;
	int i;
	int j;

	if ((!s1) && (!s2))
		return (NULL);
	if (!s1)
		return (s2);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
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

char *ft_substr(char *s, unsigned int start, size_t len)
{
	char *str;
	size_t i;
	size_t strlen;

	if (!s)
		return (NULL);
	size_t original_len = ft_strlen(s);
	if (start >= original_len)
		return "";

	strlen = MIN(MAX(0, original_len - start), len);

	str = (char *)malloc(sizeof(*s) * (strlen + 1));
	if (!str)
		return (NULL);

	i = 0;
	while (s[i] && (i < strlen))
	{
		str[i] = s[start + i];
		i++;
	}
	str[strlen] = 0;
	return (str);
}
