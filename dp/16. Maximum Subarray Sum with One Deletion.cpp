#include<bits/stdc++.h>
using namespace std;

// dp[n][k] for if maximum k element is possible to delete
class Solution {
public:
    int maximumSum(vector<int>& arr) {
        const int n = arr.size();
        int answer = arr[0];
        int suf_del = arr[0];
        int suf_no_del = arr[0];
        for(int i=1;i<n;++i) {
            suf_del = max(suf_del+arr[i], suf_no_del);
            suf_no_del = max(suf_no_del+arr[i], arr[i]);
            answer = max({answer, suf_no_del, suf_del});
        }
        return answer;
    }
};
int main() {
	Solution obj;
	vector<int> arr = {1,-2,-2,3};
	int res = obj.maximumSum(arr);
	cout<<res<<endl;
	return 0;
}

// https://leetcode.com/problems/maximum-subarray-sum-with-one-deletion/

/*
1,-2,0,3

1,-2,-2,3

-1,-1,-1,-1
*/