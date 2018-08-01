#include "wordPerMin.h"

//saveAttributes
void saveConsoleSettings() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
	WORD saved_attributes;

	/* Save current attributes */
	GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
	saved_attributes = consoleInfo.wAttributes;

	/* Restore original attributes */
	SetConsoleTextAttribute(hConsole, saved_attributes);
	printf("Back to normal");
}


// parameters: filename
// return: 0 if file exists, ERROR(-1) if file does not exists
// Behavior: prints out the entire text file, starting a new line 
//			every time period is found
int displayText(char * filename) {
	char txtChar;
	int count = 0; 
	FILE * inFile = fopen(filename, "r"); 
	if (inFile == NULL) {
		fclose(inFile);
		return FILE_ERROR; 
	}
	while (fscanf(inFile, "%c", &txtChar) != EOF) {
		printf("%c", txtChar);
		if ((txtChar == '.' || txtChar == ',') && count >= LINE_SIZE) {
			printf("\n"); 
			count = 0; 
		}
		count++; 
	}
	fclose(inFile); 
	return 0; 
}

// parameters: filename
// return: word count
// Behavior: checks if user is typing the correct character, and 
//			calculates word count at the same time
int typeCheck(char * filename) {
	
	char txtChar, userChar;
	int charCount = 0;
	int wordCount = 0; 
	int keycode; 
	int sameKey = 0; 
	int wordFound = 0; 

	clock_t start, current; 

	FILE *inFile = fopen(filename, "r"); 
	//go to top left of console
	gotoxy(0, 0);
	// set text color to white
	changeTextColor(WHITE); 

	start = clock(); 
	fscanf(inFile, "%c", &txtChar);

	while (1) {
		//if correct key is typed, get new key
		if (sameKey == 1) {
			if (fscanf(inFile, "%c", &txtChar) == EOF) {
				break; 
			}
			if (txtChar == '\n') {
				printf("\n"); 
				wordCount++; 
				fscanf(inFile, "%c", &txtChar); 
			}
			sameKey = 0; 
		}

		if (_kbhit()) {
			keycode = _getch();
			if (keycode == txtChar) {

				// two if statements used to count words
				if (txtChar != ' ' && wordFound == 0) {
					wordFound = 1; 
				}
				if (txtChar == ' ' && wordFound == 1) {
					wordCount++; 
					wordFound = 0; 
				}

				//update if correct key is typed
				printf("%c", txtChar); 
				sameKey = 1; 
				charCount++;
			}
		}

		//check if we need to go to new line
		if ((txtChar == '.' || txtChar == ',') 
			&& charCount >= LINE_SIZE && sameKey == 1)
		{
			printf("\n");
			charCount = 0;
		}

		// check if time has expired
		current = clock();
		if ((current - start) > 60 * CLOCKS_PER_SEC) {
			break;
		}
	}
	

	//restore color to green
	changeTextColor(GREEN); 
	system("cls"); 
	fclose(inFile);
	return wordCount; 
}


// parameters: N/A
// return: N/A 
// Behavior: prints out an introduction the game
void wpmLoadingScreen(void) {
	printf("How many words can you type in 60 seconds.\n");
	Sleep(3000);
	printf("Are you ready? ");
	Sleep(1000); 
	int i;
	for (i = 3; i >= 1; i--) {
		printf("%d....", i);
		Sleep(1000);
	}

	system("cls");
}

// parameters: N/A
// return: N/A 
// Behavior: randoms a file and lets the user type until one minute
//			is reached, then calculates Words per minute, and prints it out
int WPM(void) {
	srand( time(NULL)); 
	int wordCount = 0; 
	int num; 
	num = rand() % 3; 

	wpmLoadingScreen(); 

	if (displayText(files[num]) == FILE_ERROR) {
		printf("ERROR: Text file could not be opened.\n"); 
		Sleep(3000); 
		system("cls"); 
		return FILE_ERROR; 
	}

	wordCount = typeCheck(files[num]);

	int keycode; 
	printf("Congratulations.\n");
	printf("You typed %d words in one minute.\n", wordCount);
	printf("Press enter key to return to main menu.\n");

	while (1) {
		if (_kbhit()) {
			keycode = _getch(); 
			if (keycode == ENTER)
				break; 
		}
	}

	system("cls"); 
	
	return 0; 
}