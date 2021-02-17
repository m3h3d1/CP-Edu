#include<bits/stdc++.h>
using namespace std;
int A[1000005];

int partition (int start ,int end) {
    int i = start + 1;
    int piv = A[start] ;            //make the first element as pivot element.
    for(int j=start+1; j<=end;j++)  {
    /*rearrange the array by putting elements which are less than pivot
       on one side and which are greater that on other. */

          if ( A[j] < piv) {
                swap (A[i],A [j]);
            	i += 1;
        }
   }
   swap ( A[start] ,A[i-1] ) ;  //put the pivot element in its proper place.
   return i-1;                      //return the position of the pivot
}
void quick_sort (int start , int end ) {
   if( start < end ) {
        //stores the position of pivot element
         int piv_pos = partition (start , end ) ;     
         quick_sort (start , piv_pos -1);    //sorts the left side of pivot.
         quick_sort (piv_pos +1 , end) ; //sorts the right side of pivot.
   }
}

int main() {
	int n;
	cin>>n;
	//int A[n+1];
	for(int i=0;i<n;++i) cin>>A[i];
	quick_sort(0, n-1);
	for(int i=0;i<n;++i) cout<<A[i]<<" ";
	return 0;
}

/*
12
73 32 72 49 45 33 45 29 7 28 99 31
*/

/*
Cormen

Quicksort(A, p, r)
	if(p<r)
		q = partition(A,p,r)
		Quicksort(A,p,q-1)
		Quicksort(A,q+1,r)
Partition(A,p,r)
	x = A[r]
	i = p-1;
	for j = p to r-1
		if A[j] <= x
			i++
			swap(A[i], A[j])
	swap(A[i+1], A[r]);
	return i+1
Worst Case Run Time = Θ(n2)
Average Case Run Time = Θ(n log n)
*/

/*
hackerearth

Select the first element of array as the pivot element First, we will see how the partition of the array takes place around the pivot. 

start: Leftmost position of the array
end: Rightmost position of the array
i: Boundary between the elements that are less than pivot and those greater than pivot
j: Boundary between the partitioned and unpartitioned part of array
*/


/*
The basic version of quick sort algorithm was invented by C. A. R. Hoare in 1960 and formally introduced quick sort in 1962.  It is used on the principle of divide-and-conquer. Quick sort is an algorithm of choice in many situations because it is not difficult to implement, it is a good "general purpose" sort and it consumes relatively fewer resources during execution.

 
Good points
It is in-place since it uses only a small auxiliary stack.
It requires only n log(n) time to sort n items.
It has an extremely short inner loop
This algorithm has been subjected to a thorough mathematical analysis, a very precise statement can be made about performance issues.

Bad Points
It is recursive. Especially if recursion is not available, the implementation is extremely complicated.
It requires quadratic (i.e., n2) time in the worst-case.
It is fragile i.e., a simple mistake in the implementation can go unnoticed and cause it to perform badly.
*/


/*
	Array of Same Elements:
Since all the elements are equal, the "less than or equal" teat in lines 6 and 8 in the PARTITION (A, p, r) will always be true. this simply means that repeat loop all stop at once. Intuitively, the first repeat loop moves j to the left; the second repeat loop moves i to the right. In this case, when all elements are equal, each repeat loop moves i and j towards the middle one space. They meet in the middle, so q= Floor(p+r/2). Therefore, when all elements in the array A[p . . r] have the same value equal to Floor(p+r/2).

 
	Performance of Quick Sort:
The running time of quick sort depends on whether partition is balanced or unbalanced, which in turn depends on which elements of an array to be sorted are used for partitioning.

A very good partition splits an array up into two equal sized arrays. A bad partition, on other hand, splits an array up into two arrays of very different sizes. The worst partition puts only one element in one array and all other elements in the other array. If the partitioning is balanced, the Quick sort runs asymptotically as fast as merge sort. On the other hand, if partitioning is unbalanced, the Quick sort runs asymptotically as slow as insertion sort.


	Best Case:
The best thing that could happen in Quick sort would be that each partitioning stage divides the array exactly in half. In other words, the best to be a median of the keys in A[p . . r] every time procedure 'Partition' is called. The procedure 'Partition' always split the array to be sorted into two equal sized arrays.

If the procedure 'Partition' produces two regions of size n/2. the recurrence relation is then

T(n) = T(n/2) + T(n/2) +  (n)
       = 2T(n/2) +  (n)

And from case 2 of Master theorem

        T(n) =  (n lg n)

 
	Worst case Partitioning:
The worst-case occurs if given array A[1 . . n] is already sorted. The PARTITION (A, p, r) call always return p so successive calls to partition will split arrays of length n, n-1, n-2, . . . , 2 and running time proportional to n + (n-1) + (n-2) + . . . + 2 = [(n+2)(n-1)]/2 =  (n2). The worst-case also occurs if A[1 . . n] starts out in reverse order.
*/