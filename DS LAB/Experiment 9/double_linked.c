#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node *next,*prev;
};

void Insert(struct Node**, int , int);
void Delete(struct Node**, int);
void Traversal(struct Node*);
struct Node *Search(struct Node* ,int);


int main(){
	int choice,want_continue,pos,data,key;
	printf("Enter your choice: 1-Insert; 2-Delete; 3-Traversal; 4-Search: ");
	struct Node* head = NULL, *r;
	do{
		printf("Enter your choice: ");
		scanf("%d",&choice);
		switch(choice){
			case 1 : printf("Enter value and pos: ");
				 scanf("%d%d",&data,&pos);
				 Insert(&head,data,pos);
				 break;
				 
			case 2 : printf("Enter pos: ");
				  scanf("%d",&pos);
				  Delete(&head,pos);
				  break;
				  
			case 3 : Traversal(head);
				  break;
				  
			case 4 : printf("Enter Key: ");
				 scanf("%d",&key);
				 r = Search(head,key);
				 if(r == NULL){
				 	printf("Not Found\n");
				 }
				 else{
				 	printf("Sucessfull\n");
				 }
				 break;
		}
		printf("Want to continue -- Enter '1':");
		scanf("%d",&want_continue);
	}while(want_continue == 1);
	
	return 0;
}


void Insert(struct Node **head,int data,int pos){
	struct Node *temp,*p, *q;
	int k = 1;
	temp = (struct Node*)malloc(sizeof(struct Node));
	temp -> data = data;
	p = *head;
	if(pos == 1){
		temp -> next = *head;
		temp -> prev = NULL;
		if(*head != NULL){
			(*head) -> prev = temp;
		}
		*head = temp;
	}
	else{
		while((k<pos-1) && (p->next!= NULL)){
			p = p -> next;
			k++;
		}
		if(k != pos-1){
			printf("Position doesn't exist\n");
			return;
		}
		temp -> next = p->next;
		temp -> prev = p;
		p -> next = temp;
		if(p->next){
			p-> next->prev = temp;
			
		}
	}
}


void Delete(struct Node **head,int pos){
	struct Node *p,*q;
	int k=1;
	p = *head;
	if(pos == 1){
		*head = (*head) -> next;
		if(*head){
			(*head) -> prev = NULL;
		}
		free(p);
	}
	else{
		while((k<pos) && (p->next!= NULL)){
			p = p -> next;
			k++;
		}
		if(k!= pos){
			printf("Position doesn't exist\n");
			return;
		}
		q = p -> prev;
		q -> next = p -> next;
		if(p -> next != NULL){
			p -> next ->prev = q;
			free(p);
		}
		
	}
}

void Traversal(struct Node *head){
	struct Node *p;
	p = head;
	while(p != NULL){
		printf("%d\t", p-> data);
		p = p -> next;
	}
}

struct Node *Search(struct Node *head, int key){
	struct Node *p;
	p = head;
	while(p != NULL){
		if(p -> data == key){
			return p;
		}
		p = p -> next;
	}
	return NULL;
}


	
			
