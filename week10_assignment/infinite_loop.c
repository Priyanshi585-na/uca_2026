#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

volatile sig_atomic_t signal_count = 0;

void handle_sigint(int sig)
{
	signal_count++;

	if(signal_count >= 3)
		exit(0);
}

int main()
{
	signal(SIGINT, handle_sigint);

	while(1)
		sleep(1);
}
