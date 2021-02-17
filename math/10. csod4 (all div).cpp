#include<bits/stdc++.h>
using namespace std;

int csod(int n) {
    int s = 0;
    for(int i=1;i<=n;++i) {
        s += (n/i) * i;
    }
    return s;
}
int main() {
    int a,b,n,T,cas=0;
    while(cin>>n) {
        int res = csod(n);
        cout<<res<<endl;
    }
    return 0;
}

/*
1
2
3
4
5
*/