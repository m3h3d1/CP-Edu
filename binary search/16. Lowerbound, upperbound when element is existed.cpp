#include "bits/stdc++.h"
using namespace std;

int bslowerbound(vector<int> v,int x) {
    int l=0, r=v.size()-1;
    int idx=-1;
    while(l<=r) {
        int mid=(l+r)/2;
        if(v[mid]>=x){
            if(v[mid]==x) idx=mid;
            r=mid-1;
        }
        else if(v[mid]<x) l=mid+1;
    }
    return idx;
}
int bsupperbound(vector<int> v,int x) {
    int l=0, r=v.size()-1;
    int idx=-1;
    while(l<=r) {
        int mid=(l+r)/2;
        if(v[mid]<=x){
            if(v[mid]==x) idx=mid;
            l=mid+1;
        }
        else if(v[mid]>x) r=mid-1;
    }
    return idx;
}
int main() {
    vector<int>vec;
    int target, n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        int val;
        scanf("%d",&val);
        vec.push_back(val);
    }
    scanf("%d",&target);

    cout<<bslowerbound(vec,target)<<endl;
    cout<<bsupperbound(vec,target)<<endl;
    return 0;
}

/*
input jodi hoy eirokom:
8
10 10 10 20 20 20 30 30
20

tahole lowerbound er dibe: 3 (3rd index)
upperbound dibe: 6 (6th index)
------------------------------------

ar eirokom input dile:
8
10 10 10 20 20 20 30 30
21

lowerbound, upperbound duitar e output: -1
(karon eikhane array te 21 exist kore nah)
*/