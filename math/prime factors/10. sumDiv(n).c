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
long long mypow(long long n, int p) {
    long long res=1;
    for(int i=1;i<=p;++i) res*=n;
    return res;
}
ll sumDiv(ll n){
    ll idx=0,pf=prime[idx],res=1,power;
    while(pf*pf<=n){
        power=0;
        while(n%pf==0){
            n=n/pf;
            power++;
            printf("%d ",pf);
        }
        res*=((long long) mypow(pf,power+1)-1) / (pf-1);
        pf=prime[++idx];
    }
    if(n!=1) {
        res*=( (long long) mypow(n,2)-1) / (n-1);
        printf("%d",n);
    }
    return res;
}
int main(){
    sieve();
    int n,i;
    while(scanf("%d",&n) != EOF){
        printf("\nsum of divisor is %lld\n\n",sumDiv(n));
    }
    return 0;
}