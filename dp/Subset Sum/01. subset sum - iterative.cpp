#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define db(x) cerr<<__LINE__<<": "<<#x<<" = "<<(x)<<'\n'
const int N = 1e3;
int mem[N+9][N+9], A[N+9];

int dp(int n, int k) {
	mem[0][0]=1;
	for(int i=1;i<=k;++i) mem[0][k]=0;
	
	for(int i=1;i<=n;++i) {
		for(int j=0;j<=k;++j) {
			if(j<A[i]) mem[i][j] = mem[i-1][j]; // As A[i] is bigger than j, we don't pick the current element A[i]
			else {
				int need = j-A[i];
				if(mem[i-1][j]==1 || mem[i-1][need]==1) // We ignore or take current element
					mem[i][j]=1; 
				else mem[i][j]=0;
			}
		}
	}
	return mem[n][k];
}

int main() {
	ios_base::sync_with_stdio(0);
	int a,b,n,k,T,cas=0;
	cin>>T;
	while(T--) {
		cin>>n>>k;
		for(int i=1;i<=n;++i) cin>>A[i];
		int res = dp(n, k);
		for(int i=0;i<=n;++i) {
			for(int j=0;j<=k;++j) cerr<<mem[i][j]<<" ";
			cerr<<endl;
		}
		cout<<res<<endl;
	}
	return 0;
}

/*
3

5 10
3 4 6 1 9

3 2
1 3 4

4 12
2 5 3 4
*/

/*
Given a set S of size N of non-negative integers, find whether there exists a subset whose sum is K.
https://www.codechef.com/problems/TF01
https://www.youtube.com/watch?v=BT_ACNC47Os
*/