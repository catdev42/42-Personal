// #include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
// #include <string.h>
// #include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>

int	main(int argc, char *argv[])
{
	int pid;

	pid = fork();
	if (pid == -1)
		return (1);
	if (pid == 0)
	{
		while (1)
		{
			printf("One line\n");
			usleep(50000);
		}
	}
	else
	{
		kill(pid, SIGSTOP);
		sleep(1);
		kill(pid, SIGCONT);
		sleep(1);
		kill(pid, SIGKILL);
		wait(NULL);
	}
}
