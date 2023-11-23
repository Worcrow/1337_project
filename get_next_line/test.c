#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
	int fd = open("fl.txt", O_RDONLY);
	char *res;

	res = get_next_line(fd);
	if (!res)
		printf("not res\n");
	while (res)
	{
		printf("%s", res);
		free(res);
		res = get_next_line(fd);
	}
	return (0);
}
