#include<iostream>
using namespace std;
const int mxn=1e3+5;
int arr[mxn],tree[4*mxn];

void build(int n,int tl,int tr) {
	if(tl==tr) {
		tree[n]=arr[tl]; return;
	}
	int tm=(tl+tr)/2;
	build(n*2,tl,tm);
	build(n*2+1,tm+1,tr);
	tree[n]=0; //initialization of prop node
}
int query(int n,int tl,int tr,int pos) {
	if(tl==tr) return tree[n]; //leaf node
	int tm=(tl+tr)/2;
	if(pos<=tm) return tree[n]+query(n*2,tl,tm,pos); //t[n] hoiche prop node
	else return tree[n]+query(n*2+1,tm+1,tr,pos); 
}
void update(int n,int tl,int tr,int l,int r,int newval) {
	if(l>r) return;
	if(l==tl && r==tr) tree[n]+=newval; //(prop node) ei range er vitor sobgular value ei node a add kora hoiche
	else {
		int tm=(tl+tr)/2;
		update(n*2,tl,tm,l,min(r,tm),newval);  //durer duitar min (mone rakhar jonno)
		update(n*2+1,tm+1,tr,max(l,tm+1),r,newval); //kacher duitar max (mone rakhar jonno)
	}
}
int main() {
	int a,b,n,q;
	cin>>n;
	for(int i=1;i<=n;++i) cin>>arr[i];
	build(1,1,n);
	for(int i=1;i<=n;++i) cout<<query(1,1,n,i)<<" ";
	cout<<endl;
	update(1,1,n,3,6,1);
	for(int i=1;i<=n;++i) cout<<query(1,1,n,i)<<" ";
	cout<<endl;
	return 0;
}

/*
10
1 2 3 4 5 6 7 8 9 0
*/

/*
cp-algorithms.com

Addition on segments:
We begin by considering problems of the simplest form: the modification query should add a number x to all numbers in the segment a[l…r]. 
The second query, that we are supposed to answer, asked simply for the value of a[i].

To make the addition query efficient, we store at each vertex in the Segment Tree how many we should add to all numbers in the corresponding segment. 
For example, if the query "add 3 to the whole array a[0…n−1]" comes, then we place the number 3 in the root of the tree. 
In general we have to place this number multiple to multiple segments, which form a partition of the query segment. 
Thus we don't have to change all O(n) values, but only O(logn) many.

If now there comes a query that asks the current value of a particular array entry, it is enough to go down the tree and add up all values found along the way.
*/