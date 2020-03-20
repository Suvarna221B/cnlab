#include<stdio.h>
#include<unistd.h>
void main()
{
	int pid,pip[2];
	char instring[20];
	pipe(pip);
	pid = fork();
	if(pid==0)
	{
		read(pip[0],instring,7);
		write(1,instring,7);
	}
	else
	{
		write(pip[1],"hey1234",7);
	}
}
