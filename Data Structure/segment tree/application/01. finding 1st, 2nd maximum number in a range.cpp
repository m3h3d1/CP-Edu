#include<iostream>
#include<algorithm>
using namespace std;
const int mxn=2e5+5;
struct Data{
	int x1,x2;
};
int arr[mxn];
Data tree[mxn*4];

void build(int n,int tl,int tr) {
	if(tl==tr) {
		tree[n].x1=arr[tl]; tree[n].x2=-1; return;
	}
	int tm=(tl+tr)/2;
	build(n*2,tl,tm);
	build(n*2+1,tm+1,tr);
	//t[n]=0;
	int temp[]={tree[n*2].x1,tree[n*2].x2,tree[n*2+1].x1,tree[n*2+1].x2};
	sort(temp,temp+4,[](int x,int y)->bool {return x>y;});
	tree[n].x1=temp[0]; tree[n].x2=temp[1];
}
Data query(int n,int tl,int tr,int l,int r) {
	if(tl==l && tr==r) return tree[n];
	int tm=(tl+tr)/2;
	if(r<=tm) return query(n*2,tl,tm,l,r);
	else if(l>tm) return query(n*2+1,tm+1,tr,l,r);
	else {
		Data a=query(n*2,tl,tm,l,min(tm,r));
		Data b=query(n*2+1,tm+1,tr,max(tm+1,l),r);
		int temp[]={a.x1,a.x2,b.x1,b.x2};
		sort(temp,temp+4,[](int x,int y)->bool {return x>y;});
		Data c;
		c.x1=temp[0], c.x2=temp[1];
		return c;
	}
}
void update(int n,int tl,int tr,int pos, int newval) {
	if(tl==tr) {
		tree[n].x1=newval; tree[n].x2=-1;
		return;
	}
	int tm=(tl+tr)/2;
	if(pos<=tm) update(n*2,tl,tm,pos,newval);
	else update(n*2+1,tm+1,tr,pos,newval);

	int temp[]={tree[n*2].x1,tree[n*2].x2,tree[n*2+1].x1,tree[n*2+1].x2};
	sort(temp,temp+4,[](int x,int y)->bool {return x>y;});
	tree[n].x1=temp[0], tree[n].x2=temp[1];
}
int main() {
	int a,b,n,T,q;
	char ch;
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&arr[i]);
	build(1,1,n);
	scanf("%d",&q);
	for(int i=1;i<=q;++i) {
		getchar();
		scanf("%c %d %d",&ch,&a,&b);
		if(ch=='Q') {
			Data x=query(1,1,n,a,b);
			printf("%d %d\n",x.x1,x.x2);
		}
		else update(1,1,n,a,b);
	}
	return 0;
}

/*
5
1 2 3 4 5
6
Q 2 4
Q 2 5
U 1 6
Q 1 5
U 1 7
Q 1 5
*/

/*
similar to, spoj KGSS - Maximum Sum

Update:
This will be indicated in the input by a 'U' followed by space and then two integers i and x.

U i x, 1 ≤ i ≤ N, and x, 0 ≤ x ≤ 10^8.

This operation sets the value of A[i] to x.

Query:
This will be indicated in the input by a 'Q' followed by a single space and then two integers i and j.

Q x y, 1 ≤ x < y ≤ N.
*/