#include<stdio.h>
#include<math.h>
#define mxn 1000000
#define ll long long
#define db(x) printf("%s is %d\n",#x,x);
int numDiffPF[mxn];

void sieveDiffPF(){
    int i,j,sq=sqrt(mxn);
    for(i=2;i<mxn;i+=2) numDiffPF[i]++;
    for(i=3;i<mxn;i+=2){ /* not sq  ie. 33073*3=99219 ,here 2 PF*/
        if(numDiffPF[i]==0){
            //printf("%d ",i);
            for(j=i;j<mxn;j+=i) numDiffPF[j]++;
        }
    }
}
int main(){
    sieveDiffPF();
    int n;
    while(scanf("%d",&n) != EOF){
        printf("\nnum of different prime factor is %d\n\n",numDiffPF[n]);
    }
    return 0;
}