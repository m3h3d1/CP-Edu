#include<bits/stdc++.h>
using namespace std;
string A, B;
int dp[2][3005];

int dist(int l1, int l2) {
	int x;
	for(int i=0;i<=l1;++i) {
		x = i&1;
		for(int j=0;j<=l2;++j) {
			if(i==0) dp[x][j] = j; //add
			else if(j==0) dp[x][j] = i; //delete
			else if(A[i-1] == B[j-1]) dp[x][j] = dp[1-x][j-1];
			else dp[x][j] = min( min(dp[x][j-1]+1, dp[1-x][j]+1), dp[1-x][j-1]+1 );
		}
	}
	return dp[x][l2];
}

int main() {
	int n,T,cas=0;
	cin>>T;
	while(T--) {
		A.clear(), B.clear();
		cin>>A>>B;
		int res = dist(A.size(), B.size());
		printf("%d\n",res);
	}
	return 0;
}

/*
1
FOOD
MONEY
*/

/*
If you have noticed, we just need the (i – 1)th row to calculate the ith row. 
Which means that we need not store the entire array, we could just store the previous row only. 
This drastically reduces the memory complexity.
*/