/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmayweat <gmayweat@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 12:10:19 by gmayweat          #+#    #+#             */
/*   Updated: 2020/12/15 17:52:12 by gmayweat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>

int		get_next_line(int fd, char **line);
int		meow(int i);
size_t	ft_strlen(const char *s);
char		*ft_strjoin(const char *s1, const char *s2);
char	*ft_strdup(const char *s);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_findn(char *s);
void	ft_strnl(char **s);

#endif