#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
void main()
{
	int pid;
	int ret;
	int value;
	char fifoname[]="/tmp/testfifo";
	char sentence[20];
	char output[20];
	FILE *cfp;
 	 FILE *pfp;

	ret = mkfifo(fifoname,0600);
	pid = fork();
	if(pid==0)
	{
		cfp=fopen(fifoname,"r");
		ret=fscanf(cfp,"%[^\n]",output);
		 fclose(cfp);
		printf("This is the child. Received value %s from parent on fifo \n", output);
		unlink(fifoname); /* Delete the created fifo */
      		exit(0);
	}
	else
	{
		pfp = fopen(fifoname,"w");
		printf("write\n");
		fgets(sentence, sizeof(sentence), stdin);
		ret=fprintf(pfp,"%s",sentence);
		fclose(pfp);
	}
}
