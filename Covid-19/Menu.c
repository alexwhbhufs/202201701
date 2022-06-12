#define _CRT_SECURE_NO_WARNINGS

#include "Menu.h"
#include "Control.h"
#include <stdio.h>
#include <string.h>

typedef struct _default {	// [평가항목5] 구조체 사용
	int x;
	int y;
	int code;
	int code2;
	char line[100];	// [평가항목3] 배열 사용
	char var[100];
}Dflt;

typedef struct _client {
	char name[100];
	char age[3];
	char vaccine[2];
	char full[200];
}Client;

int mainmenu();
void helpmenu();
void clientsearch();
void clientinput();

int mainmenu() {
	Dflt d;

	clear();

	gotoxy(0, 0);
	printf(">[정보 조회]");
	gotoxy(1, 1);
	printf("[정보 입력]");
	gotoxy(1, 2);
	printf("[도움말]");
	gotoxy(1, 3);
	printf("[종료]");
	gotoxy(1, 0);
	
	d.code=updowncontrol(0, 0, 0, 3);
	return d.code;
}

void helpmenu() {
	
	clear();

	printf("이동:↑,↓\n");
	printf("선택/완료: ENTER");
	
	enter();
}

void clientinput() {

	clear();

	Client c;
	
	FILE* fpc = fopen("Clients.txt", "a");

	printf("이름(영문):\n");
	printf("나이:\n");
	printf("백신 접종 여부([]차, 없으면 [0]입력):[ ]");
	
	gotoxy(11, 0);
	scanf("%s", &c.name);
	gotoxy(5, 1);
	scanf("%s", &c.age);
	gotoxy(38, 2);
	scanf("%s", &c.vaccine);

	fputs("\n", fpc);	// [평가항목7] 파일 입출력
	fputs(c.name, fpc);
	fputs("/", fpc);
	
	fputs(c.age, fpc);
	fputs("/", fpc);
	
	fputs(c.vaccine, fpc);
	fclose(fpc);
}

void clientsearch() {
	Dflt d;
	int count=0;

	clear();

	gotoxy(0, 0);
	printf(">[검색]");
	gotoxy(1, 1);
	printf("[뒤로가기]");
	gotoxy(1, 0);

	d.code = updowncontrol(0, 0, 0, 3);

	if (d.code == 0) {
		
		gotoxy(0, 2);
		printf(">");
		scanf("%s", &d.var);
		gotoxy(0, 4);
		printf("<이름/나이/백신 접종 여부>\n\n");
		
		FILE* fpc = fopen("Clients.txt", "r");	// [평가항목4] 포인터 사용
		
		while (!feof(fpc)) {
			fgets(d.line, sizeof(d.line), fpc);
			if (strstr(d.line, d.var) != NULL) {
				count++;
				printf(" %s", d.line);
			}
		}
		
		if (count==0) {
			printf("일치하는 정보가 없습니다.\n");
		}
		
		else {
			printf("\n>[메인메뉴]");
			printf("\n [재검색]");
			d.y = cursory();
			gotoxy(0, d.y - 1);
			d.code2 = d.y - updowncontrol(0, d.y - 1, d.y - 1, d.y);
			if (d.code2 == 0) {
				clear();
				clientsearch();
			}
		}
	}
}