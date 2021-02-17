#include<iostream>
using namespace std;
int z,i,m;

int func(int L) {
	return ((z*L) + i)%m;
}
int cycle(int L) {
	int tortoise = L, hare = L;
	do {
		tortoise = func(tortoise);
		hare = func(hare);
		hare = func(hare);
	} while(tortoise != hare);
	int len=0;
	do {
		tortoise = func(tortoise);
		len++;
	} while(tortoise != hare);
	return len;
}
int main() {
	int L,cas=0;
	while(cin>>z>>i>>m>>L && (z || i || m || L)) {
		int res = cycle(L);
		printf("Case %d: %d\n",++cas,res);
	}
	return 0;
}

/*
http://shoshikkha.com/archives/4845

7 5 12 4
5173 3849 3279 1511
9111 5309 6000 1234
1079 2136 9999 1237
0 0 0 0
*/