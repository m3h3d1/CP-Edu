//* not sure
//lower bound
//if key is found than print it. else print the immediate small number
#include<iostream>
using namespace std;

int binarys(int arr[],int l,int r,int x) {
    int idx=-1;
    int temp=arr[l+(r-l)/2];
    while(l<=r) {
        int mid=l+(r-l)/2;
        if(arr[mid]==x){
            idx=mid;
            break;
        }
        else if(arr[mid]>x) r=mid-1;
        else if(arr[mid]<x){
            l=mid+1;
            if(arr[mid]>temp) temp=arr[mid];
        }
    }
    if(idx>=0) {
        //cout<<"yes";
        return arr[idx];
    }
    else {
        //cout<<temp;
        return temp;
    }
}
int main() {
    int a,b,n=6;
    int arr[]={1,2,3,4,6,7};
    int x=5;
    int res=binarys(arr,0,n-1,x);
    cout<<res;
    return 0;
}