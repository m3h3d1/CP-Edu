#include<stdio.h>
int main(){
    long long n,cnt;
    cnt=0;
    scanf("%lld",&n);
    if(n<10) cnt=n;
    else if(n<100) cnt=9+(n-9)*2;
    else if(n<1000) cnt=189+(n-99)*3;
    else if(n<10000) cnt=2889+(n-999)*4;
    else if(n<100000) cnt=38889+(n-9999)*5;
    else if(n<1000000) cnt=488889+(n-99999)*6;
    else if(n<10000000) cnt=5888889+(n-999999)*7;
    else if(n<100000000) cnt=68888889+(n-9999999)*8;
    else if(n<1000000000) cnt=788888889+(n-99999999)*9;
    else if(n<10000000000) cnt=8888888889+(n-999999999)*10;
    printf("%lld\n",cnt);
    return 0;
}