#include<bits/stdc++.h>
using namespace std;

int bs(vector<int>& v, int x) {
	if(v.size() == 0) return -1;
	int l = 0, r = v.size()-1;
	while(l+1<r) {
		int m = l+(r-l)/2;
		if(v[m] == x) return m;
		else if(v[m] < x) l = m;
		else r = m;
	}
	//post processing: l+1 == r
	if(v[l] == x) return l;
	if(v[r] == x) return r;
	return -1;
}
int main() {
	int a,b,n,T,cas=0;
	
	return 0;
}

/*
Template #3 is another unique form of Binary Search. 
It is used to search for an element or condition which requires accessing the current index and its immediate left and right neighbor's index in the array.

Key Attributes:
* An alternative way to implement Binary Search
* Search Condition needs to access element's immediate left and right neighbors
* Use element's neighbors to determine if condition is met and decide whether to go left or right
* Gurantees Search Space is at least 3 in size at each step
* Post-processing required. Loop/Recursion ends when you have 2 elements left. Need to assess if the remaining elements meet the condition.
 

Distinguishing Syntax:
* Initial Condition: left = 0, right = length-1
* Termination: left + 1 == right
* Searching Left: right = mid
* Searching Right: left = mid
*/