#include<iostream>
#include<vector>
#include<map>
using namespace std;
#define ll long long

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
void npf(ll n,map<ll, int> &mp) {
    for(int i=0;(long long)prime[i]*prime[i]<=n;++i) {
        int power=0,c=0;
        while(n%prime[i]==0) {
            power++;
            n/=prime[i];
            c=1;
        }
        if(c) mp[prime[i]]=power;
    }
    if(n!=1) mp[n]=1;
}
int main() {
    sieve();
    int T,cas=0;
    ll a,b,L;
    cin>>T;
    while(T--) {
        cin>>a>>b>>L;
        if(L%a!=0 || L%b!=0) {
            printf("Case %d: impossible\n",++cas);
            continue;
        }
        map<ll,int> m1,m2,m3;
        npf(a,m1), npf(b,m2), npf(L,m3);
        ll res=1;
        for(auto it=m3.begin();it!=m3.end();++it) {
            if(m1[it->first]<it->second && m2[it->first]<it->second) {
                for(int i=1;i<=it->second;++i) res*=it->first;
            }
        }
        printf("Case %d: %lld\n",++cas,res);
    }
    return 0;
}

/*
a b L (1 ≤ a, b ≤ 106, 1 ≤ L ≤ 1012).
*/
/*
3
3 5 30
209475 6992 77086800
2 6 10
*/