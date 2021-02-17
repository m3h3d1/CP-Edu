#include<stdio.h>
#include<math.h>
#define mxn 1000000
#define ll long long
#define db(x) printf("%s is %d\n",#x,x);
int cnt,flag[mxn+1],prime[mxn/3];

void sieve(){
    int i,j,sq=sqrt(mxn);
    cnt=0;
    prime[cnt]=2;
    for(i=4;i<=mxn;i+=2) flag[i]=1;
    for(i=3;i<=sq;i+=2){
        if(!flag[i]){
            prime[++cnt]=i;
            for(j=i*i;j<=mxn;j+=i*2) flag[j]=1;
        }
    }
}
ll EulerPhi(ll n){
    ll idx=0,pf=prime[idx],res=n;
    while(pf*pf<=n){
        if(n%pf==0){
            res-=res/pf;
            while(n%pf==0){
                n=n/pf;
                printf("%d ",pf);
            }
        }
        pf=prime[++idx];
    }
    if(n!=1) {
        res-=res/n;
        printf("%d",n);
    }
    return res;
}
int main(){
    sieve();
    int n,i;
    while(scanf("%d",&n) != EOF){
        printf("\nnum of relative-prime is %lld\n\n",EulerPhi(n));
    }
    return 0;
}

/*
1000
100
45
31
*/