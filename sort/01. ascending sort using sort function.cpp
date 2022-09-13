#include <bits/stdc++.h>
using namespace std;

int main()
{   
    string A[70];
    for(int i=0;i<64;++i) {
        cin>>A[i];
    }
    sort(A, A+64);
    cout<<endl;
    for(int i=0;i<64;++i) {
        cout<<A[i]<<endl;
    }
    return 0;
}
