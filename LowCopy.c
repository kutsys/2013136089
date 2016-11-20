#include <unistd.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <time.h>

int main(int argc, char *argv[]) {
  int in, out;
  char block[1024];
  int nread;
  char i_name[52], o_name[52];
  
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
  if(in == -1) { perror("Open"); exit(1);}
 
  out = open(o_name, O_WRONLY|O_CREAT, S_IRUSR|S_IWUSR);
 
  while((nread = read(in, block, sizeof(block))) > 0 ) {
    if(write(out, block, nread) != nread)
      fprintf(stderr, "error : Write");
    sleep(1);
    printf(".");    
  }
  close(in);
  close(out);
}
 //////////warning 수정, dot 출력 수정
