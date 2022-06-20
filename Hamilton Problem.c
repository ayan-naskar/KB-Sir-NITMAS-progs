#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define N 100

int adjm[N][N],n,path[N];

bool isValid(int ver, int posk){
	int i;
	if(adjm[path[posk-1]][ver]!=1)
		return false;
	else{
		for(i=0;i<n;i++)
			if(path[i]==ver)
				return false;
	}
	return true;
}

bool CycleFound(int k){
	int i;
	if(k==n){
		if(adjm[path[k-1]][0])
			return true;
		else return false;
		//return adjm[path[k-1]][0];
	}
	for(i=1;i<n;i++){
		if(isValid(i,k)){
			path[k]=i;
			if(CycleFound(k+1))
				return true;
			else{
				path[k]=-1;
			}
		}
	}
	return false;
}

int main(){
	int i,j,e,a,b;
	//Initialization here::
	for(i=0;i<N;i++)for(j=0;j<N;j++)adjm[i][j]=0;
	for(i=0;i<N;i++)path[i]=-1;

	//Input here::
	printf("Enter the number of Nodes: ");
	scanf("%d",&n);
	printf("Enter the number of Edges: ");
	scanf("%d",&e);
	printf("Enter the Edges:\n");
	for(i=0;i<e;i++){
		scanf("%d%d",&a,&b);
		adjm[a][b]=adjm[b][a]=1;
	}


	//Main portion of Hamiltonian Algorithm
	path[0]=0;
	if(CycleFound(1)){
		printf("\nThe Cycle is: ");
		for(i=0;i<n;i++) 
			printf("%d -> ",path[i]);
		printf("0");
	}else printf("\nNo Cycle has been Found!!");
}

/*
4
5
0 1
0 2
2 3
3 1
0 3

0----1
|\\  |
|  \\|
2----3


9
17
0 1
0 4
0 5
0 3
1 5
1 6
1 7
2 5
2 6
3 7
4 5
4 8
5 6
5 8
6 7
6 8
7 8

*/