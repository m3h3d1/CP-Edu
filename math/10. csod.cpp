//commulative sum of divisors LOJ-1098,UVA-10830
#include<iostream>
using namespace std;
#define ll long long

ll csod(int n) {
	long long s=0;
	for(int i=2;(ll)i*i<=n;++i) { //when i=1, it counts 1 and the number itself as a divisor. eg. for 25, 1 and 25 are also divisors.
		int j=n/i;
		s+=(ll) (j+i)*(j-i+1)/2;
		s+=(ll) i*(j-i); //For first i numbers less than sqrt(n)
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
http://rizoantoufiq.blogspot.com/2015/12/lightoj-1098-new-function.html
P=25

 1:
 2:
 3:
 4: 2
 5:
 6: 2 3
 7:
 8: 2 4
 9: 3
10: 2 5
11:
12: 2 3 4 6
13:
14: 2 7
15: 3 5
16: 2 4 8
17:
18: 2 3 6 9
19:
20: 2 4 5 10
21: 3 7
22: 2 11
23:
24: 2 3 4 6 8 12
25: 5
total: 173

Given Number P = 25, i = 2 , j= P/i = 12
From above calculation, we can find out two relations
First Relation
2+3+4+5+6+7+8+9+10+11+12 
= 1+2+3+4+5+6+7+8+9+10+11+12-1  
= j*(j+1)/2 - (i-1)*(i-1+1)/2   
= j*(j+1)/2 - (i-1)*(i)/2
= (j^2+j - i^2 + i)/2
= ((j-i)(j+i)+(j+i))/2
= ((j+i)(j-i+1))/2  (General Form)
= (14 * 11 )/2 = 77

Second Relation
2x10 = i*(j-i)  (General Form)
     = 20

Again
 i  = 3 ,  j = P/i = 8

First Relation
3+4+5+6+7+8 
= (1+2+3+4+5+6+7+8) - (1+2) 
= (j*(j+1)/2 - (i-1)*(i-1+1)/2
= ((j+i)(j-i+1))/2  (General Form)
= (11 * 6 )/2 = 33

Second Relation
3x5 = i*(j-i)
    = 15

Again
 i  = 4 ,  j = P/i = 6

First Relation
4+5+6 
= (1+2+3+4+5+6) - (1+2+3) 
= (j*(j+1)/2 - (i-1)*(i-1+1)/2
= ((j+i)(j-i+1))/2  (General Form)
= (10 * 3 )/2 = 15

Second Relation
4x2 = i*(j-i)
    = 8

Again
 i  = 5 ,  j = P/i = 5

First Relation
5 
= (1+2+3+4+5) - (1+2+3+4) 
= (j*(j+1)/2 - (i-1)*(i-1+1)/2
= ((j+i)(j-i+1))/2  (General Form)
= (10 * 1 )/2 = 5

Second Relation
5x0 = i*(j-i)
    = 0

SUM = 77+20+33+15+15+8+5+0 = 173
*/