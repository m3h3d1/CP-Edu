#include<bits/stdc++.h>
using namespace std;

int bs(vector<int>& v, int x) {
	if(v.size()==0) return -1;
	int l=0, r=v.size()-1;
	while(l<=r) {
		int mid = l+(r-l)/2;
		if(v[mid] == x) return mid;
		else if(v[mid] < x) l = mid+1;
		else r = mid-1;
	}
	return -1;
}
int main() {
	vector<int> v{1, 2, 4, 7, 9};
	cout<<bs(v, 9)<<endl;
	return 0;
}