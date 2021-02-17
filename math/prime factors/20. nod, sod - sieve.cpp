#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const int N = 1e5+9;
ll nod[N], sod[N];

void sieve() {
    for(int i=1;i<N;i++) {
        for(int j=i;j<N;j+=i) {
            nod[j]++;
            sod[j] += i;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    sieve();
    int a,b,n,T;
    cout<<nod[10]<<" "<<sod[10]<<endl;
    return 0;
}