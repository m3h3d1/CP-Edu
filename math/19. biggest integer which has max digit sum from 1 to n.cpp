#include<bits/stdc++.h>
using namespace std;

int digitSum(int a) {
	int sum = 0;
	while(a) {
		sum += a%10;
		a /= 10;
	}
	return sum;
}
int findmax(int x) {
	int b = 1, ans = x;
	while(x) {
		int cur = (x-1) * b + (b-1);
		if(digitSum(cur) > digitSum(ans)) {
			ans = cur;
		}
		x /= 10;
		b *= 10;
	}
	return ans;
}
int main() {
	int a,b,n,T,cas=0;
	while(cin>>n) {
		cout<<findmax(n)<<endl;
	}
	return 0;
}

/*
100
48
11
*/

/*
if (sumOfDigits(cur) > sumOfDigits(ans) ||  
           (sumOfDigits(cur) == sumOfDigits(ans) &&  
            cur > ans)) 
            ans = cur; 
*/

/*
https://www.geeksforgeeks.org/biggest-integer-maximum-digit-sum-range-1-n/

We use (x – 1) * b + (b – 1); 
This line can further be explained as, if the number is x = 521 and b = 1, then

(521 – 1) * 1 + (1-1) which gives you 520, which is the thing we need to do, reduce the position number by 1 and replace all other numbers to the right by 9.
After x /= 10 gives you x as 52 and b*=10 gives you b as 10, which is again executed as (52-1)*(10) + 9 which gives you 519, which is what we have to do, reduce the current index by 1 and increase all other rights by 9.
*/