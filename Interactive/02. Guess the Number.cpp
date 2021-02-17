#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int l=1, r=1e6;
    string s;
    int m=-1;
    while(l<r) {
        m=(l+r+1)/2;
        cout<<m<<'\n';
        fflush(stdout);
        
        cin>>s;
        if(s=="<") r = m-1;
        else l=m;
    } 
    cout<<"! "<<l<<'\n';
    return 0;;
}

/*
if m=(l+r)/2 is used then if l+1==r then code would run forever.

https://codeforces.com/blog/entry/45307
*/

/*
Guess the Number
https://codeforces.com/gym/101021/problem/1

In this problem there is some hidden number and you have to interactively guess it. The hidden number is always an integer from 1 and to 1 000 000.

You can make queries to the testing system. Each query is one integer from 1 to 1 000 000. Flush output stream after printing each query. There are two different responses testing program can provide:

string "<" (without quotes), if the hidden number is less than the integer in your query;
string ">=" (without quotes), if the hidden number is greater than or equal to the integer in your query.
When your program is sure that guessed the hidden number, print string "! x", where x is the answer, and terminate your program immediately after flushing the output stream.

Your program is allowed to make no more than 25 queries (not including printing the answer) to the testing system.
*/
