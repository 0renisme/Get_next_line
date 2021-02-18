#include "get_next_line.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	int		fd;
	char	*line;

	fd = 0;
	if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		printf("%s\n", line);
		free(line);
	}
	printf("%s\n", line);
	free(line);
	if (fd > 0)
		close(fd);
/*
**	system("leaks a.out");
*/

	return (0);
}

