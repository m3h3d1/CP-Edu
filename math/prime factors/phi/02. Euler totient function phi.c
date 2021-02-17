#include<stdio.h>
#include<math.h>
#define db(x) printf("%s is %d\n",#x,x);

int phi(int n){
    /*if(n==1) return 1;*/
    int res=n,i,sq=sqrt(n);
    if(n%2==0){
        res-=res/2;
        while(n%2==0){
            n=n/2;
        }
    }
    for(i=3;i<=sq;i+=2){
        if(n%i==0){
            res-=res/i;
            while(n%i==0){
                n=n/i;
            }
        }
    }
    if(n!=1) res-=res/n;
    return res;
}
int main(){
    int n;
    while(scanf("%d",&n) && n){
        printf("%d\n",phi(n));
    }
    return 0;
}