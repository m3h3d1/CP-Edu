#include<stdio.h>
#define MX 46345
#define db(x) printf("%s is %d\n",#x,x);
int flag[MX],prime[MX/3], cnt;

void sieve(){
    int i,j;
    cnt=0;
    prime[cnt++]=2;
    for(i=4;i<MX;i+=2){
        flag[i]=1;
    }
    for(i=3;i<MX;i+=2){
        if(!flag[i]){
            prime[cnt++]=i;
            for(j=i*i;j<MX;j+=i*2) flag[j]=1;
        }
    }
}
int phiNdiv(int n){
    int coprime=n,divn=1,i,power;
    for(i=0;i<cnt && n>1;i++){
        power=0;
        if(n%prime[i]==0){
            coprime-=coprime/prime[i];
            while(n%prime[i]==0){
                n=n/prime[i];
                power++;
            }
            divn*=(power+1);
        }
    }
    if(n>1){
        coprime-=coprime/n;
        divn*=2;
    }
    return divn+coprime-1;
}

int main(){
    int n,ans;
    sieve();
    while(scanf("%d",&n) != EOF){
        ans=n-phiNdiv(n);
        printf("%d\n",ans);
    }
    return 0;
}

//for 6-> 1,2,3 are divisors gcd(m,n)=m
// 5,6 are relative-prime gcd(m,n)=1;