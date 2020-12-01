/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmayweat <gmayweat@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 12:08:48 by gmayweat          #+#    #+#             */
/*   Updated: 2020/12/01 14:16:26 by gmayweat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#define BUFFER_SIZE 50

int		get_next_line(int fd, char **line)
{
	int		n;
	int 	i;
	char	*buf[BUFFER_SIZE];

	if (fd < 0)
		return (-1);
	i = 0;
	while (n > 0)
	{
		if (n = read(fd, buf, BUFFER_SIZE) < 1)
			return(n);
		while ()
		if (!(line[i++] =
	}
	printf("BUFF = %d", BUFFER_SIZE);
	line[0][0] = 'c';
	return (fd);
}