#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main()
{
	int fd = open("meow", O_RDONLY);
	//int fd = open("warandpeace", O_RDONLY);
	char *line;
	int i;
	int j = 0;

	while ((i = get_next_line(0, &line)) != 0)
	{
		printf("j = %d %s\n", j, line);
		free(line);
		++j;
		if(j == 25059)
			write(1, "meow\n", 5);
	}
 	printf("i = %d %s\n", i, line);
	free(line);
	close(fd);
	return (0);
}
