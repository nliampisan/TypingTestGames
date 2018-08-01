#include "main.h"

int choice = 0; 

// parameters: color 
// return: N/A 
// Behavior: changes the text color that is printed to console
void changeTextColor(int color) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
}

// parameters: x, and y coordinates
// return: N/A 
// Behavior: changes console cursor to specified x and y coord
void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE),
		coord
	);
}


// parameters: N/A
// return: N/A 
// other: prints out a menu according to the current choice
void printMenu() {
	printf("Welcome to the typing game.\n"); 
	if (choice == 0) {
		printf("> Check your typing speed(WPM)\n"); 
	}
	else {
		printf("  Check your typing speed(WPM)\n");
	}
	if (choice == 1) {
		printf("> Type Type Game\n");
	}
	else {
		printf("  Type Type Game\n");
	}
	if (choice == 2) {
		printf("> Quit\n");
	}
	else {
		printf("  Quit\n");
	}
}


// parameters: keycode
// return: N/A 
// other: changes the global variable choice according to KEY
//			UP key increments choice by 1, DOWN key decrement choice by 1
void updateChoice(int keycode) {
	if (keycode == UP && choice > 0) {
		choice -= 1; 
	}
	else if(keycode == DOWN && choice < 2) {
		choice += 1; 
	}
}


int main() {
	int keycode; 
	printMenu();
	while (1) {
		if (_kbhit())
		{
			system("cls");
			// gets the character from stdin
			keycode = _getch();
			// if press enter goes into another game mode
			if (keycode == ENTER) {
				switch (choice) {
					case 0: 
						printf("Test your Typing Speed.\n"); 
						WPM(); 
						break; 
					case 1: 
						matrix(); 
						break; 
					case 2: 
						exit(1); 
						break; 
					default: 
						break; 
				}
			}
			updateChoice(keycode); 
			printMenu(); 
		}
	}


	system("pause"); 
	return 1; 
}