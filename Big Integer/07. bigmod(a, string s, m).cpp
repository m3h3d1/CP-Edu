#include<bits/stdc++.h>
using namespace std;

int powmod(int a, int b, int m) {
    a%=m;
    int res = 1%m;
    while(b) {
        if(b&1) res = (res*a)%m;
        a = (a*a)%m;
        b>>=1;
    }
    return res;
}
int mypow(int x, string s, int m) {
    x%=m;
    int res = 1%m;
    int now = x; 
    for(int i=s.size()-1;i>=0;--i) {
        res = (res*powmod(now, s[i]-'0', m)) % m;
        now = powmod(now, 10, m);
    }
    return res;
}
int main() {
    int a,m;
    string s;
    cin>>a>>s>>m;
    int res =  mypow(a, s, m)%m;
    cout<<res<<endl;
    return 0;
}

/*
15 234 8888
*/

/*
15^234 er jonno:
res = 1
res = res*(15^4)
res = res * (15^10)^3
res = res * (15^100)^2
*/