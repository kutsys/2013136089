#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>

void printdir(char *dir,int depth){
	DIR *dp;
	struct dirent *entry;
	struct stat statbuf;

	if((dp = opendir(dir)) == NULL){	//dir로 디렉토리 열기에 실패하면 오류메세지 출력 후 함수 종료
		fprintf(stderr,"cannot open dirctory: %s\n", dir);
		return;
	}
	
	chdir(dir);	//문자열 dir에 저장되어있는 디렉토리로 이동
	while((entry=readdir(dp)) != NULL) {	//포인터 dp에 저장된 값을 entry에 저장
		lstat(entry->d_name, &statbuf);

		
		if(S_ISDIR(statbuf.st_mode)) {	//상태버퍼의 모드 값을 검사하였는데, 디렉토리이면
			if(strcmp(".",entry->d_name) ==0 ||
			   strcmp("..",entry->d_name) ==0) continue;
			//문자열이 ‘.’ 또는 ‘..’이면 다음 엔트리 읽어들이기	
			if(entry->d_name[0]=='.') continue;		//Hidden 디렉토리는 무시
			//디렉토리나 파일이면
			printf("%*s%s/\n",depth,"",entry->d_name);	//디렉토리 depth와 디렉토리명을 출력
			printdir(entry->d_name,depth+4);	//디렉토리명으로 재귀호출
		}else {	//디렉토리가 아닌 파일일 경우
			
			if(entry->d_name[0] == '.') continue;	//Hidden파일은 무시
			printf("%*s%s\n",depth,"",entry->d_name);	//depth와 파일명 출력
		}	
	}
	chdir("..");	//이전 디렉토리로 이동
	closedir(dp);	//디렉토리 닫기
}

int main(){
	printf("Directory scan of /home:\n");
	printdir(".",0);
	printf("done.\n");
	exit(0);
}
