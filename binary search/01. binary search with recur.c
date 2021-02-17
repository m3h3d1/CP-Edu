#include<stdio.h>
#define db(x) printf("%s is %d\n",#x,x);

int binaryS(int arr[],int x,int l,int r){
    if(l>r) return -1;
    int mid=(l+r)/2; /* or, l+(r-l)/2 */
    if(x==arr[mid]) return mid;
    else if(x>arr[mid]) binaryS(arr,x,mid+1,r);
    else if(x< arr[mid]) binaryS(arr,x,l,mid-1); /*if(arr[mid]>x) */
}
int main(){
    int arr[]={2,3,4,10,30,40,50,60};
    int n=sizeof(arr)/sizeof(arr[0]);
    int x=31;
    int res=binaryS(arr,x,0,n-1);
    res==-1 ? printf("element is not present\n")
            : printf("elsement is present at index %d\n",res);
    return 0;
}