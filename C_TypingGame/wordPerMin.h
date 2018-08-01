#ifndef WPM_H
#define WPM_H

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


#define NAME_SIZE 100
#define NUM_FILES 3
#define LINE_SIZE 50
#define FILE_ERROR -1
#define ENTER 13


enum Color {
	DARKBLUE = 1, DARKGREEN, DARKTEAL, DARKRED, DARKPINK,
	DARKYELLOW, GRAY, DARKGRAY, BLUE, GREEN, TEAL, RED,
	PINK, YELLOW, WHITE
};

const char files[NUM_FILES][NAME_SIZE] = { "file1.txt", "file2.txt", "file3.txt" }; 

extern void changeTextColor(int color);
extern void gotoxy(int x, int y); 
int displayText(char * filename); 
int typeCheck(char * filename); 
void wpmLoadingScreen(void); 
int WPM(void); 

#endif