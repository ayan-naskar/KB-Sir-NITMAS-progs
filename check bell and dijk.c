#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<time.h>
#include<conio.h>

#define INF 10e7

/*void print(int *a,int v, int iter){//this is for debugging
	int i;
	printf("\nFor Relaxation number: %d\n",iter);
	for(i=0;i<v;i++)
		if(a[i]!=INF)
			printf("%d\t",a[i]);
		else printf("INF\t");
}*/

/*void printFinalDist(int *dp,int v,int iter){
	int i;
	printf("\n\n\nThe distance to all vertices from Source is:\n");
	for(i=0;i<v;i++) printf("(%d)\t",i);
		puts("");
	for(i=0;i<v;i++){
		if(dp[(v-1)*v+i]!=INF)
			printf("%d\t",dp[(iter-1)*v+i]);
		else printf("INF\t");
	}
}*/

void BellmanFord(int *edgeList, int e, int v, int src,int *dp){
	//int *dp=(int*)calloc(v*(v-1),sizeof(int));
	int *cos,i,j,fl,u,v1,wt;
	for(j=0;j<v;j++)
		dp[j]=INF;
	dp[src]=0;
	for(i=1;i<v;i++){
		cos=(int*)calloc(v,sizeof(int));
		for(j=0;j<v;j++)
			cos[j]=dp[v*(i-1)+j];
		//print(cos,v,i);
		fl=0;
		for(j=0;j<e;j++){
			u=edgeList[3*j];
			v1=edgeList[3*j+1];
			wt=edgeList[3*j+2];
			if((cos[u]!=INF)&&(cos[u]+wt<cos[v1])){
				cos[v1]=cos[u]+wt;
				//printf("\ncos=%d\n",cos[v1]);
				//puts("here");
				//fl=1;
			}
		}
		for(j=0;j<v;j++)
			dp[v*i+j]=cos[j];
		free(cos);
	}
	//printFinalDist(dp,v,i);
}


struct verx{
	bool selected;
	int *distance;
	int *source;
	int status;//true if permanent, false if temporary
	int sdsc;//similar_dist_source_count;
};

void initialize(struct verx *dp,int v, int src){
	int i;
	for(i=0;i<v;i++){
		dp[i].selected=false;
		dp[i].status=false;
		dp[i].sdsc=0;
		dp[i].distance=(int*)malloc(v*sizeof(int));
		dp[i].source=(int*)malloc(v*sizeof(int));
	}
	dp[src].selected=true;
	dp[src].status=true;
	//puts("here");
	dp[src].distance[dp[src].sdsc]=0;
	dp[src].source[dp[src].sdsc]=-1;
	dp[src].sdsc+=1;
}

void addedgesfromlastupdated(struct verx *dp, int *adjmat, int v, int lastupdated){
	int i;
	for(i=0;i<v;i++){
		if(adjmat[v*lastupdated+i]!=INT_MAX){
			if(dp[i].selected){
				if((dp[lastupdated].distance[0]+adjmat[v*lastupdated+i])==dp[i].distance[0]){
					dp[i].distance[dp[i].sdsc]=dp[i].distance[0];
					//printf("\nbefore updating: %d\t",dp[i].source[dp[i].sdsc-1]);
					dp[i].source[dp[i].sdsc]=lastupdated;
					//printf("after updating:%d\n",dp[i].source[dp[i].sdsc]);
					dp[i].sdsc++;
					//puts("here111");
				}
				else if((dp[lastupdated].distance[0]+adjmat[v*lastupdated+i])<dp[i].distance[0]){
					dp[i].distance[0]=dp[lastupdated].distance[0]+adjmat[v*lastupdated+i];
					dp[i].source[0]=lastupdated;
					dp[i].sdsc=1;
					//puts("here222");
					//printf("kiser jonno dhukche:%d new distance is: %d\n",i,dp[i].distance[0]);
				}
			}
			else{
				dp[i].selected=true;
				dp[i].distance[dp[i].sdsc]=adjmat[v*lastupdated+i]+dp[lastupdated].distance[0];
				dp[i].source[dp[i].sdsc]=lastupdated;
				dp[i].sdsc++;
			}			
		}
	}
}

/*void printSSSP(struct verx *dp, int v){
	int i,j;
	printf("\nThe final tree is:\nNODES\t[Dist, Src]\n");
	for(i=0;i<v;i++){
		printf("(%d)\t",i);
		if(!dp[i].selected){
			puts("IMPOSSIBLE to REACH");
			continue;
		}
		for(j=0;j<dp[i].sdsc;j++){
			printf("[%d,%d]",dp[i].distance[j],dp[i].source[j]);
		}
		puts("");
	}
}*/

void Dijkstra(int *adjmat, int v, int src,struct verx *dp){
	int i,j,lastupdated,min,minin;//minin is the minimum index
	//struct verx *dp;
	//dp=(struct verx*)malloc(v*sizeof(struct verx));
	initialize(dp,v,src);
	lastupdated=src;

	for(i=1;i<v;i++){//steps counter; 0 step is done already
		addedgesfromlastupdated(dp,adjmat,v,lastupdated);
		//findedgeofmindist(dp,v);
		//update here
		min=INT_MAX;
		minin=-1;
		for(j=0;j<v;j++){
			if(dp[j].selected==true && dp[j].status==false && dp[j].distance[0]<min){
				min=dp[j].distance[0];
				minin=j;
			}
			//if(dp[j].selected==true) printf("%d ",j);
		}
		//puts("\n");
		if(minin==-1)
			continue;
		dp[minin].status=true;//hence the minimum distance vertex is now permanent.
		lastupdated=minin;
		//printf("\nStep %d:-------------\n",i);
		//printSSSP(dp,v);
		//printf("\nminin=%d\n",minin);
	}
	//printSSSP(dp,v);
}

/*int main(){
	int v,e,*adjmat,i,j,a,b,d,*dp,src;
	printf("Enter the number of vertices and edges:");
	scanf("%d%d",&v,&e);
	adjmat=(int*)malloc(v*v*sizeof(int));
	for(i=0;i<v*v;i++) adjmat[i]=INT_MAX;
		printf("Enter the Edges and distance:\n");
	while(e--){
		scanf("%d%d%d",&a,&b,&d);//dijksrta algorithm do not have negative edges!!!!!
		adjmat[a*v+b]=d;
	}
	printf("Enter the Source Vertex: ");
	scanf("%d",&src);
	Dijkstra(adjmat,v,src);
}*/

int check(struct verx *dp1, int *dp, int v){
	int i;
	for(i=0;i<v;i++){
		if(dp1[i].selected==true && dp1[i].distance[0]!=dp[(v-1)*v+i]){
			printf("\ndp1=%d dp2=%d",dp1[i].distance[0],dp[(v-1)*v+i]);
			return 0;
		}
	}
	return 1;
}

int main(){
	struct verx *dp1;//dijk
	int *dp2;//bell
	int v,e,i,*adjmat,src,*edgeList,j=0;
	srand(time(NULL));
	while(1){
		v=rand()%10+10;
		e=rand()%25+12;
		src=rand()%10;
		edgeList=(int*)calloc(e*3,sizeof(int));
		adjmat=(int*)malloc(v*v*sizeof(int));
		printf("%d %d\n",v,e);
		for(i=0;i<v*v;i++) adjmat[i]=INT_MAX;
		for(i=0;i<e;i++){
			src=edgeList[i*3]=rand()%v;
			here:edgeList[i*3+1]=rand()%v;
			//puts("hi");
			if(edgeList[i*3]==edgeList[i*3+1])
				goto here;
			edgeList[i*3+2]=rand()%20+1;
			adjmat[v*edgeList[i*3]+edgeList[i*3+1]]=edgeList[i*3+2];
			printf("%d\t%d\t%d\n",edgeList[i*3],edgeList[i*3+1],edgeList[i*3+2]);
		}
		printf("%d\n",src);

		dp1=(struct verx*)malloc(v*sizeof(struct verx));
		Dijkstra(adjmat,v,src,dp1);
		dp2=(int*)calloc(v*(v-1),sizeof(int));
		BellmanFord(edgeList,e,v,src,dp2);
		if(check(dp1,dp2,v)){
			printf("Iteration: %d\tStatus: Accepted!\n",j++);
		}
		else{
			printf("Stalled!!");
			getch();
		}
	}
	return 0;
}
/*
8 16
0 2 2
0 1 1
1 2 1
1 3 5
1 4 2
2 5 4
2 4 1
2 3 2
3 4 3
3 6 8
3 5 6
4 5 3
4 6 7
5 6 5
5 7 2
6 7 6
0

5 8
0 1 5
0 2 3
0 3 10
0 4 9
1 2 1
2 3 4
3 1 2
3 4 1
0

*/