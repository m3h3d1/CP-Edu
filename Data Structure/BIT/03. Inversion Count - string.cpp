#include<bits/stdc++.h>
using namespace std;
const int mxn = 3e4+9;
int n;
int A[mxn]; //index of 1st sentence based on 2nd sentence
int BIT[mxn];

void update(int idx, int x) {
    for(int i=idx;i<=n;i+=i&(-i)) {
        BIT[i] += x;
    }
}
int get(int idx) {
    int s=0;
    for(int i=idx;i>0;i-=i&(-i)) {
        s += BIT[i];
    }
    return s;
}

int main() {
    ios_base::sync_with_stdio(false);
    int a,b,T,cas=0;
    string str;
    cin>>T;
    while(T--) {
        unordered_map<string, int> mp;
        cin>>n;
        fill(BIT,BIT+n+1,0);
        for(int i=1;i<=n;++i) {
            cin>>str;
            mp[str] = i;
        }
        for(int i=1;i<=n;++i) {
            cin>>str;
            A[i] = mp[str];
        }

        long long inv = 0;
        for(int i=n;i>=1;--i) {
            int x = get(A[i]);
            inv += x;
            update(A[i], 1);
        }
        cout<<inv<<'\n';
    }
    return 0;
}

/*
Yodaness Level : SPOJ - YODANESS 

2
6
in the force strong you are
you are strong in the force
6
or i will help you not
or i will not help you
*/