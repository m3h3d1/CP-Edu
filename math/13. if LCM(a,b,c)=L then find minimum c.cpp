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
void pfact(ll n,map<ll, int> &mp) {
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
        pfact(a,m1), pfact(b,m2), pfact(L,m3);
        ll res=1;
        for(map<ll,int>::iterator it=m3.begin();it!=m3.end();++it) {
            if(m1[it->first]<it->second && m2[it->first]<it->second) {
                for(int i=1;i<=it->second;++i) res*=it->first;
            }
        }
        printf("Case %d: %lld\n",++cas,res);
    }
    return 0;
}

/*
Lightoj 1215: 
LCM is an abbreviation used for Least Common Multiple in Mathematics. We say LCM (a, b, c) = L if and only if L is the least integer which is divisible by a, b and c.
You will be given a, b and L. You have to find c such that LCM (a, b, c) = L. If there are several solutions, print the one where c is as small as possible. If there is no solution, report so.

Input
Input starts with an integer T (≤ 325), denoting the number of test cases.
Each case starts with a line containing three integers a b L (1 ≤ a, b ≤ 10^6, 1 ≤ L ≤ 10^12).

Output
For each case, print the case number and the minimum possible value of c. If no solution is found, print 'impossible'.

Sample Input
3
3 5 30
209475 6992 77086800
2 6 10

Sample Output
Case 1: 2
Case 2: 1
Case 3: impossible
*/

/*
if  a=p1^2 * p2^4
	b=p1^3 * p2^1 * p3^4
	c=p1^1 * p2^2 * p3^5* p4^1
then lcm=p1^3 * p2^4 * p3^5 * p4^1

so, minimum c = p3^5 * p4^1
*/