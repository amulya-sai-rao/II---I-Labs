#include <stdio.h>

int rlinear(int a[], int n, int key);

int main(){
	int n,i,key,pos;
	printf("Enter the size of array: ");
	scanf("%d",&n);
	int a[n];
	printf("Enter elements of array: ");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	printf("Enter the value of key: ");
	scanf("%d",&key);
	pos = rlinear(a,n,key);
	if(pos>=0){
		printf("Element found at position %d",pos);
	}
	else{
		printf("Element not found");
	}
	return 0;
}


int rlinear(int a[], int n, int key){
	if(n >=0){
		if(a[n-1] == key){
			return n;
		}
		else{
			return rlinear(a,n-1,key);
		}
	}
	return -1;
	
}

