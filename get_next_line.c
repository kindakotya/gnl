/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmayweat <gmayweat@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 12:08:48 by gmayweat          #+#    #+#             */
/*   Updated: 2020/12/01 17:53:29 by gmayweat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#define BUFFER_SIZE 50

char	*fill_storage(char *buf, char *storage)
{
	char *meow;

	meow = storage;
	storage  = ft_strjoin(storage, buf);
	free(meow);
	return(storage);
}

int		ft_free(char *line, char *storage, int flag)
{
	if (flag == -1)
	{
		free(storage);
		free(line);
		return (-1);
	}
	if (!flag)
	{
		free(storage);
		return (0);
	}
}

int		get_next_line(int fd, char **line)
{
	int		n;
	int 	i;
	static char *storage;
	char	*buf[BUFFER_SIZE];

	if (fd < 0 || (n = read(fd, buf, BUFFER_SIZE) < 0))
		return (ft_free(*line, storage, -1));
	storage = ftll_storage(buf, storage);
	return (0);
}