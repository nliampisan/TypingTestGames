#ifndef GAME_H
#define GAME_H

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

#define WIDTH 7
#define HEIGHT 15

enum Color {
	DARKBLUE = 1, DARKGREEN, DARKTEAL, DARKRED, DARKPINK,
	DARKYELLOW, GRAY, DARKGRAY, BLUE, GREEN, TEAL, RED,
	PINK, YELLOW, WHITE
};

struct NodeStruct {
	char c; 
	int x; 
	int y; 
	struct Node * next; 
};

typedef struct NodeStruct Node; 

char screen[HEIGHT][WIDTH] = {
"|     |",
"|     |",
"|     |",
"|     |",
"|     |",
"|     |", 
"|     |",
"|     |",
"|     |",
"|     |",
"|     |",
"|     |",
"|     |",
"|     |",
"=======" }; 


extern void changeTextColor(int color);
extern void gotoxy(int x, int y);
void game(void); 

#endif