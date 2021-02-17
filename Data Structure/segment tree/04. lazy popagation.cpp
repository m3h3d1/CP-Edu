//spoj HORRIBLE - Horrible Queries
#include<iostream>
#include<cstring>
using namespace std;
#define mxn 100005
#define ll long long
struct info {
	long long prop,sum;
} tree[mxn*4];

long long query(long long node,long long l,long long r,int i, int j,long long carry=0) {
	if(l>j || r<i) return 0;
	if(l>=i && r<=j) {
		return tree[node].sum + (r-l+1)*carry;
	}
	long long a=node*2,b=node*2+1,mid=(l+r)/2;
	long long p1=query(a,l,mid,i,j,carry+tree[node].prop);
	long long p2=query(b,mid+1,r,i,j,carry+tree[node].prop);
	return p1+p2;
}
void update(long long node,long long l,long long r,int i,int j,int x) {
	if(l>j || r<i) return;
	if(l>=i && r<=j) {
		tree[node].prop+=x;
		tree[node].sum+=(r-l+1)*x;
		return;
	}
	long long a=node*2,b=node*2+1,mid=(l+r)/2;
	update(a,l,mid,i,j,x);
	update(b,mid+1,r,i,j,x);
	tree[node].sum=(r-l+1)*tree[node].prop + tree[a].sum+ tree[b].sum;
}
int main() {
	int n,m,T,p,q,v,x,cas=0;
	scanf("%d",&T);
	while(T--) {
		memset(tree,0,sizeof(tree));
		//printf("Case %d:\n",++cas);
		scanf("%d %d",&n,&m);
		while(m--) {
			scanf("%d %d %d",&x,&p,&q);
			//p++,q++;
			if(!x) {
				scanf("%d",&v);
				update(1,1,n,p,q,v);
			}
			else {
				long long res=query(1,1,n,p,q);
				printf("%lld\n",res);
			}
		}
	}
	return 0;
}

/*
1
8 6
0 2 4 26
0 4 8 80
0 4 5 20
1 8 8 
0 5 7 14
1 4 8
*/