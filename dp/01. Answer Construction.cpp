#include "bits/stdc++.h"
using namespace std;
#define ff first
#define ss second
#define pb push_back
typedef long long ll;
typedef pair<int,int> pii;
#define all(v) (v).begin(),(v).end()
#define db(x) cerr<<__LINE__<<": "<<#x<<" = "<<(x)<<'\n'
const int inf = 1e9+7;
const int N = 1e6+9;
int n=3, m=3;
vector<vector<int>> grid(3, vector<int>(3));
vector<vector<pii>> dp(n, vector<pii>(m, {-1, 0}));
// 0 -> take a down direction
// 1 -> take a right direction

int f(int i, int j) {
	if(i==n || j==m)
		return inf;
	if(i==n-1 && j==m-1)
		return grid[n-1][m-1];
	if(dp[i][j].first != -1)
		return dp[i][j].first;
	int ans1 = f(i+1, j);
	int ans2 = f(i, j+1);
	if(ans1 < ans2) {
		dp[i][j].second = 0;
		dp[i][j].first = grid[i][j] + ans1;
	}

	else {
		dp[i][j].second = 1;
		dp[i][j].first = grid[i][j] + ans2;
	}
	return dp[i][j].first;
}
int main() {
    ios_base::sync_with_stdio(0);
    for(int i=0;i<3;++i) {
    	for(int j=0;j<3;++j) {
    		cin>>grid[i][j];
    	}
    }
    cout<<f(0, 0)<<endl;

    pii cur = {0, 0};
    while(cur != make_pair(n-1, m-1)) {
    	cout<<cur.first<<" "<<cur.second<<'\n';
    	if(dp[cur.first][cur.second].second == 0)
    		cur.first++;
    	else
    		cur.second++;
    }
    cout<<cur.first<<" "<<cur.second<<'\n';
    return 0;
}

/*
1 2 3
10 1 3
1 1 1
*/
// https://youtu.be/YZDjUDW4xwc?t=5536