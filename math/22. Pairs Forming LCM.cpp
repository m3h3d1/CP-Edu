#include<bits/stdc++.h>
using namespace std;
#define db(x) cerr<<__LINE__<<": "<<#x<<" = "<<(x)<<'\n'
const int N = 1e7+5;
bool comp[N+7]={1,1};
vector<int>prime;
#define ll long long

void sieve() {
    for(int i=4;i<N;i+=2) comp[i]=1;
    for(ll i=3;i<=N/i;i+=2) {
        if(!comp[i]) {
            for(ll j=i*i;j<N;j+=2*i) comp[j]=1;
        }
    }
    prime.emplace_back(2);
    for(int i=3;i<N;i+=2) {
        if(!comp[i]) prime.emplace_back(i);
    }
}

vector<int> pfact(ll n) {
	vector<int> v;
	for(int i=0;i<prime.size() && (ll)prime[i]*prime[i]<=n;++i) {
		if(n%prime[i]==0) {
			int power=0;
			while(n%prime[i]==0) {
				power++;
				n/=prime[i];
			}
			v.emplace_back(power);
		}
	}
	if(n!=1) v.emplace_back(1);
	return v;
}

int main(){
	sieve();
	ios_base::sync_with_stdio(0);
	int a,b,T,cas=0;
	ll n;
	cin>>T;
	while(T--) {
		cin>>n;
		vector<int> v=pfact(n);
		ll res=1;
		for(int i=0;i<v.size();++i) {
			res*=2*(v[i]+1)-1;
		}
		res=(res+1)/2;
		cout<<"Case "<<++cas<<": "<<res<<'\n';
	}
	return 0;
}

/*
8

2
6
12
18
20
21
24
27
*/

/*
Find the result of the following code:

long long pairsFormLCM( int n ) {
    long long res = 0;
    for( int i = 1; i <= n; i++ )
        for( int j = i; j <= n; j++ )
           if( lcm(i, j) == n ) res++; // lcm means least common multiple
    return res;
}

A straight forward implementation of the code may time out. If you analyze the code, you will find that the code actually counts the number of pairs (i, j) for which lcm(i, j) = n and (i ≤ j).

Input
Input starts with an integer T (≤ 200), denoting the number of test cases.
Each case starts with a line containing an integer n (1 ≤ n ≤ 10^14).
*/

/*
360 = 23 * 32* 51

Let the first number be (2^a x 3^b x 5^c) 
Let the second number be (2^d x 3^e x 5^f)

Now looking at just 2's - at least one of "a" or "d" will have to be 3 for the LCM to have 23. When one of those variables is selected to be 23 the other one can take values from 20 to 23.

Therefore number of cases would be 2(selecting which variable will be 2^3)x4(the other variable can take 4 values from 2^0 to 2^3)-1(removing the extra case where variables are 2^3 and 2^3 as they are identical)=7 cases

List of cases will be (2^3,2^0), (2^3,2^1), (2^3,2^2), (2^3,2^3), (2^0,2^3),(2^1,2^3), (2^2,2^3)

Hopefully now you can engage in the same process for 3's and 5's and reach the following state
Cases with 3's = 2x3-1=5
Cases with 5's = 2x2-1=3

Therefore total number of cases will be 7x5x3=105 (these will be ordered number of pairs). If you want unordered pairs, except the case of (360,360) each case has been repeated twice.
Therefore number of cases with unordered pairs will be (105+1)/2=53.
*/