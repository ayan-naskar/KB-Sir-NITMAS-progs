#include<stdio.h>
#include<stdbool.h>

int NODE;
int graph[100][100];
int color[100];

void graphColoring() {
   color[0] = 0;    //Assign first color for the first node
   bool colorUsed[100];    //Used to check whether color is used or not

   for(int i = 1; i<NODE; i++)
      color[i] = -1;    //initialize all other vertices are unassigned

   for(int i = 0; i<NODE; i++)
      colorUsed[i] = false;    //initially any colors are not chosen

   for(int u = 1; u<NODE; u++) {    //for all other NODE - 1 vertices
      for(int v = 0; v<NODE; v++) {
         if(graph[u][v]){
            if(color[v] != -1)    //when one color is assigned, make it unavailable
               colorUsed[color[v]] = true;
         }
      }

      int col;
      for(col = 0; col<NODE; col++)
         if(!colorUsed[col])    //find a color which is not assigned
            break;

      color[u] = col;    //assign found color in the list

      for(int v = 0; v<NODE; v++) {    //for next iteration make color availability to false
         if(graph[u][v]) {
            if(color[v] != -1)
              colorUsed[color[v]] = false;
         }
      }  
   }
}

void printGraphColors(){
   char defaultColorList[20][20]={"Red","Blue","Green","Violet","Indigo","Yellow","Orange"};
   puts("\nThe Result is:\n");
   for(int u = 0; u<NODE; u++)     
      printf("Node %d is %s\n",u,defaultColorList[color[u]]);
}

/*main() {
   int i,j;
   printf("Enter the number of nodes: ");
   scanf("%d",&NODE);
   printf("Enter the Adjacency Matrix:\n");
   for(i=0;i<NODE;i++){
      for(j=0;j<NODE;j++)
         scanf("%d",&graph[i][j]);
   }
   graphColoring();
   printGraphColors();
}*/
int main(){
   int i,j,e,a,b,N=100;
   for(i=0;i<N;i++)for(j=0;j<N;j++)graph[i][j]=0;

   printf("Enter the number of Nodes: ");
   scanf("%d",&NODE);
   printf("Enter the number of Edges: ");
   scanf("%d",&e);
   printf("Enter the Edges:\n");
   for(i=0;i<e;i++){
      scanf("%d%d",&a,&b);
      graph[a][b]=graph[b][a]=1;
   }
   graphColoring();
   printGraphColors();
}

/*

6
0 1 1 1 0 0
1 0 0 1 1 0
1 0 0 1 0 1
1 1 1 0 1 1
0 1 0 1 0 1
0 0 1 1 1 0

5
0 1 0 1 1
1 0 1 1 0
0 1 0 1 1
1 1 1 0 1
1 0 1 1 0

*/