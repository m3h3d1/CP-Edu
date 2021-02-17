#include "bits/stdc++.h"
using namespace std;

bool isValid(string s) {
    stack<char> st;
    for(char ch: s) {
        if(ch=='(') st.push(')');
        else if(ch=='{') st.push('}');
        else if(ch=='[') st.push(']');
        else {
            if(st.size()==0 || st.top()!=ch) return 0;
            else st.pop();
        }
    }
    return st.size()==0;
}
int main() {
    ios_base::sync_with_stdio(0);
    int a,b,n,T,cas=0;
    string s;
    cin>>s;
    cout<<isValid(s);
    return 0;
}

/*
https://leetcode.com/problems/valid-parentheses/
(){}[]
(]
{[]}
[
*/