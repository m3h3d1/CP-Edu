#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
	int a,b,n,W,T,cas=0;
	cin>>n>>W;
	vector<ll> dp(W+1);
	// dp[i] = the maximum total values of items with total weight exactly
	for(int i=0;i<n;++i) {
		int weight, val;
		cin>>weight>>val;
		for(int weight_already=W-weight;weight_already>=0;--weight_already) {
			dp[weight_already+weight] = max(dp[weight_already+weight], dp[weight_already]+val);
		}
	}
	cout<<dp[W]<<endl;
	return 0;
}

/*
All values in input are integers.
1≤N≤100
1≤W≤10^5
1≤wi≤W
1≤vi≤10^9
*/