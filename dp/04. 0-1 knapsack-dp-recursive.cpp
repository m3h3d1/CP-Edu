#include<stdio.h>
#include<string.h>
#define db(x) printf("%s is %d\n",#x,x);
int weight[]={4,1,4,3,4},cost[]={10,120,280,150,200};
int n=5,dp[1000][1000];

int max(int x,int y) { return x>y ? x:y; }
int knapsack(int bag,int item){ //bag -> bag_sz
    if(bag<0) return -cost[item-1];
    if(bag==0 || item>=n) return 0;
    if(dp[bag][item]!=-1) return dp[bag][item];
    return dp[bag][item]=max(cost[item]+knapsack(bag-weight[item],item+1), knapsack(bag,item+1));
}
int main(){
    memset(dp,-1,sizeof(dp));
    printf("%d\n",knapsack(10,0));
    return 0;
}

/*return zeroo */

/*
10 5
4 10
1 120
4 280
3 150
4 200
*/