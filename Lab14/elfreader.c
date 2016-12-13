#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 100

void checkFile(char* argv)
{
	if(access(argv,F_OK)==-1)
	{
		printf("could not find the file %s \n", argv);
		exit(1);
    	}
}

void checkOption(char* argv1,char* argv2)
{
char temp[SIZE];
	if(strstr(argv1,"e") != NULL)
   	{
		sprintf(temp,"readelf -h %s",argv2);
		system(temp);
	}

   	if(strstr(argv1,"p") != NULL)
	{
		sprintf(temp,"readelf -l %s",argv2);
		system(temp);
 	}

    	if(strstr(argv1,"s") != NULL)
    	{
		sprintf(temp,"readelf -S %s",argv2);
		system(temp);
    	}

}

int main(int argc,char* argv[])
{
char temp[SIZE];
	switch(argc)
	{
	case 2:
		sprintf(temp,"readelf -h %s",argv[1]);	
		checkFile(argv[1]);
		break;
	case 3:
		checkFile(argv[2]);
		checkOption(argv[1],argv[2]);
		break;
	default:
		printf("put the filename\n");
		break;
	}
	return 0;
}
