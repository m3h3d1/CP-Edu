#include<stdio.h>
#include<iostream>
#include<ctime>
using namespace std;
#define mxn 10000000
#define db(x) printf("%s is %d\n",#x,x);
int phi[mxn+1];

void sievephi(){
    int i,j;
    for(i=1;i<=mxn;i++) phi[i]=i;
    for(i=2;i<=mxn;i++){
        if(phi[i]==i){  // i is a prime number
            for(j=i;j<=mxn;j+=i){
                phi[j]-=phi[j]/i;
            }
        }
    }
}
int main(){
    int T,a,n,i;
    time_t t;
    t = clock();
    sievephi();
    t = clock() - t;
    cout<<(double)t/1000<<endl;
    while(scanf("%d",&n) != EOF){
        printf("%d\n",phi[n]);
    }
    return 0;
}