#include<iostream>
#include<vector>
using namespace std;

const int mxn=1e6+5;
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

int numdiv(long long n) {
    int res=1;
    for(int i=0;(long long)prime[i]*prime[i]<=n;++i) {
        int power=0;
        while(n%prime[i]==0) {
            power++;
            n/=prime[i];
        }
        res*=(power+1);
    }
    if(n!=1) res*=2;
    return res;
}
int main() {
    sieve();
    int T,cas=0;
    long long n;
    cin>>T;
    while(T--) {
        cin>>n;
        int res=numdiv(n);
        printf("Case %d: %d\n",++cas,res);
    }
    return 0;
}

/*
5

2
6
100
999999
*/