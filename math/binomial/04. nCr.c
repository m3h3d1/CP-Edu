/*if the answer will not exceed the int range,
intermidiate result will not be overflowed */
#include<stdio.h>
#define db(x) printf("%s is %d\n",#x,x);

long long ncr(int n,int r){
    long long res=1,i;
    if(n-r<r) r=n-r;
    for(i=0;i<r;i++){
        res*=(n-i);
        res/=(i+1);
    }
    // for(int i=1;i<=r;++i) {
    //     res *= (n-i+1);
    //     res /= i;
    // }
    return res;
}

int main(){
    int n,r;
    while(scanf("%d %d",&n, &r) && !(n==0 && r==0)){ /* *** */
        printf("%lld\n",ncr(n,r));
    }
    return 0;
}

/*
uva 530
Test I/O
Input
5 0
65535 2 
2345 3 
477 4
43 10 
34 15 
65535 65533 
2147483647 2147483646 
0 0 

Output
1
2147385345 
2146453540 
2130031575 
1917334783 
1855967520 
2147385345 
2147483647
*/

/*
for(i=n,j=1;i>r && j<=r;i--,j++){
        res*=i;
        res/=j;
}
*/