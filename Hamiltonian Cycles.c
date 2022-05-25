#include<stdio.h>
#include<stdlib.h>

int V;
void printSolution(int path[]);
 
bool isSafe(int v, bool graph[100][100], int path[], int pos){
    if (graph [ path[pos-1] ][ v ] == 0)
       return false;
    for (int i = 0; i < pos; i++)
       if (path[i] == v)
          return false;
 
    return true;
}

bool hamCycleUtil(bool graph[100][100], int path[], int pos){
    if (pos == V){
        if ( graph[ path[pos-1] ][ path[0] ] == 1 )
            return true;
        else
           return false;
    }
    for (int v = 1; v < V; v++){
        if (isSafe(v, graph, path, pos)){
            path[pos] = v;
            if (hamCycleUtil (graph, path, pos+1) == true)
                return true;
            path[pos] = -1;
        }
    }
    return false;
}

bool hamCycle(bool graph[100][100]){
    int *path = (int*)malloc(V*sizeof(int));
    for (int i = 0; i < V; i++)
        path[i] = -1;
 
    path[0] = 0;
    if ( hamCycleUtil(graph, path, 1) == false ){
        printf("\nSolution does not exist!!");
        return false;
    }
 
    printSolution(path);
    return true;
}
 
void printSolution(int path[]){
    printf ("\n\nHamiltonian Cycle is: ");
    for (int i = 0; i < V; i++)
        printf("%d-> ", path[i]);
 
    printf("%d", path[0]);
    printf("\n");
}

int main(){
    int i,j;
    bool graph[100][100];
    printf("Enter the number of nodes: ");
    scanf("%d",&V);
    printf("Enter the Adjacency Matrix:\n");
    for(i=0;i<V;i++){
        for(j=0;j<V;j++)
            scanf("%d",&graph[i][j]);
    }
    hamCycle(graph);
}
/*
5
0 1 0 1 0
1 0 1 1 1
0 1 0 0 1
1 1 0 0 1
0 1 1 1 0

5
0 1 0 1 0
1 0 1 1 1
0 1 0 0 1
1 1 0 0 0
0 1 1 0 0

*/