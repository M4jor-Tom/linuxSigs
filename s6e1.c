#include <unistd.h>
#include <signal.h>
#include <stdio.h>

void beep();

int main()
{
	signal(SIGALRM, beep);
	alarm(5);
	printf("alarme dans 5s\n");
	pause();

	return 0;
}

void beep()
{
	printf("*BEEEEEEEP*\n");
}
