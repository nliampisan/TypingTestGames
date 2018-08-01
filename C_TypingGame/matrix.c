#include "matrix.h"

CharNode * headIn = NULL; 
int score = 0; 

// parameters: pointer
// return: N/A
// Behavior: inserts a node to the front of the list
void insertList(CharNode * ptr) {
	if (headIn == NULL) {
		headIn = ptr; 
		ptr->next = NULL; 
	}
	else {
		ptr->next = headIn; 
		headIn = ptr; 
	}
}

// parameters: character
// return: N/A
// Behavior: removes the node containing the specified character
//			from the list. if does not exist, does nothing.
void removeNode(char c) {
	changeTextColor(GREEN); 
	CharNode * prev; 
	CharNode * curr; 
	if (headIn == NULL) {
		return; 
	}
	if (headIn->c == c) {
		gotoxy(headIn->x, headIn->y); 
		printf("%d", rand()%2); 
		score++; 

		curr = headIn->next; 
		free(headIn); 
		headIn = curr; 
		return; 
	}
	prev = headIn; 
	curr = headIn->next; 
	while (curr != NULL) {
		if (curr->c == c) {
			gotoxy(curr->x, curr->y);
			printf("%d", rand() % 2);
			score++; 

			prev->next = curr->next;
			free(curr); 
			break; 
		}
		prev = curr; 
		curr = curr->next; 
	}

}

// parameters: N/A
// return: N/A
// Behavior: allocates memory for a node and fills it with random 
//				values for c , x, and y
//				calls insertList to insert into list
void genRandChar() {
	CharNode * ptr = (CharNode *)malloc(sizeof(CharNode)); 
	ptr->c = 'a' + rand() % 26; 
	ptr->x = rand() % WIDTH; 
	ptr->y = rand() % HEIGHT;
	insertList(ptr); 
}


// parameters: N/A
// return: N/A
// Behavior: allocates memory for a node and fills it with specified 
//				value for c. x and y coords are set to 0. 
//				calls insertList to insert into list
void genChar(char c) {
	CharNode * ptr = (CharNode *)malloc(sizeof(CharNode));
	ptr->c = c;
	ptr->x = 0; 
	ptr->y = 0; 
	insertList(ptr);
}

// parameters: N/A
// return: N/A
// Behavior: prints nodes in list in one line(used for debugging) 
void printList() {
	CharNode * temp = headIn; 
	while (temp != NULL) {
		printf("%c ", temp->c); 
		temp = temp->next; 
	}
	printf("\n"); 
}

// parameters: N/A
// return: N/A
// Behavior: loops through every letter in list
//			prints out the letter at the correct x and y value
void printLetters() {
	changeTextColor(WHITE); 
	CharNode * temp = headIn; 
	while (temp != NULL) {
		gotoxy(temp->x, temp->y); 
		printf("%c", temp->c);
		temp = temp->next;
	}
}

// parameters: N/A
// return: N/A
// Behavior: loops through every node in list
//			freeing memory as it goes (used for cleanup ) 
void delList() {
	CharNode * ptr = headIn;
	while (ptr != NULL) {
		ptr = headIn->next; 
		free(headIn); 
		headIn = ptr; 
	}
}

// parameters: N/A
// return: N/A
// Behavior: prints out an randomized binary game board
void randomScreen() {
	int i, j;
	for (i = 0; i < WIDTH; i++) {
		for (j = 0; j < HEIGHT; j++) {
			printf("%d", rand()%2); 
		}
		printf("\n"); 
	}
}


// parameters: N/A
// return: N/A
// Behavior: main function for the game, keeps track of time, 
//			score, user input and update of screen
void matrix(void) {
	srand(time(NULL));
	int keycode; 

	randomScreen(); 
	Sleep(1000); 
	clock_t start, current;
	start = clock();
	genChar('a'); 
	while (1) {
		current = clock(); 

		if ((current - start) % 2000 == 0) {
			genRandChar();
			printLetters();
		}

		if (_kbhit()) {
			keycode = _getch();
			removeNode(keycode);
		}

		if ((current - start) > 30 * CLOCKS_PER_SEC) {
			break; 
		}
	}
	system("cls"); 

	changeTextColor(GREEN);
	printf("Congratulations.\n");
	printf("Your score was %d.\n", score);
	printf("Press enter key to return to main menu.\n");

	while (1) {
		if (_kbhit()) {
			keycode = _getch();
			if (keycode == ENTER)
				break;
		}
	}

	system("cls"); 
	delList(headIn); 
	
}