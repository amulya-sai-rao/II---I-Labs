#include <stdio.h>
#include <stdlib.h>


struct Node {
	int data;
	struct Node *next;
};

void Insert(struct Node ** , int , int );
void Delete(struct Node ** , int );
void Traversal(struct Node *);
struct Node *Search(struct Node * ,int );
void Middle(struct Node **);

int main(){
	int choice,want_continue,pos,data,key;
	struct Node *head = NULL, *r;
	printf("Choose from 1:Insertion ; 2:Deletion ; 3:Traversal ; 4:Searching ; 5:Middle_Element\n");
	do{
		printf("Enter your choice:");
		scanf("%d",&choice);
		switch(choice){
			case 1 : printf("Enter value and position: ");
				 scanf("%d%d", &data, &pos);
				 Insert(&head,data,pos);
				 break;
				 
			case 2 : printf("Enter position to delete: ");
				 scanf("%d",&pos);
				 Delete(&head,pos);
				 break;
			
			case 3 : Traversal(head);
				  break;
				  
			case 4 : printf("Enter the key: ");
				  scanf("%d", &key);
				  r = Search(head,key);
				  if(r == NULL){
				  	printf("Not sucessful\n");
				  }
				  else{
				  	printf("Sucessful\n");
				  }
				  break;
			 
			case 5 :  Middle(&head);
		}
		printf("Want to continue, Enter ! : ");
		scanf("%d", &want_continue);
	}while(want_continue == 1);
	return 0;
}

void Insert(struct Node **head, int data, int pos){
	struct Node *p,*q,*temp;
	int k = 1;
	temp = (struct Node *)malloc(sizeof(struct Node));
	temp->data = data;
	p = *head;
	if(pos == 1){
		temp -> next = *head;
		*head = temp;
	}
	else{
		while((p != NULL) && (k < pos)){
			q = p;
			p = p -> next;
			k++;
		}
		q -> next = temp;
		temp -> next = p;
	}
}


void Delete(struct Node **head, int pos){
	struct Node *p, *q;
	int k = 1;
	p = *head;
	if(pos == 1){
		*head = (*head) -> next;
		free(p);
	}
	else{
		while((p != NULL) && (k < pos)){
			q = p;
			p = p -> next;
			k++;
		}
		if(p == NULL){
			printf("Node doesnt exist\n");
		}
		else{
			q->next = p->next;
			free(p);
		}
	}
}

void Traversal(struct Node *head){
	struct Node *p;
	p = head;
	while(p != NULL){
		printf("%d\t", p -> data);
		p = p -> next;
	}
}


struct Node *Search(struct Node *head ,int key){
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

void Middle(struct Node **head){
	struct Node *p, *q;
	p = *head;
	q = *head;
	while((p != NULL) && ((p -> next) != NULL)){
		p = p -> next ->next;
		q = q -> next;
	}
	printf(" Middle element is : %d\n",q ->data);
}
	
		


			



