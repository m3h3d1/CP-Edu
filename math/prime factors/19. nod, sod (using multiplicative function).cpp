#include<iostream>
#include<cmath>
#include<ctime>
using namespace std;
#define ll long long
const int mxn = 2e7+5;

int bigPrime[mxn+7];
int t[mxn+7];
ll sigma[mxn+7];
void precal() {
	t[1] = sigma[1] = 1;

	int root = sqrt(mxn);
	for(int i=2; i<=mxn; ++i) {
		if(bigPrime[i] == 0) {
			bigPrime[i] = i;
			if(i>root) continue;
			for(int j = i*i; j<=mxn; j+=i) {
				bigPrime[j] = i;
			}
		}
	}

	for(int i=2; i<=mxn; ++i) {
		int p = bigPrime[i], a = 0;
		int pa = bigPrime[i], tmp = i;
		while(tmp % p == 0) {
			tmp /= p;
			a++;
			pa *= p;
		}
		t[i] = (a+1) * t[tmp];
		sigma[i] = (pa-1) / (p-1) * sigma[tmp];
	}
}

int main() {
		time_t tim;
		tim = clock();
	precal();
		tim = clock() - tim;
		cout<<(double)tim/1000<<" sec"<<endl;

	int n;
	while(cin>>n) {
		cout << t[n] << " " << sigma[n] << endl;
	}
	return 0;
}

/*
0
1
3
6
100
*/

/*
Among the number theory functions t(n) and σ(n) both are very familiar and most of number theory enthusiast know the formula to calculate them for a given positive integer n. 
But What if we are asked to calculate t(n) and σ(n) for all positive integer from 1 to 10⁷ ?

	Definitions:
	t(n) is the number of positive divisors of n including the divisors 1 and n
	σ(n) is the sum of divisors of n, including the 1 and n.


t(n) and σ(n) are multiplicative and for this property we can use previous values of t(x) and σ(x) where x < n to calculate t(n) and σ(n). 
Lets depict few examples for integers:

	n = 10 = 2 x 5
	t(n) = t(2) x t(5)
	σ(n) = σ(2) x σ(5)

	n = 20 = 2^2 * 5 = 4 * 5
	t(n) = t(4) x t(5)
	σ(n) = σ(4) x σ(5)

	n = 120 = 2^3 * 3 * 5 = 24 * 5
	t(n) = t(24) x t(5)
	σ(n) = σ(24) x σ(5)

In the last example notice that finally we separated the big prime in prime factorization and merged the other prime factors together. 
Why? Because if we can separate at least one type of prime in prime factorization, 
the separated part and other part will be co prime and we can apply the multiplicative rule thereby. 
Lets explain by another value of n which a bit large value.

	n = 600 = 2^3 * 3 * 5^2
	x = 5^2        <- Part of big prime separated
	y = 2^3 * 3    <- The other part

	x and y must be co-prime. You got it now?
	t(n) = t(x) * t(y)
	σ(n) = σ(x) x σ(y)

https://medium.com/@iamcrypticcoder/calculate-t-n-and-%CF%83-n-up-to-10%E2%81%B7-efficiently-be3d198fe557
*/