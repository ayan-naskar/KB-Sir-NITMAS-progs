#include<stdlib.h>
#include<stdio.h>

int findExtreme(int *p, int bl, int low, int high){
	int av=(low+high)/2,a,b;
	//printf("av=%d low=%d High=%d\n",av,low,high);
	if(low>=high)
		return p[low];
	a=findExtreme(p,bl,low,av);
	//puts("a");
	b=findExtreme(p,bl,av+1,high);
	//printf("a=%d b=%d\n",a,b);
	return ((a>b)==bl)?a:b;
}

int main(){
	int *p,n,i,num;
	printf("Enter the size: ");
	scanf("%d",&n);
	printf("Enter the elements: ");
	p=(int*)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
		scanf("%d",p+i);
	fflush(stdin);
	printf("Enter 1 to find the maximum number in the array or 0 to find minimum: ");
	printf("The required number is: %d",findExtreme(p,getchar()-'0',0,n-1));
	return 0;
}
/*
3
1 2 3
1

*/