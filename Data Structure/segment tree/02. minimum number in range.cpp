#include<iostream>
#include<climits>
#include<cstdio>
using namespace std;
#define mxn 100005
int arr[mxn],tree[4*mxn];

void init(int node,int a,int b) {
	if(a==b) {
		tree[node]=arr[a]; return;
	}
	int l=node*2, r=node*2+1, mid=(a+b)/2;
	init(l,a,mid);
	init(r,mid+1,b);
	tree[node]=min(tree[l],tree[r]);
}
int query(int node,int a, int b, int i, int j) {
	if(a>j || b<i || i>j) return INT_MAX;
	if(a>=i && b<=j) return tree[node];
	int l=node*2, r=node*2+1, mid=(a+b)/2;
	int p1=query(l,a,mid,i,j);
	int p2=query(r,mid+1,b,i,j);
	return min(p1,p2);
}
void update(int node,int a,int b,int pos,int newval) {
	if(a>pos || b<pos) return;
	if(a>=pos && b<=pos) { //a==b
		tree[node]=newval; return;
	}
	// if(a==b) {
	// 	tree[node]=newval; return;
	// }
	int l=node*2, r=node*2+1, mid=(a+b)/2;
	update(l,a,mid,pos,newval);
	update(r,mid+1,b,pos,newval);
	tree[node]=min(tree[l],tree[r]);
}

int main() {
	int a,b,n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&arr[i]);;
	init(1,1,n);
	printf("%d\n",query(1,1,n,1,n));
	update(1,1,n,2,-1);
	printf("%d\n",query(1,1,n,1,3));
	return 0;
}

/*
7
4 -9 3 7 1 0 2
*/