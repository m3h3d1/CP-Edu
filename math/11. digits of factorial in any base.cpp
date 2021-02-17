#include<iostream>
#include<cmath>
using namespace std;

const int mxn=1e6+5;
double dig[mxn];
void pre() {
	double res=0;
	for(int i=1;i<mxn;++i) {
		res+=log10(i);
		dig[i]=res;
	}
}
int main() {
	pre();
	int n,T,base,cas=0;
	scanf("%d",&T);
	while(T--) {
		scanf("%d %d",&n,&base);
		int x=floor(dig[n]/log10(base))+1;
		printf("Case %d: %d\n",++cas,x);
	}
	return 0;
}

/*
Factorial of an integer is defined by the following function
f(0) = 1
f(n) = f(n - 1) * n, if(n > 0)
So, factorial of 5 is 120. But in different bases, the factorial may be different. For example, factorial of 5 in base 8 is 170.
In this problem, you have to find the number of digit(s) of the factorial of an integer in a certain base.

Input
Input starts with an integer T (≤ 50000), denoting the number of test cases.
Each case begins with two integers n (0 ≤ n ≤ 106) and base (2 ≤ base ≤ 1000). Both of these integers will be given in decimal.

Output
For each case of input you have to print the case number and the digit(s) of factorial n in the given base.

Sample Input
5
5 10
8 10
22 3
1000000 2
0 100

Sample Output
Case 1: 3
Case 2: 5
Case 3: 45
Case 4: 18488885
Case 5: 1
*/