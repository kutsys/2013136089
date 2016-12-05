#include <unistd.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
  char block[1024];
  int in, out;
  char c;
  int nread;
  char i_name[52], o_name[52];
  int dot = 0;
  
  if(argc != 3) { //인자의 수가 조건에 맞지 않을 경우
    fprintf(stderr, "error : put [input filename] [output filename]\n");
    exit(1);
  }
  
  if(strlen(argv[1]) > 50||strlen(argv[2]) > 50) {  //파일명 길이 제한
    fprintf(stderr, "error : filename should not be over 100 byte\n");
    exit(1);
  }
 
  strcpy(i_name, argv[1]);
  strcpy(o_name, argv[2]);
 
  in = open(i_name, O_RDONLY);
  out = open(o_name, O_WRONLY|O_CREAT, S_IRUSR|S_IWUSR);
  
  while((nread = read(in, block, sizeof(block))) > 0 ) {
    write(out, block, nread);
    ++dot;
    if(dot%100 == 0) {
	printf(".");
	usleep(10000);
    }     
    fflush(stdout);
  }
  printf("\n");
  close(in);
  close(out);
  exit(0);
}
