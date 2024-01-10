#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int *p = malloc(sizeof(int));
	printf("(%d) value p stored at address %p\n", getpid(), p);
	
	while (1) {
		sleep(1);
		*p += 1;
		printf("(%d) p = %d\n", getpid(), *p);
	}

	return 0;
}
