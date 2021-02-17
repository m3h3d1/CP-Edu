#include<iostream>
#include<cstring>
using namespace std;
string A, B;
int dp[2005][2005];

int dist(int m, int n) {
	if(m==0) return n;
	if(n==0) return m;
	if(dp[m-1][n-1] != -1) return dp[m-1][n-1];
	int cost = (A[m-1] == B[n-1]) ? 0 : 1;
	return dp[m-1][n-1] = min( min(dist(m-1, n)+1, dist(m, n-1)+1), dist(m-1, n-1)+cost);
}
int main() {
	int n,T,cas=0;
	while(cin>>A) {
		cin>>B;
		memset(dp, -1, sizeof(dp));
		int res = dist(A.size(), B.size());
		cout<<res<<endl;
	}
	return 0;
}

/*
fxpimu
xwrs
*/