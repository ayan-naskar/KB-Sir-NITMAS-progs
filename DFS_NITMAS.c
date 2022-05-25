#include<stdio.h>
#include<stdlib.h>

int ar[20][20];
int q[20];//not queue but stack
int top=-1;

int pop(){
	if(top==-1) return -1;
	else{
		top--;
		return q[top+1];
	}
}

void push(int num){
	top++;
	q[top]=num;
}

void traverse(int n,int src){
	int del,i;
	int *p=(int*)calloc(n,sizeof(p));
	push(src); p[src]=1;
	for(;top!=-1;){
		del=pop();
		printf("%d ",del);
		for(i=0;i<n;i++){
			if(ar[del][i]==1 && p[i]==0){
				push(i);
				p[i]=1;
			}
		}
	}
}

int main(){
	int i=20,j,n,t,a,b,src;
	while(i--) for(j=0;j<20;j++) ar[i][j]=0;
	printf("Enter number of Vertices: ");
	scanf("%d",&n);
	printf("Enter number of Edges: ");
	scanf("%d",&t);
	printf("Enter the Edges:\n");
	while(t--){
		scanf("%d%d",&a,&b);
		ar[a][b]=ar[b][a]=1;
	}
	printf("Enter the Source Vertex: ");
	scanf("%d",&src);
	printf("The D.F.S. traversal is: ");
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