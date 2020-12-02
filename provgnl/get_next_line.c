
#include "get_next_line.h"

int				ft_free(char *buf, char *buf2, char **storage, int flag)
{
	if (flag == 1)
		return (1);
	if (flag == -1)
	{
		free(buf);
		free(buf2);
		return (flag);
	}
	if (flag == 0)
	{
		free(buf);
		free(buf2);
		if (storage)
		{
			free(*storage);
			*storage = 0;
		}
		return (flag);
	}
	return (flag);
}

char			*ft_strdup(char *str)
{
	int		len;
	char	*ptr;

	len = 0;
	if (!str)
		return (0);
	len = ft_strlen(str);
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (0);
	ptr[len] = 0;
	while (--len >= 0)
		ptr[len] = str[len];
	free(str);
	return (ptr);
}

char			*process_nullptr(void)
{
	char *ptr;

	ptr = (char *)malloc(sizeof(char) * 1);
	if (!ptr)
		return (0);
	ptr[0] = 0;
	return (ptr);
}

char			*get_newline(char **buf)
{
	char	*newline;
	char	*ptr;
	int		len;
	int		count;

	count = -1;
	ptr = *buf;
	len = 0;
	if (!ptr)
		return (process_nullptr());
	while (ptr[len] && ptr[len] != '\n')
		len++;
	newline = (char *)malloc(sizeof(char) * (len + 1));
	if (!newline)
		return (0);
	newline[len] = 0;
	while ((++count != -1) && ptr[count] && ptr[count] != '\n')
		newline[count] = ptr[count];
	if (ptr[count] == '\n')
		count++;
	len = ft_strlen(*buf) - count;
	ptr = *buf;
	*buf = ft_substr(ptr, count, len);
	return (newline);
}

int				get_next_line(int fd, char **line)
{
	char			*newline;
	static char		*storage;
	char			*buf;
	int				flag;

	flag = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	while (!check_buf(storage))
	{
		buf = read_from_fd(fd, &flag);
		if (!buf || flag == 0 || flag == -1)
		{
			if (flag == -1)
				return (ft_free(buf, storage, 0, flag));
			ft_free(buf, 0, 0, flag);
			break ;
		}
		storage = ft_strjoin(storage, buf);
	}
	if (!(newline = get_newline(&storage)))
		return (-1);
	*line = newline;
	ft_free(0, 0, &storage, flag);
	return (flag);
}
