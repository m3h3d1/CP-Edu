#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s;

ll res = 0;
void dfs(int i, ll cur) {
	if(i==s.size()) {
		res += cur;
		return;
	}

	ll x = 0;
	for(int j=i;j<s.size();++j) {
		x = x*10 + s[j] - '0';
		dfs(j+1, cur+x);
	}
}

int main() {
	cin>>s;
	dfs(0,0);
	cout<<res<<endl;
	return 0;
}

/*
125
*/
/*
https://vjudge.net/problem/AtCoder-2067

There are 4 formulas that can be obtained: 125, 1+25, 12+5 and 1+2+5. When each formula is evaluated,

125
1+25=26
12+5=17
1+2+5=8
Thus, the sum is 125+26+17+8=176.
*/