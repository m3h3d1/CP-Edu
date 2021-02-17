#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define db(x) cerr<<__LINE__<<": "<<#x<<" = "<<(x)<<'\n'
const int N = 2e5+9;
int me[N][5];

int main() {
    ios_base::sync_with_stdio(0);
    int a,b,n,T,cas=0;
    string s;
    cin>>n>>s;
    s="#"+s;
    me[1][1]=me[1][2]=me[1][3]=1;
    if(s[1]=='R') me[1][1]=0;
    else if(s[1]=='G') me[1][2]=0;
    else if(s[1]=='B') me[1][3]=0;

    for(int i=2;i<=n;++i) {
        me[i][1] = min(me[i-1][2], me[i-1][3]);
        me[i][2] = min(me[i-1][1], me[i-1][3]);
        me[i][3] = min(me[i-1][1], me[i-1][2]);
        if(s[i]=='R') {
            me[i][2] += 1;
            me[i][3] += 1;
        }
        else if(s[i]=='G') {
            me[i][1] += 1;
            me[i][3] += 1;
        }
        else if(s[i]=='B') {
            me[i][1] += 1;
            me[i][2] += 1;
        }
    }
    int res = min({me[n][1], me[n][2], me[n][3]});

    if(me[n][1]==res) s[n]='R';
    else if(me[n][2]==res) s[n]='G';
    else s[n]='B';

    for(int i=n-1;i>=1;--i) {
        if(s[i+1]=='R') {
            if(me[i][2]<me[i][3]) s[i]='G';
            else s[i]='B';
        }
        else if(s[i+1]=='G') {
            if(me[i][1]<me[i][3]) s[i]='R';
            else s[i]='B';
        }
        else {
            if(me[i][1]<me[i][2]) s[i]='R';
            else s[i]='G';
        }
    }
    
    cout<<res<<endl;
    for(int i=1;i<=n;++i) cout<<s[i];

    return 0;
}

/*
9
RBGRRBRGG

8
BBBGBRRR

13
BBRRRRGGGGGRR
*/

/*
https://codeforces.com/contest/1108/problem/D
Greedy is also possible
*/