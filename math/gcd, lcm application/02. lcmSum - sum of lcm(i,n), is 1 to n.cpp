#include<bits/stdc++.h>
using namespace std;
#define db(x) cerr<<__LINE__<<": "<<#x<<" = "<<(x)<<'\n'
const int N = 1e6;
#define ll long long
ll phi[N+7];
ll sum[N+7];

void sievephi() {
	for(int i=1;i<=N;++i) phi[i]=i;
	for(int i=2;i<=N;++i) {
		if(phi[i]==i) {
			for(int j=i;j<=N;j+=i) phi[j] -= phi[j]/i;
		}
	}
}
void pre() {
	for(int i=1;i<=N;++i) {
		for(int j=i;j<=N;j+=i) sum[j] += i*phi[i];
	}
}
int main(){
	sievephi();
	pre();
	int a,b,T,cas=0;
	ll n;
	scanf("%d",&T);
	while(T--) {
		scanf("%lld",&n);
		ll res = n*(sum[n] + 1)/2;
		printf("%lld\n", res);
	}
	return 0;
}

/*
Constraints
1 <= T <= 300000
1 <= n <= 1000000
*/

/*
Sample Input:
3
1
2
5

Sample Output:
1
4
55
*/

/*
Given n, calculate the sum LCM(1,n) + LCM(2,n) + .. + LCM(n,n), where LCM(i,n) denotes the Least Common Multiple of the integers i and n.

Input
The first line contains T the number of test cases. Each of the next T lines contain an integer n.

Output
Output T lines, one for each test case, containing the required sum.
*/