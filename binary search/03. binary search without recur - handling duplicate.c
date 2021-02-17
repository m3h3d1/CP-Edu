//for duplicate data exmple: 60,60,60
#include<stdio.h>
#define db(x) printf("%s is %d\n",#x,x);

int binaryS(int arr[],int x,int l,int r){
    int idx=-1,mid;
    while(l<=r){
        mid=(l+r)/2;
        if(x<=arr[mid]){
            if(x==arr[mid]) idx=mid;
            r=mid-1;
        }
        else if(x>arr[mid]) l=mid+1;
    }
    return idx;
}
int main(){
    int arr[]={2,3,4,10,40,50,60,60,60,80,90};
    int n=sizeof(arr)/sizeof(arr[0]);
    int x=60;
    int res=binaryS(arr,x,0,n-1);
    db(res);
    res==-1 ? printf("element is not present\n")
            : printf("element is present at index %d\n",res);
    return 0;
}