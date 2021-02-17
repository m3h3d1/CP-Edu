//sorted in ascending order
#include<bits/stdc++.h>
using namespace std;

int circularBS(vector<int>& v, int x) {
	int l=0, r=v.size()-1;
	while(l<=r) {
        int mid = (l+r)/2;
        if(v[mid] == x) return mid;
        if(v[l] <= v[mid]) { //check if left half is sorted
            if(v[l]<=x && v[mid]>x) //check key lies in A[l..mid]
                r = mid-1; //search in left sorted half
            else 
                l = mid+1; //search in right half
        }
        else {
            if(v[mid]<x && v[r]>=x) //check key lies in A[mid..r]
                l = mid+1; //search in right sorted half
            else 
                r = mid-1; //search in left half
        }
    }
    return -1;
}
int main() {
	int key;
	vector<int> v{9, 10, 2, 5, 6, 8};
	while(cin>>key) {
		int idx = circularBS(v, key);
		cout<<"    "<<idx<<endl;
	}
	return 0;
}