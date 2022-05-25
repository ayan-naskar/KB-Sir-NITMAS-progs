#include<stdio.h>
#include<stdlib.h>

int ar[20][20];
int q[20],front,rear;

void enQ(int num){
	if(front==-1 && rear==-1)
		front=rear=0;
	else rear++;
	q[rear]=num;
}

int deQ(){
	int index;
	if(front==rear && rear==-1)
		return -1;
	else{
		index=front;
		front++;
		if(rear<front)
			rear=front=-1;
		return q[index];
	}
}

void traverse(int n,int src){
	int del,i;
	int *p=(int*)calloc(n,sizeof(p));
	enQ(src); p[src]=1;
	for(;front!=-1;){
		del=deQ();
		printf("%d ",del);
		for(i=0;i<n;i++){
			if(ar[del][i]==1 && p[i]==0){
				enQ(i);
				p[i]=1;
			}
		}
	}
}

int main(){
	int i=20,j,n,t,a,b,src;
	front=rear=-1;
	while(i--) for(j=0;j<20;j++) ar[i][j]=0;
	printf("Enter number of Vertices: ");
	scanf("%d",&n);
	printf("Enter number of Edges: ");
	scanf("%d",&t);
	printf("Enter the Edges:\n");
	while(t--){
		scanf("%d",&a);scanf("%d",&b);
		ar[a][b]=ar[b][a]=1;
	}
	printf("Enter the Source Vertex: ");
	scanf("%d",&src);
	printf("The B.F.S. traversal is: ");
	traverse(n,src);
	return 0;
}
/*
6
5
0 1
1 2
0 2
3 4
4 4

*/