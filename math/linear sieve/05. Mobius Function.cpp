#include "bits/stdc++.h"
using namespace std;
#define ff first
#define ss second
#define pb push_back
typedef long long ll;
const int N = 1e4+9;
bool comp[N+7];
vector<int> prime;
int mu[N+7];

void sieve() {
    mu[1] = 1;
    for(int i=2;i<N;++i) {
        if(!comp[i]) {
            prime.push_back(i);
            mu[i] = -1; // obiously the number of prime factors of a prime number is odd
        }
        for(int j=0;i*prime[j]<N;++j) {
            int x = i*prime[j];
            comp[x] = 1; // Marking indicates that it is not a prime number 4%2==0 4*2=8
            if(i%prime[j]==0) { // x = i*p, i%p==0 => p^2 | x
                mu[x] = 0;
                break;
            }
            mu[x] = mu[i]*(-1); // or mu[x] = -mu[i]
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    int a,b,n,T=0;
    sieve();
    while(cin>>n && n!=-1) {
        if(T++) cout<<endl;
        cout<<"M("<<n<<") = "<<mu[n]<<endl;
    }
    return 0;
}

/*
https://vjudge.net/problem/UVALive-2116/origin
*/