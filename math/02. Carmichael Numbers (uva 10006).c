/*time 0.040s*//

#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>
#define type unsigned long long
#define db(x) printf("%s is %d\n",#x,x);
#define MX 65000
bool prime[MX];

void sieve(){
    memset(prime,1,sizeof(prime));
    prime[0]=prime[1]=0;
    int i,j,sq=sqrt(MX);
    for(i=4;i<MX;i+=2) prime[i]=0;
    for(i=3;i<=sq;i+=2){
        if(prime[i]){
            for(j=i*i;j<MX;j+=i*2) {
                prime[j]=0;
            }
        }
    }
}
type bigmod(int b,int p,int m){
    if(p==1) return b%m;
    else if(p%2==0){
        type x= bigmod(b,p/2,m);
        return (x*x)%m;
    }
    else {
        return bigmod(b,p-1,m)%m * b%m;
    }
}

int main(){
    sieve();
    int n,i,c;
    type a;
    while(scanf("%d",&n) && n){
        c=1;
        if(prime[n]) c=0;
        else{
            for(i=2;i<n;i++){
                 if(prime[i]){
                    a=bigmod(i,n,n);
                    if(a!=i){
                        c=0;
                        break;
                    }
                } 
            }
        }
        if(c) printf("The number %d is a Carmichael number.\n",n);
        else printf("%d is normal.\n",n);
    }
    return 0;
}




/*precalculated, time 0.010s (AC by me)*/

// #include<stdio.h>
// #include<stdbool.h>
// bool pre[65000];
// int main(){
//     int n;
//     pre[561]=pre[1105]=pre[1729]=pre[2465]=pre[2821]=pre[6601]=pre[8911]=pre[10585]=pre[15841]=pre[29341]=pre[41041]=pre[46657]=pre[52633]=pre[62745]=pre[63973]=1;
//     while(scanf("%d",&n) && n){
//         if(pre[n]) printf("The number %d is a Carmichael number.\n",n);
//         else printf("%d is normal.\n",n);
//     }
//     return 0;
// }




/*precalculated, time 0.00s (AC by me)*/

// #include<stdio.h>
// #include<stdbool.h>
// bool pre[65000];
// int main(){
//     int n;
//     pre[561]=pre[1105]=pre[1729]=pre[2465]=pre[2821]=pre[6601]=pre[8911]=pre[10585]=pre[15841]=pre[29341]=pre[41041]=pre[46657]=pre[52633]=pre[62745]=pre[63973]=1;
//     while(scanf("%d",&n) && n){
//         if(pre[n]) printf("The number %d is a Carmichael number.\n",n);
//         else printf("%d is normal.\n",n);
//     }
//     return 0;
// }