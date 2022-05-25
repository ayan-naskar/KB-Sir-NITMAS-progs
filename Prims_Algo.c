#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int minkey(int *k,int *mst,int v){
    int mini=INT_MAX,min,i;
    for(i=0;i<v;i++){
        if(mst[i]==0 && k[i]<mini){
            mini=k[i];
            min=i;
        }
    }
    return min;
}

int main(){
    int mat[20][20],i,j,e,v,a,b,wt,sv;
    int p[20],k[20],mst[20],edge,minwt=0;
    printf("Enter the number of vertices and edges: ");
    scanf("%d%d",&v,&e);
    printf("Enter the edges:\n");
    for(i=0;i<v;i++) for(j=0;j<v;j++) mat[i][j]=INT_MAX;
    for(i=0;i<e;i++){
        scanf("%d%d%d",&a,&b,&wt);
        mat[a][b]=mat[b][a]=wt;
    }
    for(i=0;i<v;i++){
        k[i]=INT_MAX;mst[i]=0;
    }//mst[i]=0 means this ith edge is not in the mst, 1 means present
    k[0]=0;
    p[0]=-1;
    for(i=0;i<v-1;i++){
        edge=minkey(k,mst,v);
        mst[edge]=1;
        for(j=0;j<v;j++){
            if(mat[edge][j]!=INT_MAX && mst[j]==0 && mat[edge][j]<k[j]){
                p[j]=edge;
                k[j]=mat[edge][j];
            }
        }
    }
    printf("The minimum spanning tree is...\nEdges\tWeights\n");
    for(i=1;i<v;i++){
        //printf("%d %d\t%d\n",p[i],i,mat[i][p[i]]);
        printf("%d %d\t%d\n",p[i],i,k[i]);
        minwt+=mat[i][p[i]];
    }
    printf("The minimum spanning tree weight is: %d",minwt);
    //getch();
}
/*
5 5
0 1 5
1 2 2
2 3 3
0 3 10
3 4 12


7 9
0 5 10
5 4 25
4 6 24
4 3 22
6 3 18
6 1 14
3 2 12
1 2 16
2 0 28

*/