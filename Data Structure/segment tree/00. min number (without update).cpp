#include<iostream>
using namespace std;
const int mxn=1e5+5;
int arr[mxn];
int tree[4*mxn];

void init(int n, int l, int r) {
	if(l==r) {
		tree[n]=arr[l]; return;
	}
	int mid=l+(r-l)/2;
	init(n*2,l,mid);
	init(n*2+1,mid+1,r);
	tree[n]=min(tree[n*2],tree[n*2+1]);
}
int query(int n,int l,int r,int s, int e) {
	if(l>r) return 0;
	if(l==s && r==e) return tree[n];
	int mid=l+(r-l)/2;
	if(e<=mid) return query(2*n,l,mid,s,e);
	else if(s>mid) return query(2*n+1,mid+1,r,s,e);
	else {
		return min(query(n*2,l,mid,s,mid),query(n*2+1,mid+1,r,mid+1,e));
	}
}
int main() {
	int a,b,n,q,T,cas=0;
	scanf("%d",&T);
	while(T--) {
		scanf("%d %d",&n,&q);
		for(int i=1;i<=n;++i) scanf("%d",&arr[i]);
		init(1,1,n);
		printf("Scenario #%d:\n",++cas);
		for(int i=1;i<=q;++i) {
			scanf("%d %d",&a,&b);
			printf("%d\n",query(1,1,n,a,b));
		}
	}
}

/*
2
5 3
1 2 3 4 5
1 5
1 3
2 4
5 3
1 -2 -4 3 -5
1 5
1 3
2 4
*/