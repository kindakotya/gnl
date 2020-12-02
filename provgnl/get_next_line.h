

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

int		check_buf(char *buf);
int		get_next_line (int fd, char **line);
int		ft_strlen(char *str);
char	*read_from_fd(int fd, int *flag);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, int start, int len);

char	*get_newline(char **buf);
char	*ft_strdup(char *str);

#endif
