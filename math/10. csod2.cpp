//commulative sum of divisors LOJ-1098,UVA-10830
#include<iostream>
using namespace std;
#define ll long long

ll csod(int n) {
	long long s=0;
	for(int i=2;(ll)i*i<=n;++i) { //when i=1, it counts 1 and the number itself as a divisor. eg. for 25, 1 and 25 are also divisors.
		s+=i; // This factor satisfies 
        ll e=i+1 ; // The previous statistics have been pushed back 
        ll j=n/i; // How many 
        if(e>j) continue ;
        s+=(j-e+1)*i; // This factor appears several times 
        s+=(j-e+1)*(e+j)/ 2 ; // factor corresponds to another factor series summation
	}
	return s;
}
int main() {
	int a,b,n,T,cas=0;
	cin>>T;
	while(T--) {
		cin>>n;
		ll res=csod(n);
		printf("Case %d: %lld\n",++cas,res);
	}
	return 0;
}

/*
3

1
3
1000
*/

/*
https://www.itread01.com/content/1508752573.html
Find a factor corresponding to this factor by a factor, and sum;
For example, when n=20, when the factor is 2, the corresponding 2(4), 3(6), 4(8), 5(10), 6(12), 7(14), 8(16), 9(18), 10(20)
When it is 3, the corresponding is 2 (6), 3 (9), 4 (12), 5 (15), 6 (18)
At this time, you should pay attention to avoid duplication between 2 and 3 when calculating.
*/