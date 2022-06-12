#define _CRT_SECURE_NO_WARNINGS

#include "Menu.h"
#include "Control.h"
#include <stdio.h>
#include <string.h>

typedef struct _default {	// [���׸�5] ����ü ���
	int x;
	int y;
	int code;
	int code2;
	char line[100];	// [���׸�3] �迭 ���
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
	printf(">[���� ��ȸ]");
	gotoxy(1, 1);
	printf("[���� �Է�]");
	gotoxy(1, 2);
	printf("[����]");
	gotoxy(1, 3);
	printf("[����]");
	gotoxy(1, 0);
	
	d.code=updowncontrol(0, 0, 0, 3);
	return d.code;
}

void helpmenu() {
	
	clear();

	printf("�̵�:��,��\n");
	printf("����/�Ϸ�: ENTER");
	
	enter();
}

void clientinput() {

	clear();

	Client c;
	
	FILE* fpc = fopen("Clients.txt", "a");

	printf("�̸�(����):\n");
	printf("����:\n");
	printf("��� ���� ����([]��, ������ [0]�Է�):[ ]");
	
	gotoxy(11, 0);
	scanf("%s", &c.name);
	gotoxy(5, 1);
	scanf("%s", &c.age);
	gotoxy(38, 2);
	scanf("%s", &c.vaccine);

	fputs("\n", fpc);	// [���׸�7] ���� �����
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
	printf(">[�˻�]");
	gotoxy(1, 1);
	printf("[�ڷΰ���]");
	gotoxy(1, 0);

	d.code = updowncontrol(0, 0, 0, 3);

	if (d.code == 0) {
		
		gotoxy(0, 2);
		printf(">");
		scanf("%s", &d.var);
		gotoxy(0, 4);
		printf("<�̸�/����/��� ���� ����>\n\n");
		
		FILE* fpc = fopen("Clients.txt", "r");	// [���׸�4] ������ ���
		
		while (!feof(fpc)) {
			fgets(d.line, sizeof(d.line), fpc);
			if (strstr(d.line, d.var) != NULL) {
				count++;
				printf(" %s", d.line);
			}
		}
		
		if (count==0) {
			printf("��ġ�ϴ� ������ �����ϴ�.\n");
		}
		
		else {
			printf("\n>[���θ޴�]");
			printf("\n [��˻�]");
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