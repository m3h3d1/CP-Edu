#include "bits/stdc++.h"
using namespace std;

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    do {
        res.push_back(nums);
    } while(next_permutation(nums.begin(), nums.end()));
    return res;
}
int main() {
    ios_base::sync_with_stdio(0);
    int a,b,n,T,cas=0;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;++i) cin>>nums[i];
    vector<vector<int>> res = permute(nums);
    for(vector<int> v: res) {
        for(int x: v) cout<<x<<" ";
        cout<<endl;
    } 
    return 0;
}

/*
3
1 3 2
*/