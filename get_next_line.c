/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmayweat <gmayweat@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 12:08:48 by gmayweat          #+#    #+#             */
/*   Updated: 2020/12/11 22:44:47 by gmayweat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
//#define BUFFER_SIZE 50

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

int		ft_free(char *line, char *storage, char *buf, size_t *nline, int flag)
{
	if (buf)
		free(buf);
	if (flag == -1)
	{
		if (storage)
			free(storage);
		if (line)
			free(line);
		*nline = 0;
		return (-1);
	}
	if (flag == 0)
	{
		if (storage)
			free(storage);
		*nline = 0;
		return (0);
	}
	return (1);
}

size_t	fill_line(char *storage, char **line, size_t nline)
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
	while (storage[j] != '\n' && storage[j])
		++j;
	*line = malloc((j - i + 1) * sizeof(char));
	j = 0;
	while (storage[i] != '\n' && storage[i])
		(*line)[j++] = storage[i++];
	(*line)[j] = '\0';
	while (storage[i] == '\n' && storage[i])
		++i;
	return(i);
}

int		get_next_line(int fd, char **line)
{
	static ssize_t			n;
//	size_t			i;
	static size_t nline;
	static char *storage;
	char	*buf;

	if (!storage || n)
	{
		buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (fd < 0 || (n = read(fd, buf, BUFFER_SIZE) < 0))
			return (ft_free(*line, storage, buf, &nline, -1));
		buf[BUFFER_SIZE] = '\0';
	}
	else
		buf = NULL;
	nline = (storage) ? nline + 1 : 0;
	if (buf)
		storage = fill_storage(buf, storage);
	if (!storage[fill_line(storage, line, nline)])
		return (ft_free(0, storage, buf, &nline, 0));
	return (ft_free(0, 0, buf, 0, 1));
}