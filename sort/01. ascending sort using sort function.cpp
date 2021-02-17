#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {1, 5, 8, 9, 6, 7, 3, 4, 2, 0};
    int n = sizeof(arr)/sizeof(arr[0]); //to determine array size. here it is 40/4=10

    sort(arr, arr+n /* 10 */);

    cout << "\nArray after sorting using "
         "default sort is : \n";
    for (int i = 0; i < n /* 10 */; ++i)
        cout << arr[i] << " ";

    return 0;
}
