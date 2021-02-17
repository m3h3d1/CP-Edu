//geeks4geeks
#include<stdio.h>
#include<limits.h>
#define max(a,b) (a>b ? a:b)

int eggdrop(int n,int k){
	int res,dp[n+1][k+1];
	//1 trial for 1 floor and 0 trials for 0 floors
	for(int i=1;i<=n;++i){
		dp[i][1]=1;
		dp[i][0]=0;
	}
	//j trials for 1 egg and j floors
	for(int j=1;j<=k;++j) dp[1][j]=j;

	for(int i=2;i<=n;++i){
		for(int j=2;j<=k;++j){
			dp[i][j]=INT_MAX;
			for(int x=1;x<=j;++x){
				res=1+max(dp[i-1][x-1],dp[i][j-x]);
				if(res<dp[i][j]) dp[i][j]=res;
			}
		}
	}
	return dp[n][k];
}
int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	int res=eggdrop(n,k);
	printf("Minimum num of trials in worst case\nwith %d eggs and %d floors is -> %d\n",n,k,res);
	return 0;
}

/*
2 4
ans->3

2 10
ans->4

2 36
ans->8
*/