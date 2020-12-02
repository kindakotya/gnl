
#include "get_next_line.h"

int		check_buf(char *buf)
{
	if (!buf)
		return (0);
	while (*buf)
		if (*buf++ == '\n')
			return (1);
	return (0);
}

char	*read_from_fd(int fd, int *flag)
{
	char	*buf;
	int		len;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
	{
		*flag = -1;
		return (0);
	}
	len = read(fd, buf, BUFFER_SIZE);
	if (len < 0)
	{
		free(buf);
		*flag = -1;
		return (0);
	}
	if (len == 0)
	{
		free(buf);
		*flag = 0;
		return (0);
	}
	buf[len] = 0;
	*flag = 1;
	return (buf);
}

int		ft_strlen(char *str)
{
	int len;

	if (!str)
		return (0);
	len = 0;
	while (*str++)
		len++;
	return (len);
}

char	*ft_substr(char *s, int start, int len)
{
	char	*ptr;
	int		count;
	int		iter;

	if (!s)
		return (0);
	if (start >= ft_strlen(s))
		len = 0;
	ptr = (char *)malloc(sizeof(*s) * (len) + 1);
	if (!ptr)
		return (0);
	iter = -1;
	count = start;
	while (++iter < len)
		ptr[iter] = s[count++];
	ptr[iter] = 0;
	free(s);
	return (ptr);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ptr;
	int		len1;
	int		len2;

	if (!s1)
		return (ft_strdup(s2));
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	ptr = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (ptr == 0)
		return (0);
	ptr[len1 + len2] = 0;
	while (len2--)
		ptr[len1 + len2] = s2[len2];
	while (len1--)
		ptr[len1] = s1[len1];
	free(s2);
	free(s1);
	return (ptr);
}
