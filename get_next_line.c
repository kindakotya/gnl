/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmayweat <gmayweat@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 12:08:48 by gmayweat          #+#    #+#             */
/*   Updated: 2020/12/02 16:26:26 by gmayweat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#define BUFFER_SIZE 50

char	*fill_storage(char *buf, char *storage)
{
	char	*meow;

	if (storage && buf)
	{
		meow = storage;
		storage  = ft_strjoin(storage, buf);
		free(meow);
	}
	if (!storage && buf)
		storage = ft_strdup(buf);
	return(storage);
}

int		ft_free(char *line, char *storage, int flag)
{
	if (flag == -1)
	{
		if (storage)
			free(storage);
		if (line)
			free(line);
		return (-1);
	}
	if (flag == 0)
	{
		if (storage)
			free(storage);
		return (0);
	}
	return (1);
}

size_t	fill_line(char *storage, char *line, size_t nline)
{
	size_t i;
	size_t j;

	i = 0;
	while (nline && storage[i])
	{
		if (storage[i] == '\n')
			--nline;
		++i;
	}
	j = i;
	while (storage[j] != '\n')
		++j;
	line = malloc((j - i) * sizeof(char));
	j = 0;
	while (storage[i] != '\n')
		line[j++] = storage[i++];
	line[j] = '\0';
	return(j);
}

int		get_next_line(int fd, char **line)
{
	ssize_t			n;
//	size_t			i;
	static size_t nline;
	static char *storage;
	char	buf[BUFFER_SIZE];

	if (fd < 0 || (n = read(fd, buf, BUFFER_SIZE) < 0))
		return (ft_free(*line, storage, -1));
	nline = (storage) ? nline + 1 : 1;
	if (buf[0] != '\0')
		storage = fill_storage(buf, storage);
	n = fill_line(storage, *line, nline);
	return (ft_free(0, storage, 0));
}