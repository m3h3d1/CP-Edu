#include <bits/stdc++.h>
#include<functional>
using namespace std;

int main(){
    int arr[] = {1, 5, 8, 9, 6, 7, 3, 4, 2, 0};
    int n = sizeof(arr)/sizeof(arr[0]);

    sort(arr, arr+n,greater<int>());
    cout << "\nArray after sorting using "
         "default sort is : \n";
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    getchar();
    return 0;
}

/*
greater<int>() caused me time limit once time
*/



////        How to sort in particular order?
////        We can also write our own comparator function and pass it as a third parameter.
//
//// A C++ program to demonstrate STL sort() using
//// our own comparator
//#include<bits/stdc++.h>
//using namespace std;
//
//// An interval has start time and end time
//struct Interval
//{
//    int start, end;
//};
//
//// Compares two intervals according to staring times.
//bool compareInterval(Interval i1, Interval i2)
//{
//    return (i1.start < i2.start);
//}
//
//int main()
//{
//    Interval arr[] =  { {6,8}, {1,9}, {2,4}, {4,7} };
//    int n = sizeof(arr)/sizeof(arr[0]);
//
//    // sort the intervals in increasing order of
//    // start time
//    sort(arr, arr+n, compareInterval);
//
//    cout << "Intervals sorted by start time : \n";
//    for (int i=0; i<n; i++)
//       cout << "[" << arr[i].start << "," << arr[i].end
//            << "] ";
//
//    return 0;
//}

//////Output:
//////
//////Intervals sorted by start time :
//////[1,9] [2,4] [4,7] [6,8]
