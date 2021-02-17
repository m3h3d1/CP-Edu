#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define db(x) cerr<<__LINE__<<": "<<#x<<" = "<<(x)<<'\n'
const int N = 1e6;

int main() {
    ios_base::sync_with_stdio(0);
    int a,b,n,T,cas=0;
    cin>>n;
    int s=0;
    for(int i=0;i<n;++i) {
        cin>>a;
        s = s^(2*a);
    }
    cout<<s<<endl;
    return 0;
}

/*
https://www.youtube.com/watch?v=LyMPfMe7T58
4
4 3 9 1

for this,
 8  7 13  5
 7  6 12  4
13 12 18 10
 5  4 10  2

here, evere element is occured twiced except the diagonal ones.
As we know A^A = 0, so sum of these duplicated items will be 0.

so final result will be 2 * A[i][j], where i=j.
*/