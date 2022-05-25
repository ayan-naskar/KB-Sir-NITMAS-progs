#include<stdio.h>
#include<stdlib.h>

#define prr(n,p) p=(float *)malloc(n*sizeof(float))
#define s(n) scanf("%f",&n)
#define p(n) printf("\t%0.2f",n)
#define fo(i,n) for(i=0;i<n;i++)

void swap(float *a, float *b){
    float t=*a;
    *a=*b;
    *b=t;
}

int main(){
    float *c, *w,*r,n,tot_wt,tot_prof=0.0,x;
    int i,j;
    puts("Enter the number of sacks: ");
    s(n);
    puts("Enter the total sack size: ");
    s(tot_wt);
    puts("Enter the cost list: ");
    prr(n,c);
    fo(i,n) s(c[i]);
    puts("Enter the weight list: ");
    prr(n,w);
    prr(n,r);
    fo(i,n){
        s(w[i]);
        r[i]=c[i]/w[i];
    }

    //sorting:
    fo(i,n-1){
        fo(j,n-i-1){
            if(r[j]<r[j+1]){
                swap(&r[j+1],&r[j]);
                swap(&c[j+1],&c[j]);
                swap(&w[j+1],&w[j]);
            }
        }
    }

    puts("The Sorted table is: ");
    printf("ITEM:\t");
    fo(i,n) p((float)i+1);
    printf("\nCost:\t");
    fo(i,n) p(c[i]);
    printf("\nWts:\t");
    fo(i,n) p(w[i]);
    printf("\nRatio:\t");
    fo(i,n) p(r[i]);


    puts("\nThe weights taken and their ratio are:");

    //main portion of greedy
    fo(i,n){
        if(w[i]<=tot_wt){
            tot_wt-=w[i];
            tot_prof+=c[i];
            printf("[%0.2f,%0.2f]\t",w[i],1.00);
        }
        else break;
    }
    if(i<n){
        x=w[i]/tot_wt;
        x=1/x;
        //p(x);

        tot_prof+=c[i]*x;
        printf("[%0.2f,%0.2f]\t",w[i],x);
    }
    printf("\nThe Maximum profit is: %0.2f",tot_prof);
    return 0;
}
/*
5
60
30 100 160 90 20
5 20 40 30 10

*/