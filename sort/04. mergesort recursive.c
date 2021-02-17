#include<stdio.h>
#define mxn 20
#define db(x) printf("%s is %d\n",#x,x);
int num[mxn],temp[10000];

void mergesort(int lo,int hi){
    if(lo==hi) return;
    int mid=(lo+hi)/2;

    mergesort(lo,mid);
    mergesort(mid+1,hi);

    int i,j,k;
    for(i=lo,j=mid+1,k=lo;k<=hi;k++){
        if(i==mid+1) 
            temp[k]=num[j++];
        else if(j==hi+1) 
            temp[k]=num[i++];
        else if(num[i]<num[j]) 
            temp[k]=num[i++];
        else 
            temp[k]=num[j++];
    }
    for(k=lo;k<=hi;k++) num[k]=temp[k];
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i) scanf("%d",&num[i]);
    mergesort(0,n-1);
    for(int i=0;i<n;++i) printf("%d ",num[i]);
    return 0;
}

/*
15
34535 345 3 345 34 52315 6567 7 5 45 6 8 9 6 999
*/