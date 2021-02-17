#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define db(x) cerr<<__LINE__<<": "<<#x<<" = "<<(x)<<'\n'
const int N = 1e6;
int A[N];

ll sumXOR(int n) {
    ll res = 0;
    for(int i=0;i<32;++i) {
        int cntO=0, cntZ=0;
        for(int j=0;j<n;++j) {
            if(A[j] & (1<<i)) cntO++; // check if i_th bit is set
            else cntZ++;
        }
        ll p = (ll) cntZ * cntO; // total number of pairs
        res += p * (1<<i);
    }
    return res;
}
int main() {
    ios_base::sync_with_stdio(0);
    int a,b,n,T,cas=0;
    cin>>n;
    for(int i=0;i<n;++i) cin>>A[i];
    ll sum = sumXOR(n);
    cout<<sum<<endl;
    return 0;
}

/*
4
5 9 7 6
*/

/*
https://www.youtube.com/watch?v=7mDzRRug9Sg
https://www.geeksforgeeks.org/sum-xor-pairs-array/
*/
/*
For example, look at the rightmost bit of all the numbers in the array. Suppose that a numbers have a rightmost 0-bit, and b numbers have a 1-bit. Then out of the pairs, a*b of them will have 1 in the rightmost bit of the XOR. This is because there are a*b ways to choose one number that has a 0-bit and one that has a 1-bit. These bits will therefore contribute a*b towards the total of all the XORs.

In general, when looking at the nth bit (where the rightmost bit is the 0th), count how many numbers have 0 (call this an) and how many have 1 (call this bn). The contribution towards the final sum will be an*bn*pow(2,n). You need to do this for each bit and sum all these contributions together.

This can be done in O(kn) time, where k is the number of bits in the given values.

Explanation :  arr[] = { 7, 3, 5 }
7 = 1 1 1
3 = 0 1 1
5 = 1 0 1
For bit position 0 : 
Bits with zero = 0
Bits with one = 3
Answer = 0 * 3 * 2 ^ 0 = 0
Similarly, for bit position 1 :
Bits with zero = 1
Bits with one = 2
Answer = 1 * 2 * 2 ^ 1 = 4
Similarly, for bit position 2 :
Bits with zero = 1
Bits with one = 2
Answer = 1 * 2 * 2 ^ 2 = 8
 Final answer = 0 + 4 + 8 = 12 
 */