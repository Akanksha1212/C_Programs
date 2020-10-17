#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	// fork() creates child process identical to parent
	int pid = fork();

	// if pid is greater than 0 than it is parent process
	// if pid is 0 then it is child process
	// if pid is -ve , it means fork() failed to create child process

	// Parent process
	if (pid > 0)
		sleep(20);

	// Child process
	else
	{
		exit(0);
	}
	
	return 0;

}
