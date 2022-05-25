#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define mat(a,b) *(mat+a*v+b)

int calCost(int *graf,int e){
	int cost=0;
	for(;e>0;e--)
		cost+=graf[(e-1)*3+2];
	return cost;
}

void swap(int *a, int *b){
	int t;
	t=*a;
	*a=*b;
	*b=t;
}

void sort(int *el,int n){
	int i,j,k,*p;
	//puts("Sorting part!!");
	//printf("n=%d",n);
	for(i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
			if(el[j*3+2]>el[(j+1)*3+2]){
				//printf("%d %d\n",el[j*3+2],el[(j+1)*3+2]);//if this line is commented, the program stops in this line.
				//puts("sooo");
				for(k=0;k<3;k++)
					swap(&el[j*3+k],&el[(j+1)*3+k]);
				//puts("soo2");
			}
		}
	}
	//puts("\nEnd of Sorting!!");
}

void printEdges(int *el,int n){
	int i,j;
	for(i=0;i<n;i++){
		printf("%d-%d\t%d\n",el[i*3],el[i*3+1],el[i*3+2]);
	}
}

int findset(int *visited,int v,int a){//returns the tree root of the vertex sent here
	return visited[a];
}

void unionset(int *visited, int v, int a, int b){
	int x,i,q,r;
	q=visited[a];
	r=visited[b];
	if(visited[a]<visited[b])
		x=visited[a];
	else x=visited[b];
	for(i=0;i<v;i++){
		if(visited[i]==q || visited[i]==r)
			visited[i]=x;
	}
}

int* FindMST(int *mat, int v,int *edgeList, int eLn){
	int *visited,*mst,i,j,mstx=0;
	//mstx is just a counter as i from 0 to v-1
	visited=(int*)calloc(v,sizeof(int));
	for(i=0;i<v;i++)visited[i]=i;
	mst=(int*)calloc((v-1)*3,sizeof(int));
	sort(edgeList,eLn);
	printf("\nAfter sorting the list is:\n");
	printEdges(edgeList,eLn);

	for(i=0;i<eLn;i++){
		/*printf("\nThe visited array is: ");
		for(j=0;j<v;j++){
			printf("%d ",visited[j]);
		}
		puts("");*/
		if(findset(visited,v,edgeList[i*3])!=findset(visited,v,edgeList[i*3+1])){//(visited[edgeList[i*3]]==0 || visited[edgeList[i*3+1]]==0){
			for(j=0;j<3;j++)
				mst[mstx*3+j]=edgeList[i*3+j];
			mstx++;
			unionset(visited,v,edgeList[i*3],edgeList[i*3+1]);
		}
	}
	return mst;
}

int main(){
	int *mat,v,e,*mst,*edgeList,eLn=0;
	//eLn is the number of valid edges
	//mat matrix is basically unused in this program.
	int i,a,b,wt,cost;
	printf("Enter the number of vertices: ");
	scanf("%d",&v);
	printf("Enter the number of Edges: ");
	scanf("%d",&e);
	mat=(int*)calloc(v*v,sizeof(int));
	for(i=0;i<v*v;i++) mat[i]=INT_MAX;
		puts("Enter the edges and weights:");
	edgeList=(int*)calloc(e*3,sizeof(int));
	for(i=0;i<e;i++){
		scanf("%d%d%d",&a,&b,&wt);
		if(mat(a,b)>wt && a!=b){
			mat(a,b)=wt;
			edgeList[eLn*3]=a;
			edgeList[eLn*3+1]=b;
			edgeList[eLn*3+2]=wt;
			eLn++;
		}
	}
	printf("Input Graf edges with premilinary modification:\n");
	printEdges(edgeList,eLn);
	mst=FindMST(mat,v,edgeList,eLn);
	printf("\nThe MST is:\n");
	printEdges(mst,v-1);
	cost=calCost(mst,v-1);
	printf("\nThe total cost of M.S.T is: %d",cost);
}

/*
7 9
0 1 28
1 2 16
2 3 12
3 4 22
4 5 25
0 5 10
4 6 24
3 6 18
1 6 14

99

5 5
0 1 10
0 2 5
1 3 14
3 4 12
2 4 25

41
*/