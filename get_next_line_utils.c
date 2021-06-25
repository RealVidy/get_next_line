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

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_count_until_newline(char *buf)
{
	int i;
	
	i = 0;
	if (!*buf)
		return (0);
	while (buf[i])
	{	
		if (buf[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char const *s1, char *s2)
{
    char *str;
    int len1;
    int len2;
    int i;
    int j;
   
    if ((!s1) && (!s2))
        return (0);
	if (!s1)
        return (s2);
    len1 = ft_strlen(s1);
    len2 = ft_strlen(s2);
    str = malloc(sizeof(char) * (len1 + len2 + 1));
    if (!str)
        return (0);
    i = 0;
    while (s1[i])
    {
        str[i] = s1[i];
        i++;
    }
    free((void*)s1);
	j = 0;
    while (s2[j])
    {
        str[i + j] = s2[j];
        j++;
    }
	str[i + j] = 0;
    return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	strlen;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		strlen = 0;
	else if (len > (ft_strlen(s) - start))
		strlen = ft_strlen(s) - start;
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

char	*ft_strdup(const char *s1)
{
	const char	*str;

	str = malloc(sizeof(*s1) * (ft_strlen(s1) + 1));
	if (!str)
		return (NULL);
	ft_memcpy((void *)str, s1, ft_strlen(s1) + 1);
	return ((char *)str);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!src && !dst)
		return (0);
	while (i < n)
	{
		*((unsigned char *)dst + i) = *((unsigned char *)src + i);
		i++;
	}
	return (dst);
}