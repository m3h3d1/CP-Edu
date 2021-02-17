#include<bits/stdc++.h>
using namespace std;
string A, B;
int dp[260][260];

int dist(int l1, int l2) {
	for(int i=0;i<=l1;++i) {
		for(int j=0;j<=l2;++j) {
			if(i==0) dp[i][j] = j;
			else if(j==0) dp[i][j] = i;
			else if(A[i-1] == B[j-1]) dp[i][j] = dp[i-1][j-1];
			else dp[i][j] = min( min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
		}
	}
	return dp[l1][l2];
}

int main() {
	int a,b,n,T,cas=0;
	cin>>T;
	while(T--) {
		memset(dp, -1, sizeof(dp));
		cin>>A>>B;
		transform(A.begin(), A.end(), A.begin(), ::toupper);
		transform(B.begin(), B.end(), B.begin(), ::toupper);
		int res = dist(A.size(), B.size());
		printf("%d. Edit Distance = %d\n", ++cas, res);
	}
	return 0;
}

/*
5
Cat Bat
Fly Flying
Grave Groovy
Kitten Sitting
Alpha Omega
*/