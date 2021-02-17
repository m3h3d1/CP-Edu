#include<bits/stdc++.h>
using namespace std;
string A, B;
int dp[2][5005];

int lcs(int n, int m) {
	int x;
	for(int i=0;i<=n;++i) {
		x = i&1;
		for(int j=0;j<=m;++j) {
			if(i==0 || j==0) dp[x][j] = 0;
			else if(A[i-1] == B[j-1]) dp[x][j] = dp[1-x][j-1] + 1;
			else dp[x][j] = max( dp[1-x][j], dp[x][j-1] );
		}
	}
	return dp[x][m];
}
int main() {
	int a,b,n;
	cin>>A>>B;
	int l = lcs(A.size(), B.size());
	cout<<l<<endl;
	return 0;
}

/*
abcdef
cdefgh
*/