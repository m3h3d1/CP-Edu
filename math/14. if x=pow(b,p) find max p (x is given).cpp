#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define ll long long

const int mxn=2e5+1;
bool comp[mxn];
vector<int> prime;
void sieve() {
	for(int i=2;i<mxn;++i) {
		if(!comp[i]) prime.push_back(i);
		for(int j=0;i*prime[j]<mxn;++j) {
			comp[i*prime[j]]=1;
			if(i%prime[j]==0) break;
		}
	}
}
void pfact(ll x,vector<int> &v) {
	for(int i=0;(long long)prime[i]*prime[i]<=x;++i) {
		if(x%prime[i]==0) {
			int cnt=0;
			while(x%prime[i]==0) {
				cnt++;
				x/=prime[i];
			}
			v.push_back(cnt);
		}
	}
	if(x!=1) v.push_back(1);
}
int calc(ll x) {
	vector<int>v; int neg=0;
	if(x<0) {
		x*=-1;
		neg=1;
	}
	pfact(x,v);
	int g=v[0];
	for(int i=1;i<v.size();++i) g=__gcd(g,v[i]);
	if(neg && g%2==0) while(g%2==0) g/=2;
	return g;
}
int main() {
	sieve();
	int a,b,n,T,cas=0;
	ll x;
	cin>>T;
	while(T--) {
	    cin>>x;
	    int res=calc(x);
	    printf("Case %d: %d\n",++cas,res);
	}
	return 0;
}

/*
Give you an x, satisfy x = b^p, what is the maximum p?

Algorithm idea:
x can be expressed as: x = p1^e1 * p2^e2 * p3^e3 ....... * pn^en. 
p = gcd (e1, e2, .......en); 
Pit: When x is negative, the value of p cannot be even.

----------------------------------------------------------------------
x = p1^x1*p2^x2*p3^x3*...*ps^xs
so, p = gcd(x1, x2, x3, ..., xs);
example: 24  = 2^3*3^1, p should be gcd(3, 1) = 1, ie 24 = 24^1
         324 = 3^4*2^2, p should be gcd(4, 2) = 2, ieIf x is a negative number, x = b^q, q must make an odd number, so the solution obtained by converting x into a positive number must be divided by 2 if it is even. 324 = 18^2

If x is a negative number, x = b^q, q must make an odd number, so the solution obtained by converting x into a positive number must be divided by 2 if it is even.
*/

/*
8
2147483647
-2147483648
32
-32
64
-64
4
-4

Output:

Case 1: 1
Case 2: 31
Case 3: 5
Case 4: 5
Case 5: 6
Case 6: 3
Case 7: 2
Case 8: 1
*/

/*
lightoj 1220
Input
Input starts with an integer T (≤ 50), denoting the number of test cases.

Each case starts with a line containing an integer x. You can assume that x will have magnitude at least 2 and be within the range of a 32 bit signed integer.
*/