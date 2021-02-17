#include<stdio.h>
#include<algorithm>
using namespace std;
#define db(x) printf("%s is %d\n",#x,x);

void combination(int arr[],int data[],int start,int end,int indx,int r){
    int i,j;
    //current combination is ready to be printed, print it
    if(indx==r){
        for(j=0;j<r;j++) printf("%d ",data[j]);
        printf("\n");
        return;
    }
    for(i=start;i<=end && end-i+1>=r-indx;i++){
        //while(arr[i]==arr[i+1]) i++; //to avoid duplicates, arr need to be sorted
        data[indx]=arr[i];
        combination(arr,data,i+1,end,indx+1,r);
    }
}
int main(){
    int r,n;
    int arr[]={1,2,2,3,3};
    r=3;
    n=sizeof(arr)/sizeof(arr[0]);

    int data[r];
    //sort(arr,arr+n); //to handle duplicates
    combination(arr,data,0,n-1,0,r);
    return 0;
}
/*
We create a temporary array ‘data[]’ which stores all outputs one by one.
The idea is to start from first index (index = 0) in data[],
one by one fix elements at this index and recur for remaining indexes.
Let the input array be {1, 2, 3, 4, 5} and r be 3. We first fix 1 at index
0 in data[], then recur for remaining indexes, then we fix 2 at index 0 and recur.
Finally, we fix 3 and recur for remaining indexes. 
When number of elements in data[] becomes equal to r 
(size of a combination), we print data[].
*/