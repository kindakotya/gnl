/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmayweat <gmayweat@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 12:08:48 by gmayweat          #+#    #+#             */
/*   Updated: 2021/01/20 14:44:43 by gmayweat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_findn(char *s)
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

static char		*fill_storage(char *buf, char *storage, int flag)
{
	char	*meow;
	int		i;

	if (!flag)
	{
		if (storage && buf)
			meow = ft_strjoin(storage, buf);
		if (!storage && buf)
			meow = ft_strdup(buf);
		if (*buf)
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
	return (meow);
}

static int		ft_free(char **storage, int flag)
{
	if (storage)
		if (*storage)
		{
			free(*storage);
			*storage = NULL;
		}
	if (flag == -1)
		return (-1);
	else if (flag == 0)
		return (0);
	return (1);
}

static size_t	fill_line(char *storage, char **line)
{
	size_t i;

	if (!storage)
	{
		*line = ft_calloc(1, sizeof(char));
		return (0);
	}
	i = 0;
	while (storage && storage[i] != '\n' && storage[i])
		++i;
	*line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (storage && storage[i] != '\n' && storage[i])
	{
		(*line)[i] = storage[i];
		++i;
	}
	return (i);
}

int				get_next_line(int fd, char **line)
{
	ssize_t			n;
	static char		*storage = NULL;
	char			buf[BUFFER_SIZE + 1];

	if (BUFFER_SIZE <= 0 || fd < 0 || !line)
		return (-1);
	n = 0;
	while (!ft_findn(storage))
	{
		ft_strnl(buf);
		n = read(fd, buf, BUFFER_SIZE);
		if (!n)
			break ;
		if (n < 0)
			return (ft_free(&storage, -1));
		storage = fill_storage(buf, storage, 0);
	}
	if (!storage && !n)
		return (fill_line(0, line));
	if (!storage[fill_line(storage, line)] && !n)
		return (ft_free(&storage, 0));
	storage = fill_storage(0, storage, 1);
	return (1);
}
