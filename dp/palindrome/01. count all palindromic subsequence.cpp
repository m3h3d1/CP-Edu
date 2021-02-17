#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define db(x) cerr<<__LINE__<<": "<<#x<<" = "<<(x)<<'\n'
const int N = 100;
ll mem[N][N];
string s;

ll dp(int l, int r) {
    if(l>r) return 0;
    if(l==r) return 1;
    if(mem[l][r]!=-1) return mem[l][r];
    if(s[l]!=s[r]) return mem[l][r] = dp(l+1, r) + dp(l, r-1) - dp(l+1, r-1);
    else return mem[l][r] = dp(l+1, r) + dp(l, r-1) + 1;
}
int main() {
    ios_base::sync_with_stdio(0);
    int a,b,n,T,cas=0;
    cin>>T;
    while(T--) {
        memset(mem, -1, sizeof(mem));
        cin>>s;
        ll res = dp(0, s.size()-1);
        cout<<res<<endl;
    }
    return 0;
}

/*
UVA 10617 - Again Palindrome

3
BAOBAB
AAAA
ABA
*/

/*
Pseudocode:
palindrome(i,j) :
if(i==j) return 1
if(char i == char j) return (1+palindrome(i+1,j)+palindrome(i,j-1)
else return ( palindrome(i+1,j) + palindrome(i,j-1) - palindrome(i+1,j-1) )

Understanding the code:
When first and last characters are not equal, we subtract palindrome(i+1,j-1) because this part was counted twice.
Do you notice we are not substracting when first and last characters are same?
consider abc=pal(ab)+pal(bc)-pal(b) ==3 ;
now aba=pal(ab)+pal(ba)+1:
pal(ab)=a+b=2 ;pal(ba)=b+a=2, here also b will be over-counted if we consider it alone, but what if we consider a(b)a (this has to be counted isn’t it ?)
*/