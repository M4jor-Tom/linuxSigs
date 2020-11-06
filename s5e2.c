#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

int main(int arc, char *argv[])
{
	//Fils
	printf("\nfils en pause\n");
	pause();
	printf("\nfils termine\n");
	exit(0);

	return 0;
}
