#ifndef MATRIX_H
#define MATRIX_H

#ifndef SECURE
#define _CRT_SECURE_NO_WARNINGS
#endif

#ifndef STUDIO
#define STUDIO
#include <stdio.h>
#endif

#ifndef WINDOWS
#define WINDOWS
#include <windows.h>
#endif

#ifndef CONIO
#define CONIO
#include <conio.h>
#endif

#ifndef TIME_H
#define TIME_H
#include <time.h>
#endif


enum Color {
	DARKBLUE = 1, DARKGREEN, DARKTEAL, DARKRED, DARKPINK,
	DARKYELLOW, GRAY, DARKGRAY, BLUE, GREEN, TEAL, RED,
	PINK, YELLOW, WHITE
};

struct CharNodeStruct {
	char c;
	int x;
	int y;
	struct CharNodeStruct * next;
};

typedef struct CharNodeStruct CharNode;

#define HEIGHT 5
#define WIDTH 5
#define ENTER 13



extern void changeTextColor(int color);
extern void gotoxy(int x, int y);
void matrix(void); 

#endif