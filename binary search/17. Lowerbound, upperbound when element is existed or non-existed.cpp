#include "bits/stdc++.h"
using namespace std;

int lower_bound(int arr[], int n, int X) { 
    int l = 0; 
    int r = n; 
  
    // Till low is less than high 
    while (l < r) { 
        int mid = (l+r)/2; 
  
        // If X is less than or equal 
        // to arr[mid], then find in 
        // left subarray 
        if (X <= arr[mid]) { 
            r = mid; 
        } 
  
        // If X is greater arr[mid] 
        // then find in right subarray 
        else { 
            l = mid + 1; 
        } 
    } 
  
    // Return the lower_bound index 
    return l; 
}

int upper_bound(int arr[], int n, int X) { 
    int l = 0; 
    int r = n; 
  
    // Till low is less than high 
    while (l < r) { 
        // Find the middle index 
        int mid = (l+r)/2; 
  
        // If X is greater than or equal 
        // to arr[mid] then find 
        // in right subarray 
        if (X >= arr[mid]) { 
            l = mid + 1; 
        } 
  
        // If X is less than arr[mid] 
        // then find in left subarray 
        else { 
            r = mid; 
        } 
    } 
  
    // Return the upper_bound index 
    return l; 
} 

// Function to implement lower_bound 
// and upper_bound of X 
void printBound(int arr[], int n, int X) { 
    int idx; 
  
    // If lower_bound doesn't exists 
    if (lower_bound(arr, n, X) == n) { 
        printf("Lower bound doesn't exist"); 
    } 
    else { 
        // Find lower_bound 
        idx = lower_bound(arr, n, X); 
        printf("Lower bound of %d is %d at index % d\n ", X, arr[idx], idx); 
    } 
  
    // If upper_bound doesn't exists 
    if (upper_bound(arr, n, X) == n) { 
        printf("Upper bound doesn't exist"); 
    } 
    else { 
        // Find upper_bound 
        idx = upper_bound(arr, n, X); 
        printf("Upper bound of %d is %d at index % d\n ", X, arr[idx], idx); 
    } 
} 
  
int main() { 
    int arr[] = { 4, 6, 10, 12, 18, 20 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
  
    // Element whose lower bound and 
    // upper bound to be found 
    int X = 6; 
  
    // Function Call 
    printBound(arr, n, X); 

    printBound(arr, n, 7);
    return 0; 
}


/*
eikhane amader r=n newa lage karon output jokhon n asbe tokhon bujhte parobo je array te lowerbound/ upperbound exist kore nah
*/