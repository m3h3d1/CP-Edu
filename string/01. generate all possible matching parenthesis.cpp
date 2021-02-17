#include "bits/stdc++.h"
using namespace std;

void addingPar(vector<string> &v, string str, int n, int m) {
    if(n==0 && m==0) {
        v.push_back(str);
        return;
    }
    if(m>0) addingPar(v, str+")", n, m-1);
    if(n>0) addingPar(v, str+"(", n-1, m+1);
}
vector<string> generateParenthesis(int n) {
    vector<string> v;
    addingPar(v, "", n, 0);
    return v;
}
int main() {
	ios_base::sync_with_stdio(0);
	int a,b,n,T,cas=0;
	cin>>n;
	vector<string> v = generateParenthesis(n);
	for(string s: v) {
		cout<<s<<endl;
	}
	return 0;
}

// 1
// 2
// 3
// 4

/*
The idea is intuitive. Use two integers to count the remaining left parenthesis (n) and the right parenthesis (m) to be added. 
At each function call add a left parenthesis if n >0 and add a right parenthesis if m>0. 
Append the result and terminate recursive calls when both m and n are zero.
*/

// https://leetcode.com/problems/generate-parentheses/