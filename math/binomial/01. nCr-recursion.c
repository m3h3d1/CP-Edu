#include<stdio.h>
#define db(x) printf("%s is %d\n",#x,x);

int nCr(int n,int r){
    if(r==0 || r==n) return 1;
    return nCr(n-1,r-1)+nCr(n-1,r);
}
int main(){
    int T,a,n,r;
    while(scanf("%d %d",&n,&r) != EOF){
        printf("%d\n",nCr(n,r));
    }
    return 0;
}

/*
nCr=(n-1)C(r-1)+(n-1)Cr
*/