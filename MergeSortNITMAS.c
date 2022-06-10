#include <stdio.h>
#include <stdlib.h>

void merge(int* ar, int l, int m, int u)
{
	int i,j,k=l,*p,*q;
	p=(int*)malloc(sizeof(int)*(m-l+1));
	q=(int*)malloc(sizeof(int)*(u-m));
	for(i=0;i<(m-l+1);i++)
		p[i]=ar[i+l];
	for(j=0;j<(u-m);j++)
		q[j]=ar[j+m+1];
	i=j=0;
	while(i<=(m-l)&&j<(u-m)){
		if(p[i]<q[j]){
			ar[k]=p[i];
			i++;
		}
		else{
			ar[k]=q[j];
			j++;
		}
		k++;
	}
	while(i<=(m-l)){
		ar[k]=p[i];
		k++;
		i++;
	} 
	while(j<(u-m)) {
		ar[k]=q[j];
		k++;
		j++;
	}
}
void mergeSort(int *ar,int l,int u)
{
	if(l<u){
		int m=(u+l)/2;
		mergeSort(ar,l,m);
		mergeSort(ar,m+1,u);
		merge(ar,l,m,u);
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
	mergeSort(p,0,n-1);
	printf("The sorted elements are: ");
	for(i=0;i<n;i++)
		printf("%d ",p[i]);
	return 0;
}
//T (n) = 2T (n/2) + θ (n)