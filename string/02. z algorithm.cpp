// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/
#include <bits/stdc++.h>
using namespace std;

vector<int> z_function_trivial(string s) {
    int n = s.size();
    vector<int> z(n);
    for (int i = 1; i < n; i++) {
        while (s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
    }
    return z;
}
class Solution {
public:
    vector<int> z_function(string s) {
        int n = s.size();
        vector<int> z(n);
        int l = 0, r = 0;
        for(int i = 1; i < n; i++) {
            if(i < r) {
                z[i] = min(r - i, z[i - l]);
            }
            while(s[z[i]] == s[i + z[i]]) {
                z[i]++;
            }
            if(i + z[i] > r) {
                l = i;
                r = i + z[i];
            }
        }
        return z;
    }

    int strStr(string text, string pattern) {
        string s = pattern + "$" + text;
        int n = s.size();
        int m = pattern.size();
        vector<int> z = z_function(s);
        for (int i = m + 1; i < n; i++) {
            if (z[i] == m) {
                return i - m - 1;
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;
    int ret = sol.strStr("sadbutsad", "sad");
    cout<<ret<<endl;
    return 0;
}