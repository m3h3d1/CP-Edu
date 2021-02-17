#include<iostream>
#include<cstring>
using namespace std;
int weight[2005], val[2005];
int total_weight, n;
int dp[2005][2005];

int knapsack(int i, int bag) {
	if(i>=n || bag==total_weight) return 0;
	if(dp[i][bag]!=-1) return dp[i][bag];
	if(bag + weight[i] > total_weight) return dp[i][bag] = knapsack(i+1, bag);
	return dp[i][bag] = max(knapsack(i+1, bag), val[i]+knapsack(i+1, bag+weight[i]));
}
int main() {
	memset(dp,-1,sizeof(dp));
	cin>>total_weight>>n;
	for(int i=0;i<n;++i) {
		cin>>weight[i]>>val[i];
	}
	cout<<knapsack(0, 0)<<endl;
	return 0;
}

/*
4 5
1 8
2 4
3 0
2 5
2 3
*/