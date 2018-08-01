#ifndef MAIN_H
#define MAIN_H

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

#ifndef WPM_H
#define WPM_H
#include "wordPerMin.h"
#endif

/*
#ifndef GAME_H
#define GAME_H
#include "game.h"
#endif
*/


#ifndef MATRIX_H
#define MATRIX_H
#include "matrix.h"
#endif

#define UP 72
#define LEFT 75
#define RIGHT 77
#define DOWN 80
#define ENTER 13
#define ESC 1
enum Color { DARKBLUE = 1, DARKGREEN, DARKTEAL, DARKRED, DARKPINK, 
	DARKYELLOW, GRAY, DARKGRAY,BLUE, GREEN, TEAL, RED,
	PINK, YELLOW, WHITE };


void changeTextColor(int color); 
void gotoxy(int x, int y);
void printMenu(); 
void updateChoice(int keycode); 

#endif
