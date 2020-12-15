/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmayweat <gmayweat@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 12:08:48 by gmayweat          #+#    #+#             */
/*   Updated: 2020/12/15 17:52:09 by gmayweat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//#include <stdio.h>
//#define BUFFER_SIZE 50

int		ft_findn(char *s)
{
	size_t i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		{
			if (s[i] == '\n')
				return (1);
			++i;
		}
	return (0);
}

char	*fill_storage(char **buf, char *storage, int flag)
{
	char	*meow;
	int		i;

	if (!flag)
	{
		if (storage && **buf)
			meow  = ft_strjoin(storage, *buf);
		if (!storage && **buf)
			meow = ft_strdup(*buf);
		if (**buf)
			ft_strnl(buf);
	}
	else
	{
		i = 0;
		while (storage[i] != '\n' && storage[i])
			++i;
		meow = ft_strdup(storage + i + 1);
	}
	if (storage)
		free(storage);
	return(meow);
}

int		ft_free(char *line, char *storage, char *buf, int flag)
{
	if (buf)
		free(buf);
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

size_t	fill_line(char *storage, char **line)
{
	size_t i;

	i = 0;
	while (storage[i] != '\n' && storage[i])
		++i;
	*line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (storage[i] != '\n' && storage[i])
	{
		(*line)[i] = storage[i];
		++i;
	}
	return(i);
}

int		get_next_line(int fd, char **line)
{
	ssize_t			n;
	static char *storage;
	char	*buf;

	if (!(buf = ft_calloc((BUFFER_SIZE + 1), sizeof(char))))
		return (ft_free(0, storage, 0, -1));

	while (!(ft_findn(storage)) && n)
	{
		n = read(fd, buf, BUFFER_SIZE);
//		printf("\nbuf = %s\n", buf);
		if (!n)
			break;
		if (fd < 0 || n < 0)
			return (ft_free(*line, storage, buf, -1));
		if (buf)
			storage = fill_storage(&buf, storage, 0);
	}
	if (!storage[fill_line(storage, line)] && !n)
		return (ft_free(0, storage, buf, 0));
	storage = fill_storage(0, storage, 1);
	return (ft_free(0, 0, buf, 1));
}