#include<stdio.h>
#include<stdlib.h>

#define fo(i,n) for(i=0;i<n;i++)
#define si(n) scanf("%d",&n)
#define pi(n) printf("%d\t",n)
#define prr(p,n) p=(int *)calloc(n,sizeof(int))

void swap(int *a,int *b){
    int t=*a;
    *a=*b;
    *b=t;
}

int main(){
	int *job_prio,*job_prof,i,n,j,*job_set,maxSetSize=0,profit=0;
	int a;
	printf("Enter the total number of people waiting for job: ");
	si(n);
	printf("Enter the profit list:\t");
	prr(job_prof,n);
	prr(job_prio,n);
	fo(i,n) si(job_prof[i]);
	printf("Enter the deadline list:");
	fo(i,n) si(job_prio[i]);
	fo(i,n-1){//sorting
        fo(j,n-i-1){
            if(job_prof[j]<job_prof[j+1]){
                swap(&job_prof[j+1],&job_prof[j]);
                swap(&job_prio[j+1],&job_prio[j]);
            }
        }
    }
    printf("\n\nThe Table is...\n");
    printf("Job Priority:\t");fo(i,n) pi(job_prio[i]);
    printf("\nJob Profit:  \t");fo(i,n) pi(job_prof[i]);

    fo(i,n) if(maxSetSize<job_prio[i]) maxSetSize=job_prio[i];
    prr(job_set,n);
    //puts("Done here");
    fo(i,n){
    	a=job_prio[i]-1;
    	here:if(job_set[a]==0)
    		job_set[a]=job_prof[i];
    	else{
    		j=a;
    		while(job_set[j]!=0 && j>=0)
    			j--;
    		if(j==-1)continue;
    		goto here;
    	}
    }
    fo(i,maxSetSize) profit+=job_set[i];
    printf("\n\nJob list done: ");fo(i,maxSetSize) printf("%d ",job_set[i]);puts("");
    printf("\nThe Maximum Profit is: %d",profit);
}
/*
5
30 50 40 10 20
3 2 4 1 5

5
60 100 20 40 20
2 1 3 2 1

4
100 10 15 27
2 1 2 1

*/