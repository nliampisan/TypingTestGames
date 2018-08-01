#include "game.h"
Node * head = NULL; 
Node * tail = NULL; 

// parameters: Node ptr
// return: N/A
// Behavior: inserts the node to the end of the list
void insert(Node * ptr) {
	ptr->next = NULL;
	if(head == NULL) {
		head = ptr; 
		tail = ptr; 
	}
	else {
		tail->next = ptr; 
		tail = ptr; 
	}
	gotoxy(ptr->x, ptr->y); 
	printf("%c", ptr->c); 
}

// parameters: N/A
// return: N/A
// Behavior: randoms character and x value, and enqueues it to list
void addRandChar() {
	Node * ptr = (Node *) malloc(sizeof(Node)); 
	ptr->c = rand() % 128; 
	ptr->x = rand() % 128; 
	ptr->y = rand() % 128;
	insert(ptr); 
}

// parameters: character c
// return: N/A
// Behavior: inserts a specific character to list(debug use) 
void addChar(char c) {
	Node * ptr = (Node *)malloc(sizeof(Node));
	ptr->c = c;
	ptr->x = rand() % 4 + 1;
	ptr->y = 0;
	insert(ptr);
}

// parameters: character
// return: N/A
// Behavior: called when user hits a key, removes that node 
//			from the list 
void removeChar(char c) {
	
	if (head == NULL) {
		return; 
	}

	Node * prev = head;
	Node * curr = head->next;

	if (head->c == c){
		gotoxy(0, curr->y); 
		printf("|     |"); 
		curr = head->next; 
		free(head); 
		head = curr; 
	}
	while (curr != NULL) {
		if (curr->c == c) {
			gotoxy(0, curr->y);
			printf("|     |");
			prev->next = curr->next; 
			free(curr); 
			break; 
		}
		prev = curr; 
		curr = curr->next; 
	}
}

void updateList() {
	Node * curr = head; 
	while (curr != NULL) {
		gotoxy(curr->x, curr->y);
		printf(" ");
		curr->y += 1; 
		curr = curr->next; 
	}
	if (head != NULL && head->y >= HEIGHT - 1) {
		curr = head->next; 
		free(head); 
		head = curr; 
	}

	
}

void displayLetters(void) {
	Node * curr = head; 
	while (curr != NULL) {
		gotoxy(curr->x, curr->y);
		printf("%c", curr->c);
		curr = curr->next;
	}
}


// parameters: N/A
// return: N/A
// Behavior: prints all items in list (used for debugging) 
void displayList() {
	Node * temp = head; 
	while (temp != NULL) {
		printf("%c %d %d\n", temp->c, temp->x, temp->y); 
		temp = temp->next; 
	}
}

void freeList() {
	Node * temp = head; 
	while (head != NULL) {
		temp = head->next; 
		free(head); 
		head = temp; 
	}
}

void displayGameScreen() {
	int i, j; 
	for (i = 0; i < HEIGHT; i++) {
		for (j = 0; j < WIDTH; j++) {
			printf("%c", screen[i][j]); 
		}
		printf("\n"); 
	}
}

void game() {
	srand(time(NULL)); 
	int i; 
	int keycode; 
	char a; 
	clock_t start, current; 
	/*for (i = 0; i < 4; i++) {
		addRandChar(); 
	}*/

	start = clock();
	system("cls"); 
	//displayGameScreen(); 
	Sleep(2000); 
	while (1) {
		current = clock();
		if ((current - start) % 10 == 0) {
			addRandChar();
			//updateList();
			displayLetters();
		}

		/*if (_kbhit()) {
			keycode = _getch();
			removeChar(keycode);
		}*/
		if ((current - start) > 30 * CLOCKS_PER_SEC) {
			break;
		}
	}

	freeList(); 
	 
}
