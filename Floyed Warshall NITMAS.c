#include<stdio.h>
#include<stdlib.h>

#define INT_MAX 10e7

void FloyedWarshall(int *adjmat, int v, int **A, int **S){
	int i,j,k,dis;
	A=(int**)calloc((v+1),sizeof(int*));
	S=(int**)calloc((v+1),sizeof(int*));
	for(i=0;i<=v;i++){
		A[i]=(int*)calloc(v*v,sizeof(int));
		S[i]=(int*)calloc(v*v,sizeof(int));
	}
	for(i=0;i<v*v;i++)
		*(A[0]+i)=adjmat[i];
	for(i=0;i<v;i++)
		for(j=0;j<v;j++)
			*(S[0]+i*v+j)=i;

	for(i=1;i<=v;i++){//step number
		for(j=0;j<v;j++){
			for(k=0;k<v;k++){
				dis=*(A[i-1]+v*j+(i-1))+*(A[i-1]+v*(i-1)+k);
				if(dis<*(A[i-1]+v*j+k)){
					*(A[i]+v*j+k)=dis;
					*(S[i]+v*j+k)=i-1;
				}else{
					*(A[i]+v*j+k)=*(A[i-1]+v*j+k);
					*(S[i]+v*j+k)=*(S[i-1]+v*j+k);
				}
			}
		}
	}
	//printing of the final matrices
	printf("The Final Distance Matrix is:\n\t");
	for(i=0;i<v;i++)
		printf("(%d)\t",i+1);
	//puts("");
	for(i=0;i<v;i++){
		printf("\n(%d)\t",i+1);
		for(j=0;j<v;j++){
			if(*(*(A+v)+v*i+j)==INT_MAX)printf("INF\t");
			else printf("%d\t",*(A[v]+v*i+j));
		}
	}

	printf("\nThe Final Source Matrix is:\n\t");
	for(i=0;i<v;i++)
		printf("(%d)\t",i+1);
	for(i=0;i<v;i++){
		printf("\n(%d)\t",i+1);
		for(j=0;j<v;j++){
			if(i==j)
				printf("-\t");
			else printf("%d\t",*(S[v]+v*i+j)+1);
		}
	}
}

int main(){
	int v,e,*adjmat,i,a,b,d;
	int **A,**S;
	printf("Enter the number of vertices and edges:");
	scanf("%d%d",&v,&e);
	adjmat=(int*)malloc(v*v*sizeof(int));
	for(i=0;i<v*v;i++) adjmat[i]=INT_MAX;//initalized with INF
	for(i=0;i<v;i++) adjmat[i*v+i]=0;//diagonal should be 0
	printf("Enter the Edges and distance:\n");
	while(e--){
		scanf("%d%d%d",&a,&b,&d);
		a--;
		b--;
		adjmat[a*v+b]=d;
		//adjmat[b*v+a]=d;
	}
	
	FloyedWarshall(adjmat,v,A,S);
}
//TIME COMPLEXITY=O(n^3)
//This is the program with nodes naming starting from 1, for nodes strting from 0 it is done in dp folder
/*
3 1
1 2 8

*/