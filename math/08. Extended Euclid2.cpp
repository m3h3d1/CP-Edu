#include<bits/stdc++.h>
using namespace std;

int egcd(int a, int b, int &x, int &y) {
    if(b==0) {
        x=1, y=0;
        return a;
    }
    int x1, y1;
    int g = egcd(b, a%b, x1, y1);
    x = y1;
    y = x1 - (a/b)*y1;
    return g;
}
int main() {
    int a,b,n,T,cas=0;
    while(cin>>a>>b) {
        int x, y;
        int g = egcd(a,b,x,y);
        cout<<x<<" "<<y<<" "<<g<<'\n';
    }
    return 0;
}

/*
4 6
17 17
*/