#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

void beep();

int main()
{
	signal(SIGUSR1, beep);
	pid_t _fork = fork();

	if(_fork)
	{
		//Pere
		printf("<f> waiting for alarm\n");
		pause();
		printf("<f> waiting for son's death\n");
		wait(NULL);
	}
	else
	{
		//Fils
		printf("<s> alarm amorced\n");
		sleep(5);
		
		printf("<s> alarm triggered\n");
		kill(getppid(), SIGUSR1);

		printf("<s> waiting before process' death\n");
		sleep(5);

		exit(0);
	}

	return 0;
}

void beep()
{
	printf("*BEEEEEEEP*\n");
}
