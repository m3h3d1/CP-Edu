#include<iostream>
#include<cstring>
using namespace std;
const int base[2] = {31, 37};
const int mod[2] = {(int)1e9+7, (int)1e9+9};
const int mxn = 1e5+5;
#define ll long long
ll power[mxn][2];

void pre() {
    power[0][0] = power[0][1] = 1;
    for(int i=1;i<mxn;++i) {
        power[i][0] = (power[i-1][0]*base[0])%mod[0];
        power[i][1] = (power[i-1][1]*base[1])%mod[1];
    }
}
int calc(char str[]) {
    ll fhash1 = 0, fhash2 = 0,bhash1 = 0, bhash2 = 0;
    int len = strlen(str), pos=0;
    for(int i=len-1;i>=0;--i) {
        fhash1 = (fhash1 * base[0] + str[i])%mod[0];
        fhash2 = (fhash2 * base[1] + str[i])%mod[1];
        bhash1 = (bhash1 + power[len-1-i][0] * str[i])%mod[0];
        bhash2 = (bhash2 + power[len-1-i][1] * str[i])%mod[1];
        pair<ll,ll> a = {fhash1, fhash2};
        pair<ll,ll> b = {bhash1, bhash2};
        if(a == b) pos = i;
    }
    return pos-1;
}
int main() {
    int a,b,n;
    char str[mxn];
    pre();
    while(scanf("%s",str) != EOF) {
        int idx = calc(str);
        printf("%s",str);
        for(int i=idx;i>=0;--i) putchar(str[i]);
        puts("");
    }
    return 0;
}

/*
aaaa
abba
amanaplanacanal
xyz
*/