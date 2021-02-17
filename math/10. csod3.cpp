//commulative sum of divisors LOJ-1098,UVA-10830
#include<iostream>
#include<cmath>
using namespace std;
#define ll long long

ll csod(int n) {
	long long s=0;
	int m=sqrt(n);
	for(int i=2;(ll)i*i<=n;++i) { //when i=1, it counts 1 and the number itself as a divisor. eg. for 25, 1 and 25 are also divisors.
		ll t1=n/i;
        s+=(t1-1)*i;
        if(t1>m) {  //It should be possible without judgment. After all, t1 must be greater than or equal to m, and even if it is equal to m, it will not affect the result.
            s+=(m+1+t1) * (t1-m)/2; //Summation formula
        }
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
https://www.itread01.com/content/1544490366.html
I will not say the meaning of the topic, I understand it very well. 
The first thing I saw at the beginning of the question was whether I wanted to run the factors of each number and then sum it up. It was a great idea, but the time was too complicated.

Then think about it, we can consider from the perspective of the contribution of each number (the name we picked up). 
The specific idea is that the number of each 1~n is considered several times. For example, we need to find the contribution of 2 when n==10, and the number of 2 is 2, 4, 6, 8, 10, 
so 2 is calculated 4 times when calculating the final answer (2 Not counting, because 2 itself does not count the factor of 2 in this question), 
so for a number i, its contribution is also (n / i - 1) * i. Ok, this method can be said to be very good, 
unfortunately, it is still impossible to pass n is 1e9 information. Then we can consider optimization, if the time complexity can be reduced to sqrt(n) is almost enough.

Then we can go to sqrt(n), then there will be a lot of statistics, what should we do? ? ? Don't worry, and listen to me slowly, 
for a number i, we consider 2 * i, 3 ​​* i, 4 * i, ....... and so on (n / i - 1) * i It's okay, we are counting i, don't know if you have noticed the factors of these numbers and there are 2, 3, 4, ......., etc.,
that is 2 * i, 3 ​​* i , ... These numbers have 2, 3, 4.... these factors in addition to i (should be very clear, I hope you can understand...). 
The key is these factors, you may want to count these when i == 2, i == 3, i == 4, yes, but these may exceed sqrt(n) (should be certain There will be more than sqrt(n), which will happen for every i).

Let's take a look at the idea. We run from 2 to sqrt(n) and calculate the contribution of each i, ie: ( n / i - 1) * i, and we consider the number with i as a factor. 
Another factor k, if k <= sqrt(n) is calculated when calculating the contribution of the following numbers, then k >= sqrt(n) needs to be calculated again, 
we have to calculate The range of k is sqrt(n) + 1 ~ n / i (because there are at most n / i i in the number less than n), 
and these numbers are still equal to the number of columns, the tolerance is 1, the direct summation formula is just fine. .

Before I did this question, I found that the solution was not detailed. I didn’t understand it for a long time, so I tried to write it in detail, hoping to help the reader. .
*/