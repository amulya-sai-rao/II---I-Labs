#include <stdio.h>
#include <stdlib.h>

int IsEmpty();
int IsFull();
void push(int);
void pop();
void traversal();

#define Max_Size 5
int stack[5],top;

int main(){
	int want_continue, choice, data;
	top = stack[0];
	printf("Enter 1.push ; 2.pop ; 3.Traversal \n");
	do{
		printf("Enter your choice: ");
		scanf("%d",&choice);
		IsEmpty();
		IsFull();
		switch(choice){
			case 1 : printf("Enter the value: ");
				  scanf("%d",&data);
				  push(data);
				  break;
				  
			case 2 : pop();
				  break;
				  
			case 3 : traversal();
				  break;
		}
		printf("If you want to contine Enter 1 : ");
		scanf("%d",&want_continue);
	}while(want_continue == 1);
	return 0;
}

int IsEmpty(){
	return top<0;
}

int IsFull(){
	return top == Max_Size -1;
}

void push(int data){
	if(IsFull() == 1){
		printf("Overflown\n");
		return;
	}
	stack[top] = data;
	top += 1;
}

void pop(){
	if (IsEmpty() == -1){
		printf("Underflown\n");
		return;
	}
	top = top -1;
}

void traversal(){
	int i;
	for(i=0;i<top;i++){
		printf("%d\t",stack[i]);
	}
}

	
	
	
				
