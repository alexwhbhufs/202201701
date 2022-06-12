/*	과제 설명:
	
		학과: 컴퓨터공학부
		학번: 202201701
		이름: 변우형

		주제: 한국 코로나 백신 접종자 정보

*/

#include <stdio.h>
#include "Menu.h"	// [평가항목8] 다중소스파일 사용
#include "Control.h"

int main() {
	
	int code;
	char r[100];

	while (1) {
		
		code = mainmenu();	// [평가항목1] 함수사용
		
		if (code == 0) {
			clientsearch();
		}
		
		if (code == 1) {
			clientinput();
		}
		
		if (code == 2) {
			helpmenu();
		}
		
		if (code == 3) {
			clear();
			break;
		}
	}

	return 0;
}