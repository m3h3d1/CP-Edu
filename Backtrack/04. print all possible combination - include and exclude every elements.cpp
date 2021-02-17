#include<stdio.h>
#include<algorithm>
using namespace std;
#define db(x) printf("%s is %d\n",#x,x);

void combination(int arr[],int n,int r,int data[],int indx,int i){
    int j;
    if(indx==r){
        for(j=0;j<r;j++) printf("%d ",data[j]);
        printf("\n");
        return;
    }
    if(i>=n) return;
    data[indx]=arr[i];
    //while(arr[i]==arr[i+1]) i++; //to handle duplicates, arr need to be sorted
    combination(arr,n,r,data,indx+1,i+1);
    combination(arr,n,r,data,indx,i+1);
}
int main(){
    int n,r;
    int arr[]={1,2,2,3,3};
    r=3;
    n=sizeof(arr)/sizeof(arr[0]);

    int data[r];
    //sort(arr,arr+n); //to handle duplicates
    combination(arr,n,r,data,0,0);
    return 0;
}

/*
We create a temporary array data[]. The idea here is similar to
Subset Sum Problem. We one by one consider every element of input array,
and recur for two cases:
1) The element is included in current combination (We put the element in data[] 
and incre-ment next available index in data[])
2) The element is excluded in current combination (We do not put the element and
do not change index)
When number of elements in data[] become equal to r (size of a combination),
we print it.
This method is mainly based on Pascal’s Identity, 
i.e. nCr = n-1 C r + n-1 C r-1
*/