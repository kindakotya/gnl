/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmayweat <gmayweat@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 12:10:13 by gmayweat          #+#    #+#             */
/*   Updated: 2020/12/02 15:40:30 by gmayweat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	int		ss_len;

	if (!s1 || !s2)
		return (NULL);
	ss_len = ft_strlen(s1) + ft_strlen(s2);
	ss = (char *)malloc((ss_len + 1) * sizeof(char));
	if (!ss)
		return (NULL);
	while (*s1 != '\0')
		*ss++ = *s1++;
	while (*s2 != '\0')
		*ss++ = *s2++;
	*ss++ = '\0';
	return ((char*)(ss - ss_len - 1));
}

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	if (c == '\0')
		return (&(((char*)s)[ft_strlen(s)]));
	while (s[i])
	{
		if (s[i] == c)
			return (&(((char*)s)[i]));
		++i;
	}
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	char	*dup;
	int		i;

	dup = (s[0] != '\0') ? malloc(ft_strlen(s) + 1 * sizeof(char)) :
	malloc(sizeof(char));
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dup[i] = s[i];
		++i;
	}
	dup[i] = '\0';
	return (dup);
}