#include <stdio.h>
#include <time.h>

int main (void) 
{
    char buff[100];
    time_t now = time (0);
	
    	while(1)
	{
    		now = time(0);
		strftime (buff, 100, "%Y-%m-%d %H:%M:%S.000", localtime (&now));	
  		printf ("%s\n", buff);
		sleep(2);
		fflush(stdout);
	}

    return 0;
}
