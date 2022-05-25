#include <stdio.h>
#include <stdlib.h>

/*int partition(int *p,int l,int h)
{
	int piv=l++,temp;
	while(l<=h)
		if(*(p+l)>*(p+piv) && *(p+h)<*(p+piv))
		{
			temp=*(p+l);
			*(p+l)=*(p+h);
			*(p+h)=temp;
			l++;
			h--;
		}
		else if(*(p+l)<*(p+piv))
			l++;
		else if(*(p+l)>*(p+piv) && *(p+h)>*(p+piv))
			h--;
	l--;
	temp=*(p+l);
	*(p+l)=*(p+piv);
	*(p+piv)=temp;
	return l;
}*/

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (int *arr, int low, int high)
{
    int pivot = arr[high]; // pivot
    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far
 
    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (arr[j] < pivot)
        {
            i++; // increment index of smaller element
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