/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cproesch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 14:11:06 by cproesch          #+#    #+#             */
/*   Updated: 2021/06/07 14:11:08 by cproesch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t count, size_t size);
unsigned long	ft_strlen(const char *str);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
void			*ft_memmove(void *dst, const void *src, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
int				ft_isnewline(char *buf);
char			*ft_strjoin(char const *s1, char *s2);
char 			**ft_split_one_t(char const *s, char c);
char			*ft_substr(char const *s, unsigned int start, size_t len);
int				ft_hasnewline(char *buf);
int				ft_count_until_newline(char *buf);
char			*ft_strdup(const char *s1);
void			*ft_memcpy(void *dst, const void *src, size_t n);

#endif

