#include<stdio.h>
#include<stdlib.h>//update

int BinarySearch(int *arr, int SIZE, int searchELEMENT){
	int max=SIZE-1,min=0,mid;
	while(max>=min){
		mid=(max+min)/2;
		if(arr[mid]>searchELEMENT)
			max=mid-1;
		else if(arr[mid]<searchELEMENT)
			min=mid+1;
		else return mid;
	}
	return -1;
}


int main(){
	int *p,n,i,searchELEMENT,INDEX;
	printf("Enter the size: ");
	scanf("%d",&n);
	printf("Enter the elements: ");
	p=(int*)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
		scanf("%d",p+i);
	printf("Enter the element to search: ");
	scanf("%d",&searchELEMENT);
	INDEX=BinarySearch(p,n,searchELEMENT);
	if(INDEX==-1)
		puts("Element is not Found in the array.");
	else printf("Element is found in position: %d",INDEX+1);
}
