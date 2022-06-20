#include<stdio.h>
#include<stdlib.h>

#define N 100

int adjm[N][N],n;

void ColorTheGraph(){
	int nodeColor[N],i,j,colorUsed[N],col;
	char colList[N][20]={"Red", "Blue", "Green", "Violet","Purple", "Yellow","Black","Beige","White","Cyan","Grey","Indigo"};

	for(i=0;i<N;i++)nodeColor[i]=(colorUsed[i]=0)-1;

	nodeColor[0]=0;
	for(i=1;i<n;i++){
		for(j=0;j<n;j++){
			if(adjm[i][j] && nodeColor[j]!=-1)
				colorUsed[nodeColor[j]]=1;
		}
		col=-1;
		for(j=0;j<n;j++){
			if(colorUsed[j]==0){
				//printf("j = %d\n",j);
				col=j;
				break;
			}
		}

		nodeColor[i]=col;
		for(j=0;j<n;j++){
			if(adjm[i][j] && nodeColor[j]!=-1)
				colorUsed[nodeColor[j]]=0;
		}
	}

	printf("\n\nThe Color used in nodes are:\n");
	for(i=0;i<n;i++){
		printf("Node %d is colored ",i);
		if(nodeColor[i]>=12)
			printf("Color%d",(nodeColor[i]-12));
		else printf("%s",colList[nodeColor[i]]);
		puts("");
	}
}

int main(){
	int i,j,e,a,b;
	for(i=0;i<N;i++)for(j=0;j<N;j++)adjm[i][j]=0;

	printf("Enter the number of Nodes: ");
	scanf("%d",&n);
	printf("Enter the number of Edges: ");
	scanf("%d",&e);
	printf("Enter the Edges:\n");
	for(i=0;i<e;i++){
		scanf("%d%d",&a,&b);
		adjm[a][b]=adjm[b][a]=1;
	}
	ColorTheGraph();
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