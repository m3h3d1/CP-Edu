#include<bits/stdc++.h>
using namespace std;

int solve(int n, int r) {
    vector<int> prime;
    for(int i=2;i*i<=n;++i) {
        if(n%i==0) {
            prime.push_back(i);
            while(n%i==0) n /= i;
        }
    }
    if(n!=1) prime.push_back(n);

    int sum = 0;
    for(int msk=1;msk<(1<<prime.size());++msk) {
        int mult = 1, cnt = 0;
        for(int i=0;i<prime.size();++i) {
            if(msk & (1<<i)) {
                ++cnt;
                mult *= prime[i];
            }
        }
        int cur = r/mult;
        sum += cur*(cnt&1 ? 1:-1);
    }
    return r-sum;
}
int main() {
    int n,r;
    cin>>n>>r;
    int res = solve(n,r);
    cout<<res;
    return 0;
}

/*
2 12
(Answer: 1 3 5 7 9 11)

3 12
(Answer: 1 2 4 5 7 8 10 11)
*/

/*
Task: given two numbers n and r, count the number of integers in the interval [1;r] that are relatively prime to n (their greatest common divisor is 1).

Let's solve the inverse problem - compute the number of not mutually primes with n.

We will denote the prime factors of n as pi(i=1⋯k).

How many numbers in the interval [1;r] are divisible by pi? The answer to this question is: floor(r/Pi)

However, if we simply sum these numbers, some numbers will be summarized several times (those that share multiple pi as their factors). Therefore, it is necessary to use the inclusion-exclusion principle.

We will iterate over all 2^k subsets of Pis, calculate their product and add or subtract the number of multiples of their product.
*/