#include <unistd.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <time.h>

int main(int argc, char *argv[]){
  char block[1024];
  int nread;
  FILE *in, *out;
    
  if(argc != 3) { //인자의 수가 조건에 맞지 않을 경우
    fprintf(stderr, "error : put [input filename] [output filename]\n");
    exit(1);
  }
  
  if(strlen(argv[1]) > 50||strlen(argv[2]) > 50) {  //파일명 길이 제한
    fprintf(stderr, "error : filename should not be over 100 byte\n");
    exit(1);
  }
  
  if((in = fopen(argv[1], "r")) == NULL) {
    fprintf(stderr, "error : input file open error\n");
    exit(1);
  }
  
  if((out = fopen(argv[2], "w")) == NULL) {
    fprintf(stderr, "error : output file open error\n");
    exit(1);
  }
  
  while((nread = fread(block, sizeof(char), sizeof(block), in)) > 0){
    fwrite(block, sizeof(char), nread, out);
    usleep(10000);
    printf(".");
    fflush(stdout);
  }
  printf("\n");
  fclose(in);
  fclose(out);
}
