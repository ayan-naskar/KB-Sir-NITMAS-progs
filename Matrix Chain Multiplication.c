#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

void print(int *dp, int n, int fl){
	int i,j;
	printf("\t");
	for(i=0;i<n;i++)
		printf("(%c)\t",'A'+i);
	puts("");
	for(i=0;i<n;i++){
		printf("(%c)\t",'A'+i);
		for(j=0;j<n;j++){
			if((i>j && fl==0) || (i>=j && fl==1)){
				if(i==j)
					printf("-");
				printf("\t");
			}
			else
				printf("%d\t",dp[i*n+j]+fl);
		}
		puts("");
	}
}


void print_optimal_parenthesis(int *s,int i, int j,int n){
	if(i==j)
		printf("%c",'A'+i);
	else{
		printf("(");
		print_optimal_parenthesis(s,i,s[n*i+j],n);
		print_optimal_parenthesis(s,s[n*i+j]+1,j,n);
		printf(")");
	}
}

void print_everything(int *dp, int *s, int n){
	printf("The final dp matrix is:\n");
	print(dp,n,0);
	printf("The final Parenthesization matrix is:\n");
	print(s,n,1);
	printf("\nThe required parenthesis is: ");
	print_optimal_parenthesis(s,0,n-1,n);
}

void matrixChain(int *ar, int *dp, int n){
	int i,j,k,min,iter,cal,in_k;
	int *s=(int*)calloc(n*n,sizeof(int));
	for(iter=1;iter<n;iter++){
		for(i=0,j=iter;j<n;i++,j++){
			min=INT_MAX;//dp[n*i+j];
			in_k=-1;
			for(k=i;k<j;k++){
				cal=dp[n*i+k]+dp[n*(k+1)+j]+ar[i]*ar[k+1]*ar[j+1];
				if(min>cal){
					min=cal;
					in_k=k;//INDEX
				}
			}
			dp[i*n+j]=min;
			s[i*n+j]=in_k;
		}
	}
	print_everything(dp,s,n);
}

int main(){
	int i,n,*dim,*ar,*dp;
	printf("Enter the number of Matrices: ");
	scanf("%d",&n);
	dim=(int*)calloc(n*2,sizeof(int));
	printf("Enter the Dimensions:\n");
	for(i=0;i<n;i++){
		printf("%c: ",'A'+i);
		scanf("%d%d",&dim[2*i],&dim[2*i+1]);
	}
	ar=(int*)calloc(n+1,sizeof(int));
	ar[0]=dim[0];
	for(i=0;i<n;i++)
		ar[i+1]=dim[i*2+1];
	dp=(int*)calloc(n*n,sizeof(int));
	matrixChain(ar,dp,n);
	printf("\n\nThe Total number of minimum Multiplication required is %d",dp[n-1]);
}

/*
4
1 2
2 3
3 4
4 3


5
4 10
10 3
3 12
12 20
20 7

6
30 35
35 15
15 5
5 10
10 20
20 25

*/