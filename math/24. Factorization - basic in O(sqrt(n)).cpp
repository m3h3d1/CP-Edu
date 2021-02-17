#include "bits/stdc++.h"
using namespace std;
#define ff first
#define ss second
#define pb push_back
typedef long long ll;
#define db(x) cerr<<__LINE__<<": "<<#x<<" = "<<(x)<<'\n'
const int inf = 1e9+7;
const int N = 1e6+9;

int main() {
    ios_base::sync_with_stdio(0);
    int a,b,n;
    n=100;
    for(int i=1;i*i<=n;++i) {
        if(n%i) continue;
        int x = i;
        int y = n/i;
        if(x!=y) cout<<x<<" "<<y<<endl;
        else cout<<x<<endl;
    }
    return 0;
}