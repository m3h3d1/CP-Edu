#include "bits/stdc++.h"
using namespace std;

vector<int> initDiffArray(vector<int> &A) {
    int n = A.size();
    vector<int> D(n+1); // one extra space is used, because update(l, r, x) updates D[r+1] too.
    D[0] = A[0], D[n]=0;
    for(int i=1;i<n;++i) 
        D[i] = A[i] - A[i-1];
    return D;
}
void update(vector<int> &D, int l, int r, int x) {
    D[l] += x;
    D[r+1] -= x;
}
void printArray(vector<int> &A, vector<int> &D) {
    for(int i=0;i<A.size();++i) {
        if(i==0) A[i] = D[i];
        else A[i] = D[i] + A[i-1];
        cout<<A[i]<<" ";
    }
    cout<<endl;
}
int main() {
    ios_base::sync_with_stdio(0);
    int a,b,n,T,cas=0;
    vector<int> A{10, 5, 20, 40};
    vector<int> D = initDiffArray(A); // Initialize Difference Array
    update(D, 0, 1, 10); // update 10 in range [1, 10]
    printArray(A, D);
    update(D, 1, 3, 20); // update 20 in range [1, 3]
    update(D, 2, 2, 30); // update 30 in range [2, 2]
    printArray(A, D);
    return 0;
}