#include <stdio.h>

int linear(int a[],int n,int key);

int main(){
	int n,i,pos,key;
	printf("Enter the size of array: ");
	scanf("%d",&n);
	int a[n];
	printf("Enter the elements of array: ");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	printf("Enter the value of key: ");
	scanf("%d",&key);
	pos = linear(a,n,key);
	if(pos>0){
		printf("Element found at position %d",pos);
	}
	else{
		printf("Element not found");
	}
	return 0;
}

int linear(int a[],int n, int key){
	int i;
	for(i=0;i<n;i++){
		if(key == a[i]){
			return i+1;
		}
	}
	return -1;
}
	
	
