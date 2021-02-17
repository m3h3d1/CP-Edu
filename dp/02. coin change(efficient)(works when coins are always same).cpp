#include<stdio.h>
#include<string.h>

int make,coin[]={1,5,10,25,50};
long long dp[6][7500];
long long call(int i,int amount){
    if(i>=5){
        if(amount==0) return 1;
        else return 0;
    }
    if(dp[i][amount]!=-1) return dp[i][amount];
    int ret1=0,ret2=0;
    if(amount-coin[i]>=0) ret1=call(i,amount-coin[i]);
    ret2=call(i+1,amount);
    return dp[i][amount]=ret1+ret2;
}
int main(){
    memset(dp,-1,sizeof(dp));
    while(scanf("%d",&make) != EOF){
        printf("%lld\n",call(0,make));
    }
    return 0;
}