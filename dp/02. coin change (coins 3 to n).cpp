#include "bits/stdc++.h"
using namespace std;
#define ff first
#define ss second
#define pb push_back
typedef long long ll;
#define db(x) cerr<<__LINE__<<": "<<#x<<" = "<<(x)<<'\n'
const int mod = 1e9+7;
const int N = 2e3+9;
int dp[N];  // dp[i] = how many ways to get this sum

void calc(int n) {
    dp[0] = 1; // there is one way to get sum 0: take nothing
    for(int sum=3;sum<=n;++sum) { // what sum do we want to get
        for(int coin=3;coin<=sum;++coin) { // going through the coins, 
// note that coins bigger than sum will not be considered because we can't get that sum using it. 
// for example it's impossible to get sum of 5 using atleast once coin 7
            dp[sum] += dp[sum-coin];
            dp[sum] %= mod; // taking mod
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    int a,b,n;
    cin>>n;
    calc(n);
    cout<<dp[n]<<endl;
    return 0;
}

/*
Given is an integer S Find how many sequences there are whose terms are all integers greater than or equal to 3,
and whose sum is equal to S. The answer can be very large, so output it modulo 10^9+7

https://atcoder.jp/contests/abc178/tasks/abc178_d
*/

// dp array at the end will be:
// dp[0] = 1; // {0}
// dp[1] = 0; // {}
// dp[2] = 0; // {}
// dp[3] = 1; // {3}
// dp[4] = 1; // {4}
// dp[5] = 1; // {5}
// dp[6] = 2; // {3+3, 6}
// dp[7] = 3; // {4+3, 3+4, 7}