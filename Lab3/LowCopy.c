#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include<stdio.h>
int main()
{
  char block[1024];
	int in, out;
	int nread;
	int count = 0;
  int printDot = 0;
	in = open("file.in",O_RDONLY);
	out = open("file.out",O_WRONLY|O_CREAT,S_IRUSR|S_IWUSR);

	while((nread = read(in,block,sizeof(block))) > 0){
		write(out,block,nread);
		count++;
		if(count % 1024 == 0){
			 printf(".");
       printDot++;
       }	
  }
	printf("\nCopy is Finished.\n");
  printf("\nDOT : %d", printDot);
	exit(0);
}