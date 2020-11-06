#include <unistd.h>
#include <signal.h>
#include <stdio.h>

int sigCount = 0;

void printC();

int main()
{
	signal(SIGINT, printC);	
	while(sigCount < 5);
	signal(SIGINT, SIG_DFL);
	pause();
	return 0;
}

void printC()
{
	sigCount++;
	printf("Ctrl + C\n");
}
