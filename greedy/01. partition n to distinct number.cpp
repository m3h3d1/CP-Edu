#include<bits/stdc++.h>
using namespace std;

vector<int> v;
int solve(int a, int b) {
	if(a>=b) return 0;
	v.push_back(a);
	int p = solve(a+1, b-(a+1));
	if(!p) v.push_back(b);
	return 1;
}
int main() {
	int n;
	cin>>n;
	if(n<=2) {
		printf("1\n%d\n", n);
		return 0;
	}
	solve(1, n-1);
	printf("%d\n", (int)v.size());
	for(int x: v) printf("%d ", x);
	printf("\n");
	return 0;
}

/*
10
1
15
24
*/