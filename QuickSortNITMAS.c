#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (int *arr, int low, int high)
{
    int pivot = arr[high]; 
    int i = (low - 1); 
 
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++; 
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quicksort(int *p,int l, int h)
{
	int piv;
	if(l<=h)
	{
		piv=partition(p,l,h);
		quicksort(p,l,piv-1);
		quicksort(p,piv+1,h);
	}
}

int main(){
	int *p,n,i;
	printf("Enter the size: ");
	scanf("%d",&n);
	printf("Enter the elements: ");
	p=(int*)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
		scanf("%d",p+i);
	quicksort(p,0,n-1);
	printf("The sorted elements are: ");
	for(i=0;i<n;i++)
		printf("%d ",p[i]);
	return 0;
}
/*
Best Case: T(n)= 2T(n/2)+ ?(n). Time complexity: O(n*logn)
Best case occurs when a middle element is chosen as a pivot. It means a number of elements smaller than pivot are equal to the number of elements greater than the pivot.
Average Case: T(n)= T(n/3)+T(2n/3)+ ?(n). Time complexity: O(n*logn)
Average case can be considered when partition puts O(n/3) elements in one set and O(2n/13) elements in other set.
Worst Case: T(n)= T(n-1)+ ?(n). Time complexity: O(n*n)
*/