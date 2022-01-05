#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node *next;
};

void Insert_beg(struct Node **,int);
void Insert_pos(struct Node *,int,int);
void Insert_end(struct Node **,int);
void Delete_beg(struct Node **);
void Delete_pos(struct Node *,int);
void Delete_end(struct Node **);
void Traversal(struct Node*);

int main(){
	int choice,want_continue,pos,data,key;
	printf("Enter 1:Insert_beg; 2:Insert_pos; 3:Insert_end; 4:Delete_beg; 5:Delete_pos; 6:Delete_end; 7:Traversal : ");
	struct Node *head = NULL,*r;
	do{
		printf("Enter your choice: ");
		scanf("%d",&choice);
		switch(choice){
			case 1 : printf("Enter value: ");
				  scanf("%d",&data);
				  Insert_beg(&head,data);
				  break;
				  
			case 2 : printf("Enter value and position: ");
				  scanf("%d%d",&data,&pos);
				  Insert_pos(head,data,pos);
				  break;
				  
			case 3 : printf("Enter value: ");
				  scanf("%d",&data);
				  Insert_end(&head,data);
				  break;
				  
			case 4 : Delete_beg(&head);
				  break;
				  
			case 5: printf("Enter pos:");
				 scanf("%d",&pos);
				 Delete_pos(head,pos);
				 break;
				 
			case 6: Delete_end(&head);
				  break;
				  
			case 7 : Traversal(head);
				  break;
				  
		}
		printf("Want to continue : Enter 1: ");
		scanf("%d",&want_continue);
	}while(want_continue == 1);
	return 0;
}

void Insert_beg(struct Node **head, int data){
	struct Node *p,*q,*temp;
	temp = (struct Node*)malloc(sizeof(struct Node));
	temp -> data = data;
	p = *head;
	if(*head == NULL){
		temp -> next = temp;
		*head = temp;
	}
	else{
		while(p -> next != *head){
			p = p -> next;
		}
		temp -> next = *head;
		p -> next = temp;
		*head = temp;
	}
}

void Insert_pos(struct Node *head, int data, int pos){
	struct Node *p,*q,*temp;
	int k = 1;
	temp = (struct Node*)malloc(sizeof(struct Node));
	temp -> data = data;
	p = head;
	while(k < pos){
		q = p;
		p = p ->next;
		k++;
	}
	q -> next = temp;
	temp -> next = p;
}

void Insert_end(struct Node **head, int data){
	struct Node *p,*q,*temp;
	temp = (struct Node*)malloc(sizeof(struct Node));
	temp -> data = data;
	p = *head;
	if(*head == NULL){
		temp -> next = temp;
		*head = temp;
	}
	else{
		while(p->next != *head){
			p = p -> next;
		}
		p -> next = temp;
		temp -> next = *head;
	}
}

void Delete_beg(struct Node **head){
	struct Node *p = *head;
	if(*head == NULL){
		printf("Empty list\n");
		return;
	}
	if((*head) -> next == *head){
		*head = NULL;
		free(p);
	}
	else{
		while(p -> next != *head){
			p = p -> next;
		}
		*head = (*head) -> next;
		p -> next = *head;
		free(p);
	}
}

void Delete_pos(struct Node *head, int pos){
	struct Node *p,*q;
	int k = 1;
	p = head;
	while(k<pos){
		q = p;
		p = p -> next;
		k++;
	}
	q -> next = p -> next;
	free(p);
}

void Delete_end(struct Node **head){
	struct Node *p = *head, *q;
	if(*head == NULL){
		printf("Empty list\n");
		return;
	}
	if((*head) -> next == *head){
		*head = NULL;
		free(p);
	}
	else{
		while(p -> next != *head){
			q = p;
			p= p->next;
		}
		q ->next = *head;
		free(p);
	}
}

void Traversal(struct Node *head){
	struct Node *p;
	p = head;
	do{
		printf("%d\t",p->data);
		p = p -> next;
	}while(p != head);
}



		
