#include<iostream>
using namespace std;
#define mxn 100
int arr[mxn],tree[mxn*4];

void init(int node,int a,int b) {
	//if(a>b) return;
	if(a==b) {
		tree[node]=arr[a]; return;
	}
	int l=node*2, r=node*2+1, mid=a+(b-a)/2;
	init(l,a,mid);
	init(r,mid+1,b);
	tree[node]=tree[l]+tree[r];
}
int query(int node,int a,int b,int i,int j) {
	if(a>j || b<i) return 0; //out of range
	if(a>=i && b<=j) return tree[node]; //relevent segment
	//node to be broken more
	int l=node*2, r=node*2 + 1, mid=a+(b-a)/2;
	int p1=query(l,a,mid,i,j);
	int p2=query(r,mid+1,b,i,j);
	return p1+p2;
}
void update(int node,int a,int b,int i,int newval) {
	if(a>i || b<i) return;
	if(a>=i && b<=i) {
		tree[node]=newval; return;
	}
	int l=node*2,r=node*2+1,mid=a+(b-a)/2;
	update(l,a,mid,i,newval);
	update(r,mid+1,b,i,newval);
	tree[node]=tree[l]+tree[r];
}

int main() {
	int a,b,n;
	cin>>n;
	for(int i=1;i<=n;++i) cin>>arr[i];
	init(1,1,n);
	cout<<query(1,1,n,1,3)<<endl;
	update(1,1,n,2,0);
	cout<<query(1,1,n,1,3)<<endl;
	update(1,1,n,2,2);
	cout<<query(1,1,n,2,2)<<endl;
	return 0;
}

/*
7
4 -9 3 7 1 0 2
*/