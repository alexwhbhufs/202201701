/*	���� ����:
	
		�а�: ��ǻ�Ͱ��к�
		�й�: 202201701
		�̸�: ������

		����: �ѱ� �ڷγ� ��� ������ ����

*/

#include <stdio.h>
#include "Menu.h"	// [���׸�8] ���߼ҽ����� ���
#include "Control.h"

int main() {
	
	int code;
	char r[100];

	while (1) {
		
		code = mainmenu();	// [���׸�1] �Լ����
		
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