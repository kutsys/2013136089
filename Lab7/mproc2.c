#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include "subproc_func.h"

#define EXECTO 10

void* subprocThread(void* arg) {
	subproc_func(20,10);
	return NULL;
}

int main(int argc, char* argv[]) {
	printf("2013136089, Lee Areum\n");
	srand(time(NULL));
	pthread_t threads[EXECTO];
	for(int i=0; i<EXECTO; ++i) {
		int res = pthread_create(&threads[i], NULL, subprocThread, NULL);
		if(res!=0) {
			printf("Failed\n");
			exit(EXIT_FAILURE);
		}
	}
	for(int i=0; i<EXECTO; ++i) {
		int res = pthread_join(threads[i], NULL);
		if(res!=0) {
			printf("Failed\n");
			exit(EXIT_FAILURE);
		}
	}
	printf("Finished\n");
	exit(0);
}
