#include<iostream>
using namespace std;
#define ll long long
const int mxn = 2e7;
ll a, b, c;

ll f(ll x) {
	return ((a%c * x)%c + (x%b)%c)%c;
}
void cyclefind() {
	ll x1 = 1, x2 = 1; //x1->tortoise,, x2->hare
	int cnt = 0;
	do {
		x1 = f(x1);
		x2 = f(f(x2));
		cnt++;
	} while((x1 != x2) && (cnt<=mxn));
	
	if(x1 != x2) {
		printf("-1\n");
		return;
	}

	int lembda = 0; //cycle length
	do {
		x1 = f(x1);
		lembda++;
	} while(x1 != x2);

	x2 = 1;
	int miu = 0; //miu-> strting point
	while(x1 != x2) {
		x1 = f(x1);
		x2 = f(x2);
		miu++;
	}
	//cout<<lembda<<" "<<miu<<endl;
	if(miu+lembda <= mxn) cout<<miu+lembda<<endl;
	else printf("-1\n");
}
int main() {
	cin>>a>>b>>c;
	cyclefind();
	return 0;
}

/*
https://codeforces.com/gym/101252/problem/D

2 2 9

2305843009213693951 1 9223372036854775807

-2 1 5
*/

/*
In the first sample test the sequence starts with the following numbers: 1, 3, 7, 6, 3, 7. The first repeatable element is 3. The second occurence of 3 has index 4.

In the second sample test the sequence starts with the following numbers: 1, 2305843009213693951, -4611686018427387903, 6917529027641081855, 0, 0, 0. The first repeatable element is 0. The second occurence of 0 has index 5.

In the third sample test the sequence starts with the following numbers: 1, -2, 4, -3, 1, -2, 4. The first repeatable element is 1. The second occurence of 1 has index 4.
*/

/*
Input
The only line of input contains three signed 64-bit integers: A, B and C (B > 0, C > 0).

Output
Print a single integer  — the index of the second occurence of the first repeatable member if it is less or equal to 2·107. Print  - 1 if the index is more than 2·107.
*/