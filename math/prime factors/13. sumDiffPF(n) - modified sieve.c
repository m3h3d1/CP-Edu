#include<stdio.h>
#include<stdbool.h>
#define mxn 5000005
#define db(x) printf("%s is %d\n",#x,x);
int sumDiffPF[mxn];

void modifiedSieve(){
    int i,j;
    for(i=2;i<mxn;i+=2) sumDiffPF[i]=2;
    for(i=3;i<mxn;i+=2){
        if(!sumDiffPF[i]){ /* check prime */
            for(j=i;j<mxn;j+=i) sumDiffPF[j]+=i;
        }
    }
}
int main(){
    modifiedSieve();
    int a;
    while(scanf("%d",&a) && a){
        printf("%d\n",sumDiffPF[a]);
    }
    return 0;
}