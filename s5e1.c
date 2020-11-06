#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void nothing(){}

int main()
{
	signal(SIGUSR1, nothing);

	pid_t _fork = fork();
	if(_fork)
	{
		//Pere
		//Débloquage du fils
		int i;
		for(i = 5; i > 0; i--)
		{
			printf("\nPere: interruption du fils dans %d", i);
			sleep(1);
		}
		kill(_fork, SIGUSR1);
		wait(NULL);
	}
	else
	{
		//Fils
		execv("./s5e2.o", (char* []){"s5e2.o", NULL});
	}

	return 0;
}
