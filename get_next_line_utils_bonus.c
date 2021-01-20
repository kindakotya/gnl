/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmayweat <gmayweat@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 12:10:13 by gmayweat          #+#    #+#             */
/*   Updated: 2021/01/20 15:21:52 by gmayweat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*ss;
	size_t	ss_len;

	if (!s1 || !s2)
		return (NULL);
	ss_len = ft_strlen(s1) + ft_strlen(s2);
	ss = (char *)ft_calloc((ss_len + 1), sizeof(char));
	if (!ss)
		return (NULL);
	while (*s1 != '\0')
		*ss++ = *s1++;
	while (*s2 != '\0')
		*ss++ = *s2++;
	return ((char*)(ss - ss_len));
}

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	i;

	if (!s)
		return (NULL);
	if (!s[0])
		dup = ft_calloc(1, sizeof(char));
	else
		dup = ft_calloc((ft_strlen(s) + 1), sizeof(char));
	if (!dup)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dup[i] = s[i];
		++i;
	}
	return (dup);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	void	*mem;

	i = 0;
	mem = malloc(nmemb * size);
	if (!mem)
		return (NULL);
	while (i < nmemb * size)
		((unsigned char *)mem)[i++] = '\0';
	return (mem);
}

void	ft_strnl(char *s)
{
	size_t i;

	i = 0;
	while (i <= BUFFER_SIZE)
		s[i++] = '\0';
}
