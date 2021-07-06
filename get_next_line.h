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
#define GET_NEXT_LINE_H

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 70
#endif

size_t ft_count(char *buf, char c);
char *ft_strjoin(char *s1, char *s2);
char *ft_substr(char *s, unsigned int start, size_t len);
int ft_init(int fd, char **line, int *read_return);
int ft_find_new_line(char **temp, char **line);
int ft_complete_temp(char **temp, char *buf);
int ft_read(int fd, char *buf, int *read_return, char **temp);
int get_next_line(int fd, char **line);

#endif
