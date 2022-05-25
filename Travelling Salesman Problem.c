#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

/*int com;
void tsp(int n, int **mat, int src){
	int *g,comb=1<<n,i,j,a,b,iter,nxt,min;
	g=(int*)calloc(comb,sizeof(int));
	for(i=0;i<n;i++){
		if(i==src) continue;

	}
	for(iter=1;iter<(n-1);iter++){
		for(i=0;i<n;i++){
			if(i!=src){
				com=0;
				nxt=next_in(iter,i,src);//iter=number of combinations i am looking for, i=which is current and i am ignoring 'i'
										//ignore src too!!
				min=INT_MAX;
				for(j=0;j<n;j++){
					if((nxt>>i)&1){
						a=mat[i][j]+g[nxt];
						if(min>a)
							min=a;
					}
				}
				g[nxt&(1<<i)]=min;
			}
		}
	}
}*/

struct g{
	int inum,c,*p;
};

void initialize(struct g *obj,int size,int * mat,int src){
	int i=0,s,n=size,pos,j;
	for(;i<n;i++){
		obj[i].inum=i;
		s=i;
		obj[i].c=j=0;
		while(s>0){
			if(s&1){
				obj[i].c++
				pos=j;
			}
			j++;
			s=s>>1;
		}
		obj[i].p=(int*)malloc(obj[i].c*sizeof(int));

		if(obj[i].c==1 && pos!=src){
			obj[i].p[0]=mat[pos][src];
		}
	}
}

void tsp(int n, int *mat, int src){
	struct g *obj=(struct g*)malloc((1<<(n-1))*sizeof(struct g));
	initialize(obj,1<<(n-1),mat,src);
	int i,j,s,a,b;

	for(s=1;s<n;s++){
		
	}
}

int main(){
	int n,**mat,i,j,src,e,a,b;
	printf("Enter the number of Nodes: ");
	scanf("%d",&n);
	mat=(int**)malloc(n*sizeof(int*));
	for(i=0;i<n;i++)
		mat[i]=(int*)calloc(n,sizeof(int));
	printf("Enter the edges: ");
	scanf("%d",&e);
	printf("Enter the edges and weights:\n");
	for(i=0;i<e;i++){
		scanf("%d%d%d",&a,&b,&j);
		mat[a][b]=j;
	}
	printf("Enter the Source Vertex: ");
	scanf("%d",&src);
	/*for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%d ",mat[i][j]);
		}
		puts("");
	}*/
	tsp(n,mat,src);
}
/*
5
20
0 1 5
0 2 3
0 3 2
0 4 4

1 0 3
1 2 3 
1 3 1
1 4 5

2 0 4
2 1 3
2 3 2
2 4 1

3 0 6
3 1 3
3 2 2
3 4 5

4 0 4
4 1 3
4 2 3
4 3 2

0

*/