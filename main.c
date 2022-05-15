#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#define size 2

typedef struct lifo {
	int data[size];
	int start;
	int end;
} lifo;

lifo stack;
int option;

void show_stack();
void push(int add);
void pop(int remove);
void menu();

int main(int argc, char *argv[]) {
	stack.start = 0;
	stack.end = 0;
	
	option = 1;
	
	int value;
	
	while(option != 0){
		system("cls");
		show_stack();
		menu();
		
		scanf("%d", &option);
		
		switch(option){
			case 1:
				printf("Enter the value to be stacked: ");
				scanf("%d", &value);
				push(value);
			break;
			
			case 2:
				value = 0;
				pop(value);
			break;
			
			default:
				menu();
		}
		system("pause");
	}
	
	return 0;
}

void menu() {
	printf("\n====== MENU ======\n");
	printf("     1- Push\n");
	printf("     2- Pop\n");
	printf("     0- Exit\n\n");
	
	printf("Choose 1 to stack, 2 to unstack and 0 to exit: ");
}

void show_stack() {
	printf("== The stack content ==\n\n");
	int i;
	printf("     [ ");
	for(i=0; i<size; i++){
		printf("%d ", stack.data[i]);
	}
	printf("]\n\n");
}

void push(int add) {
	if(stack.end != size){
		stack.data[stack.end] = add;
		stack.end++;
	} else {
		printf("  \nThe stack is full.\n\n");
	}
}

void pop(int remove) {
	if(stack.start != stack.end){
		stack.data[stack.end-1] = remove;
		stack.end--;
	} else {
		printf("  \nThe stack is empty.\n\n");
	}
}

