#include<bits/stdc++.h>
using namespace std;

int main() {
    int T, l, r, n;
    cin>>T;
    
    while(T--) {
        cin>>l>>r>>n;
        l++;
        string s="";
        while(l<=r) {
            int m=(l+r)/2;
            cout<<m<<'\n';
            fflush(stdout);
            
            cin>>s;
            if(s=="WRONG_ANSWER") return 0;
            else if(s=="TOO_BIG") r = m-1;
            else if(s=="TOO_SMALL") l = m+1;
            else break;
        }
    }
    return 0;;
}


/*
Practice Session 2018 - Google Code Jam 2018 - 
Number Guessing
https://codingcompetitions.withgoogle.com/codejam/round/0000000000000130/0000000000000523

We are thinking of an integer P within the range (A,B] — that is, A < P ≤ B. You have N tries to guess our number. After each guess that is not correct, we will tell you whether P is higher or lower than your guess.
*/