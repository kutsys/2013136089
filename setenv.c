#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

	setenv("TEST_ENV", "1234", 0);
	//(환경 변수 이름, 변수 값, 이미 같은 이름의 변수가 있다면 값을 변경할지 여부)
	printf("TEST_ENV : %s\n", getenv("TEST_ENV"));

	exit(0);
}
