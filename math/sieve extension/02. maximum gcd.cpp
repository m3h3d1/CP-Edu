#include<bits/stdc++.h>
using namespace std;
const int N = 1e6;
int cntA[N+9], cntB[N+9], lmulA[N+9], lmulB[N+9];

int main() {
    int a,b,n,x;
    cin>>n;

    //For each number from 1 to 1e6, store its largest multiple that is present in array A and B
    for(int i=0;i<n;++i) {
        cin>>x;
        cntA[x]++;
    }
    for(int i=0;i<n;++i) {
        cin>>x;
        cntB[x]++;
    }
    for(int i=1;i<=N;++i) {
        for(int j=i;j<=N;j+=i) {
            if(cntA[j]) lmulA[i] = j;
            if(cntB[j]) lmulB[i] = j;
        }
    }
    //Now, iterate for each number from 1 to 1e6, and find the largest number whose multiple is present in both the arrays. Lets say the number is mx.
    int mx = 0;
    for(int i=1;i<=N;++i) {
        if(lmulA[i] && lmulB[i]) mx = i;
    }

    //max gcd is present on lmulA[mx] or lmulB[mx]
    int mxGcd = lmulA[mx];
    cout<<mxGcd<<endl;
    return 0;
}

//https://www.hackerrank.com/contests/w34/challenges/maximum-gcd-and-sum/problem

/*
You are given two arrays  and  containing  elements each. Choose a pair of elements  such that:

 belongs to array .
 belongs to array .
 is the maximum of all pairs .
If there is more than one such pair  having maximum gcd, then choose the one with maximum sum. Print the sum of elements of this maximum-sum pair.
*/