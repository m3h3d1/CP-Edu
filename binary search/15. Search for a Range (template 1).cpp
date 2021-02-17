//finding lower-bound & upper-bound
#include<bits/stdc++.h>
using namespace std;

int lowerBound(vector<int>& v, int x) {
    int l=0, r=v.size()-1;
    int s=-1;
    while(l<=r) {
        int m = (l+r)/2;
        if(v[m] == x) {
            s = m;
            r = m-1;
        }
        else if(v[m] < x) l = m+1;
        else r = m-1;
    }
    return s;
}
int upperBound(vector<int>& v, int x) {
    int l=0, r=v.size()-1;
    int e=-1;
    while(l<=r) {
        int m = (l+r)/2;
        if(v[m] == x) {
            e = m;
            l = m+1;
        }
        else if(v[m] < x) l = m+1;
        else r = m-1;
    }
    return e;
}
vector<int> searchRange(vector<int>& v, int x) {
    vector<int> res = {-1, -1};
    if(res.empty()) return res;
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