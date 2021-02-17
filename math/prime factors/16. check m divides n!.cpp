//uva 10139
#include<iostream>
#include<vector>
#include<map>
using namespace std;
#define ll long long

const int mxn=1e5+5;
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
void pfact(int n,map<int, int> &mp) {
    for(int i=0;(long long)prime[i]*prime[i]<=n;++i) {
        int power=0,c=0;
        while(n%prime[i]==0) {
            power++;
            n/=prime[i];
            c=1;
        }
        if(c) mp[prime[i]]+=power;
    }
    if(n!=1) mp[n]++;
}
int powers(int n,ll p) {
    int res=0;
    for(ll i=p;i<=n;i*=p) {
        res+=n/i;
    }
    return res;
}
int main() {
    sieve();
    int T,cas=0;
    int n,m;
    while(cin>>n>>m) {
        if(!m) {
            printf("%d does not divide %d!\n",0,n);
            continue;
        }
        map<int,int> mp;
        pfact(m,mp);
        int c=1;
        for(auto it=mp.begin();it!=mp.end();++it) {
            int x=powers(n,it->first);
            if(x<it->second) {
                c=0;break;
            }
        }
        if(c)printf("%d divides %d!\n",m,n);
        else printf("%d does not divide %d!\n",m,n);
    }
    return 0;
}

/*
6 9
6 27
20 10000
20 100000
1000 1009
*/