#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <time.h>

int main(void){
	char block[1024];
  int nread;
  FILE *in, *out;
    
  if((in = fopen("source.txt", "r")) == NULL) {
    fprintf(stderr, "error : input file open error\n");
    exit(1);
  }
  
  if((out = fopen("copy.txt", "w")) == NULL) {
    fprintf(stderr, "error : output file open error\n");
    exit(1);
  }
  
  while((nread = fread(block, sizeof(char), sizeof(block), in)) > 0){
    fwrite(block, sizeof(char), nread, out);
    sleep(1);
    printf(".");
  }
  printf("\n");
  fclose(in);
  fclose(out);
}
