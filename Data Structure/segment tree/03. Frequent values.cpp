//uva 11235 - Frequent values
//given a sequence of n integers a1,a2....an in non-decreasing order
#include<iostream>
#include<climits>
#include<cstring>
using namespace std;
#define mxn 200005
#define S 100000
int arr[mxn],start[mxn],cnt[mxn],tree[mxn*4];

void build(int node,int a,int b) {
	if(a==b) {
		tree[node]=cnt[arr[a]]; return;
	}
	int l=node*2,r=node*2+1,mid=(a+b)/2;
	build(l,a,mid);
	build(r,mid+1,b);
	tree[node]=max(tree[l],tree[r]);
}
int query(int node,int a,int b,int i,int j) {
	if(a>j || b<i) return INT_MIN;
	if(a>=i && b<=j) return tree[node];
	int l=node*2,r=node*2+1,mid=(a+b)/2;
	int p1=query(l,a,mid,i,j);
	int p2=query(r,mid+1,b,i,j);
	return max(p1,p2);
}
int main() {
	ios_base::sync_with_stdio(false);
	int n,q,a,b;
	while(cin>>n && n) {
		cin>>q;
		memset(start,-1,sizeof(start));
		memset(cnt,0,sizeof(cnt));
		for(int i=1;i<=n;++i) {
			cin>>arr[i];
			arr[i]+=S;
			cnt[arr[i]]++;
			if(cnt[arr[i]]==1) start[arr[i]]=i;
		}
		build(1,1,n);
		while(q--) {
			cin>>a>>b;
			if(arr[a]==arr[b]) {
				cout<<b-a+1<<endl; continue;
			}
			int r1=cnt[arr[a]]-(a-start[arr[a]]);
			int r2=b-start[arr[b]]+1;
			int res=max(r1,r2);
			int x=start[arr[a]]+cnt[arr[a]];
			int y=start[arr[b]]-1;
			if(x<=y) {
				int r3=query(1,1,n,x,y);
				res=max(res,r3);
			}
			cout<<res<<endl;
		}
	}
	return 0;
}

/*
3 4
-100000 -100000 100000
1 3
1 2
2 3

84 87
47 72 89 96 97 97 98 99 99 100 100 100 100 100 100 100 100 100 100 100 100 100 100 100 100 100 100 100 100 100 
100 100 100 100 100 100 100 100 100 100 100 100 100 100 100 100 100 100 100 100 100 100 100 100 100 100 100 100 100 
100 100 100 100 100 100 100 100 100 100 100 100 100 100 100 100 100 100 100 100 100 100 100 100 100
1 8
*/

/*
http://niceproblems.blogspot.com/2012/05/uva-11235-frequent-values.html

Solving this problem requires knowledge of Range Minimum Query ( RMQ ) Given a list of N non-descending integers and Q queries of type ( i, j ) 
the problem requires to find the maximum frequency of the numbers in the range [i,j].

Let,
vector v store the input numbers
vector count  store the frequency of each input numbers , and
vector start store the index of the input list where a particular input number first appeared.

For example ,
 v = { 1, 1, 2, 2, 2, 3, 4, 5, 5 }
count = { 2, 2, 3, 3, 3, 1, 1, 2, 2 }
start = { 0, 0, 2, 2, 2, 5, 6, 7, 7 }

A segment tree is constructed where node would store the value of the maximum count of its respective range [ a,b ].

There are two cases that can occur :
1. the value of the numbers at index i and j are same , i.e v[ i ] = v[ j ].
2. the value of the numbers at index i and j are different , v[ i ] ≠ v[ j ].

Case 1:
Solving this case is easy. Since v[ i ] = v[ j ] , all the numbers in the range [ i,j ] are same ( since the numbers are non-descending ). 
The answer for case 1 is j - i + 1.

Case 2:
If v[ i ] ≠ v[ j ] then there exist an index k where v[ i ] = v[ k ] and v[ i ] ≠ v[ k + 1 ]. The value of k is
start[ v[ i ] ] + count[ v[ i ] ] - 1.
The frequency of the value v[ i ] in the range [i,k] , cnt1 = count[ v[ i ] ] - start[ v[ i ] ] + i
Frequency of v[ j ] in the range [i,j], cnt2  = j - start[ v[ j ] ] + 1

The maximum frequency of the values in range [ i,j ] may in fact exists in the range [ k + 1, start[ j ] - 1 ] and can be found by 
querying the segment tree for the maximum value in the range [ k + 1, start[ j ] - 1 ]. 
Let the maximum count returned by the query be cnt3.

Therefore the answer for case2 = max ( cnt1, cnt2 , cnt3 ) .
*/