//not tested on oj
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6;
int cnt[N+9], lmul[N+9];

int maxGCD(int hi) {
    for(int i=hi;i>=1;--i) {
        int count=0;
        for(int j=i;j<=hi;j+=i) {
            if(cnt[j]>=2) return j;
            else if(cnt[j]==1) count++;
            if(count==2) return i;
        }
    }
    return -1; //garbage
}
int main() {
    int a,b,n,T,cas=0,x;
    string str;
    cin>>T;
    cin.ignore();
    while(T--) {
        memset(cnt, 0, sizeof(cnt));
        getline(cin, str);
        stringstream ss(str);
        int hi = 0;
        while(ss>>x) {
            cnt[x]++;
            if(x>hi) hi = x;
        }
        int res=maxGCD(hi);
        printf("%d\n", res);
    }
    return 0;
}

/*
3
10 20 30 40
7 5 12
125 15 25
*/