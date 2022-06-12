#define UP 72
#define DOWN 80

#include "Control.h"
#include <Windows.h>
#include <conio.h>
#include <stdio.h>


void gotoxy(int, int);
void clear();
int updowncontrol(int, int, int, int);
void enter();
int cursorx();
int cursory();

void gotoxy(int x, int y) {
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void clear() {
	system("cls");
}

int updowncontrol(int x,int y,int count1, int count2) {
	int key;

	while (1) {
		if (_kbhit) {

			key = _getch();

			if (key == 224) {

				key = _getch();

				if (key == DOWN) {
					if (y < count2) {
						gotoxy(x, y);
						printf(" ");
						gotoxy(x, ++y);
						printf(">");
					}
				}
				if (key == UP) {
					if (y > count1) {
						gotoxy(x, y);
						printf(" ");
						gotoxy(x, --y);
						printf(">");
					}
				}
			}

			if (key == 13) {
				return y;
				break;
			}
		}
	}
}

void enter() {
	int key;

	while (1) {
		if (_kbhit) {
			key = _getch();
			if (key == 13) {
				break;
			}
		}
	}
}

int cursorx() {
	CONSOLE_SCREEN_BUFFER_INFO ci;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ci);
	return ci.dwCursorPosition.X;
}

int cursory() {
	CONSOLE_SCREEN_BUFFER_INFO ci;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ci);
	return ci.dwCursorPosition.Y;
}