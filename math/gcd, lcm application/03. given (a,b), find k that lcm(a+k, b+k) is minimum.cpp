#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long long lcm(int a, int b) {
	return 1ll*a/__gcd(a,b)*b;
}
vector<int> v;
void divs(int n) {
	for(int i=1;i*i<=n;++i) {
		if(n%i == 0) {
			v.push_back(i);
			if(i*i != n) v.push_back(n/i);
		}
	}
	sort(v.begin(), v.end());
}
int main() {
	int a, b;
	cin>>a>>b;
	if(a==b) return 0 * puts("0");
	divs(abs(a-b));
	pair<long long, int> res = {LLONG_MAX, INT_MAX};
	for(auto d: v) {
		int k = (d-a%d)%d; //*
		pair<long long, int> curr = {lcm(a+k, b+k), k};
		res = min(res, curr);
	}
	cout<<res.second<<endl;
	return 0;
}

/*
https://codeforces.com/contest/1152/problem/C
https://codeforces.com/blog/entry/66696

Print the smallest non-negative integer k (k≥0) such that the lowest common multiple of a+k and b+k is the smallest possible.

If there are many possible integers k giving the same value of the least common multiple, print the smallest one.

6 10

21 31

5 10

1 1
*/