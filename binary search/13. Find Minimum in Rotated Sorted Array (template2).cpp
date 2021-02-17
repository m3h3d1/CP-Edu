#include<bits/stdc++.h>
using namespace std;

//Template 2
int findMin(vector<int>& nums) {
    int l=0, r = nums.size()-1;
    while(l<r) {
        int m = (l+r)/2;
        if(nums[m]>nums[r]) l = m+1;
        else r = m;
    }
    return nums[l];
}
int main() {
    int a,b,n,T,cas=0;
    vector<int> v{4,5,6,7,0,1,2};
    int res = findMin(v);
    cout<<res<<endl;
    return 0;
}

/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).

Find the minimum element.

You may assume no duplicate exists in the array.

Example 1:
Input: [3,4,5,1,2] 
Output: 1

Example 2:
Input: [4,5,6,7,0,1,2]
Output: 0
*/