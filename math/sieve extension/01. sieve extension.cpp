#include<bits/stdc++.h>
using namespace std;

void divisorSieve(int n) {
    int divisor[n+1];
    for(int i=1;i<=n;++i) {
        for(int j=1;j<=n;j+=i) ++divisor[j];
    }
    //O(n logn) for n = 10^7 runs for approximately 1.700s on a normal computer, and even faster on online judges that do cloud computing.
}
void sumOfDivisors(int n) {
    int sumdiv[n+1];
    for(int i=1;i<=n;++i) {
        for(int j=i;j<=n;j+=i) sumdiv[j] += i;
    }
}
void EulerTotient(int n) { //phi
    int totient[n+1];
    for(int i=1;i<=n;++i) totient[i] = i;
    for(int i=2;i<=n;++i) {
        if(totient[i]==i) {
            for(int j=i;j<=n;j+=i) {
                totient[j] -= totient[j]/i;
            }
        }
    }
}
void biggestPrimeDivisor(int n) {
    int big[n+1] = {0,1};
    for(int i=2;i<=n;++i) {
        if(!big[i]) {
            for(int j=i;j<=n;j+=i) big[j] = i;
        }
    }
    for(int i=1;i<=n;++i) printf("%d ", big[i]);
}


int main() {
    int a,b,n,T,cas=0;
    //for(int i=0;i<5;++i) printf("%d\n", A[i]);
    biggestPrimeDivisor(10);
    return 0;
}


/*
Euler Phi:
    # Few properties of phi function :
a). phi(p) = p - 1. Where p is prime. All the numbers from 1 to p - 1 are coprime to p.
b). phi(a * b) = phi(a) * phi(b) where a and b are coprime.
c). phi(p^k) = p^k - p^(k - 1). Note that here ^ denotes power. Here all the numbers from 1 to p^k are coprime to p^k except all the multiples of p, which are exactly p^(k -1).

Method for finding:
Simple : For all numbers from 1 to n, check if it is coprime to n or not, If yes add that to your answer.
Let us say your number is n, which can be denoted as p1^k1 * p2^k2 ..... *p_m*k_m. Note that here p1, p2.... pm are prime. Basically n is written in it's prime representation.
Then phi(n) would be [ p1^k1 - (p1^(k1-1) ) ] * ....... [p_m^k_m - (p_m^(k_m-1) )] . The expression for n can also be written as p1^k1 * p2^k2 * .... * p_m^k_m * (1 - 1/p1) * (1 - 1/p2) .... * (1 - 1/pm).
which is equal to n * (1 — 1/p1) * (1 — 1/p2) .... * (1 — 1/p_m).

Now Let us calculate value of sieve of all numbers from 1 to N:
Let us say eulerPhi[i] be the value of phi(i). Assign initially all the values of eulerPhi[i] to be i. 
Then for every prime p, for all multiples of p, we will multiply value of eulerPhi[i] by (1 - 1/p) as per the formula. 
multiplying eulerPhi[i] by (1 - 1/p) is exactly equal to eulerPhi[i] -= (eulerPhi[i] / p).
*/

//https://codeforces.com/blog/entry/8989