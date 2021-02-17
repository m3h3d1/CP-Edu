#include<iostream>
using namespace std;

int check(int n) {
	int res=0;
	while(n!=0) {
		res+=n/5;
		n/=5;
	}
	return res;
}
int bslower(int q,int l,int r) {
	int res=-1;
	while(l<=r) {
		int mid=l+(r-l)/2;
		int x=check(mid);
		if(x<q) {
			l=mid+1;
		}
		else if(x==q) {
			res=mid;
			r=mid-1;
		}
		else r=mid-1;
	}
	return res;
}
int main() {
	int n,T,q,cas=0;
	cin>>T;
	while(T--) {
		cin>>q;
		printf("Case %d: ",++cas);
		int r=bslower(q,5,5*q);
		if(r==-1) cout<<"impossible"<<endl;
		else cout<<r<<endl;
	}
	return 0;
}

/*
lightoj 1138
3

1
2
5
*/

/*
Let us take few examples to observe pattern

5!  has 1 trailing zeroes 
[All numbers from 6 to 9
 have 1 trailing zero]

10! has 2 trailing zeroes
[All numbers from 11 to 14
 have 2 trailing zeroes]

15! to 19! have 3 trailing zeroes

20! to 24! have 4 trailing zeroes

25! to 29! have 6 trailing zeroes
We can notice that, the minimum value whose factorial contain n trailing zeroes is 5*n.

So, to find minimum value whose factorial contains n trailing zeroes, use binary search on range from 0 to 5*n. And, find the smallest number whose factorial contains n trailing zeroes.
*/

/*
+-------+-----+
| count | N   |
+-------+-----+
| 1     | 5   |
+-------+-----+
| 2     | 10  |
+-------+-----+
| 3     | 15  |
+-------+-----+
| 4     | 20  |
+-------+-----+
| 6     | 25  |
+-------+-----+
| 7     | 30  |
+-------+-----+
| 8     | 35  |
+-------+-----+
| 9     | 40  |
+-------+-----+
| 10    | 45  |
+-------+-----+
| 12    | 50  |
+-------+-----+
| ...   | ... |
+-------+-----+
| 28    | 120 |
+-------+-----+
| 31    | 125 |
+-------+-----+
| 32    | 130 |
+-------+-----+
| ...   | ... |
+-------+-----+
*/