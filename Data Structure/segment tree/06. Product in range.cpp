#include<iostream>
using namespace std;
const int mxn=1e5+5;
int arr[mxn],tree[mxn*4];

int query(int v,int tl,int tr,int l,int r) {
	if(l>r) return 1;
	if(tl==l && tr==r) return tree[v];
	int tm=(tl+tr)/2;
	if(r<=tm) return query(v*2,tl,tm,l,r);
	else if(l>tm) return query(v*2+1,tm+1,tr,l,r);
	else {
		int a=query(v*2,tl,tm,l,tm);
		int b=query(v*2+1,tm+1,tr,tm+1,r);
		return a*b;
	}
}
void update(int v,int tl,int tr,int pos,int val) {
	if(tl==tr) {
		tree[v]=val;
		return;
	}
	int tm=(tl+tr)/2;
	if(pos<=tm) update(v*2,tl,tm,pos,val);
	else update(v*2+1,tm+1,tr,pos,val);
	tree[v]=tree[v*2]*tree[v*2+1];
}
int main() {
	int a,b,x,n,k;
	char ch;
	while(scanf("%d %d",&n,&k) != EOF) {
		for(int i=1;i<=n;++i) {
			scanf("%d",&x);
			update(1,1,n,i,x);
		}
		while(k--) {
			getchar();
			scanf("%c %d %d",&ch,&a,&b);
			if(ch=='C') update(1,1,n,a,b);
			else {
				printf("%d\n",query(1,1,n,a,b));
			}
		}
	}
	return 0;
}

/*
5 5
2 3 4 5 6
P 1 5
C 2 1
P 2 4
C 5 0
P 1 5
*/