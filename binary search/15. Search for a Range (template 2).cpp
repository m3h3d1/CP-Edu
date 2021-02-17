//finding lower-bound & upper-bound
#include<bits/stdc++.h>
using namespace std;

int lowerBound(vector<int>& v, int x) {
    int l=0, r=v.size()-1;
    while(l<r) {
        int m = l+(r-l)/2;
        if(v[m] < x) l = m+1;
        else r = m;
    }
    if(v[l] == x) return l;
    return -1;
}
int upperBound(vector<int>& v, int x) {
    int l=0, r=v.size()-1;
    while(l<r) {
        int m = l+(r-l)/2+1; //#
        if(v[m] > x) r = m-1;
        else l = m;
    }
    if(v[r] == x) return r;
    return -1;
}
vector<int> searchRange(vector<int>& v, int x) {
    vector<int> res = {-1, -1};
    if(v.empty()) return res;
    res[0] = lowerBound(v, x);
    res[1] = upperBound(v, x);
    return res;
}
int main() {
    int a,b,n,T,cas=0;
    vector<int> v{5,7,7,8,8,10};
    vector<int> res = searchRange(v, 8);
    cout<<res[0]<<" "<<res[1];
    return 0;
}

/*
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
*/

/*
Binary search is evaluated agains a predicate for which the given array has this results

  5     7     7    8     8    10
false false false true true true
and we are looking for the first true in order to find first occurrence.

For finding the last occurrence then the evaluated predicate will give this

 5    7     7    8    8    10
true true true true true false
And we are looking for the last true element.
*/