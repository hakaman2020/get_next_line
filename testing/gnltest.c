#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"
#include <stdlib.h>

int 	main(void)
{
	char *line;
	int gnl_return = 1;
	int fd = open("test.txt",O_RDONLY);

	while (gnl_return == 1)
	{	
		gnl_return = get_next_line(fd, &line);
		if(gnl_return == -1)
			break;
		printf("return of GNL : %d\n", gnl_return);
		printf("%s\n", line);
		free(line);
	}
//	while(1); //for memory leak test
	return (0);
}