/* 
 * File:   main.cpp
 * Author: Priyanka
 *
 * Created on June 7, 2019, 9:24 PM
 */

//Note : we have to return only one peak point,more than one may exist
#include <iostream>
using namespace std;

int findPeakArray(int a[], int n, int low, int high) {
    //1. Find the mid element
    int mid = (low + high) / 2;

    //2. Compare it with the left and right element
    if ((mid == 0 || a[mid - 1] <= a[mid]) && (mid == n - 1 || a[mid + 1] <= a[mid])) {
        //Means mid is the peak
        return a[mid];
    } else if (mid > 0 && a[mid - 1] > a[mid]) {
        return findPeakArray(a, n, low, mid - 1);
    } else if (a[mid + 1] > a[mid]) {
        return findPeakArray(a, n, mid + 1, high);
    }
}

int findPeak(int a[], int n) {
    return findPeakArray(a, n, 0, n - 1);
}

int main() {
    int arr[] = {4, 5, 20, 45, 5, 9};
    int n = sizeof (arr) / sizeof (arr[0]);
    cout << "Index of a peak point is " << findPeak(arr, n);
    int array[] = {1, 10, 1, 5, 1, 20};
    cout << "\n Index of a peak point is " << findPeak(array, n);
    return 0;
}

