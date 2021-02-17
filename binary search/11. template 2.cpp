#include<bits/stdc++.h>
using namespace std;

int bs(vector<int>& v, int x) {
	if(v.size() == 0) return -1;
	int l = 0, r = v.size();
	while(l<r) {
		int m = l+(r-l)/2;
		if(v[m] == x) return m;
		else if(v[m] < x) l = m+1;
		else r = m;
	}
	//post processing: l == r
	if(l != v.size() && v[l] == x) return l;
	return -1;
}
int main() {
	int a,b,n,T,cas=0;
	
	return 0;
}

/*
Template #2 is an advanced form of Binary Search. 
It is used to search for an element or condition which requires accessing the current index 
and its immediate right neighbor's index in the array.


Key Attributes:
* An advanced way to implement Binary Search.
* Search Condition needs to access element's immediate right neighbor
* Use element's right neighbor to determine if condition is met and decide whether to go left or right
* Gurantees Search Space is at least 2 in size at each step
* Post-processing required. Loop/Recursion ends when you have 1 element left. Need to assess if the remaining element meets the condition.

Distinguishing Syntax:
* Initial Condition: left = 0, right = length
* Termination: left == right
* Searching Left: right = mid
* Searching Right: left = mid+1
*/