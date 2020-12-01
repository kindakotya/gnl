#include "get_next_line.h"
int main()
{
	char **line;
	line = malloc(sizeof(char*));
	line[0] = malloc(sizeof(char));
	get_next_line(0, line);
	return (0);
}