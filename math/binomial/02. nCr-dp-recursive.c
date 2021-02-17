#include<stdio.h>
#define db(x) printf("%s is %d\n",#x,x);
int dp[100][100];

int ncr(int n,int r){
	if(r==1) return n;
	if(n==r) return 1;
	else if(dp[n][r]) return dp[n][r];
	else dp[n][r]=ncr(n-1,r)+ncr(n-1,r-1);
	return dp[n][r];
}
int main(){
	int T,a,n,r;
	while(scanf("%d %d",&n,&r) != EOF){
		if(n-r < r) r=n-r;
		printf("%d\n",ncr(n,r));
	}
	return 0;
}