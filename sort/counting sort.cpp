#include<bits/stdc++.h>
using namespace std;

void count_sort(int A[], int n) {
	int mx = 0;
	for(int i=0;i<n;++i) {
		if(A[i]>mx) mx = A[i];
	}
	int cnt[mx+5]={0};
	for(int i=0;i<n;++i) cnt[A[i]]++;
	int j=0;
	for(int i=0;i<=mx;++i) {
		int tmp = cnt[i];
		while(tmp--) {
			A[j++] = i;
		}
	}
}
int main() {
	int a,b,n,T,cas=0;
	cin>>n;
	int A[n];
	for(int i=0;i<n;++i) cin>>A[i];
	count_sort(A, n);
	for(int i=0;i<n;++i) cout<<A[i]<<" ";
	return 0;
}

/*
7
5 2 9 5 2 3 5
*/