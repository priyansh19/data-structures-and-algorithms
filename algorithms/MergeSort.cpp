/* 
 * File:   main.cpp
 * Author: Priyanka
 *
 * Created on June 7, 2019, 9:52 PM
 */

#include <iostream>
using namespace std;

void printArray(int array[], int size) {
    int j;
    for (j = 0; j < size; j++) {
        cout << " " << array[j];
    }
    cout << endl;
}

void merge(int a[], int start, int mid, int end) {
    //start points to starting of array 1
    //mid+1 points to starting of array 2
    int b[end - start + 1];
    int k = 0, p = start, q = mid + 1;

    while (p <= mid && q <= end) {
        if (a[p] < a[q]) {
            b[k++] = a[p++];
        } else {
            b[k++] = a[q++];
        }
    }

    while (p <= mid) {
        b[k++] = a[p++];
    }

    while (q <= end) {
        b[k++] = a[q++];
    }

    for (int i = end; i >= start; i--) {
        a[i] = b[--k]; // copying back the sorted list to a[]

    }
}

void mergeSort(int a[], int start, int end) {
    int mid;
    if (start < end) {
        mid = (start + end) / 2;
        mergeSort(a, start, mid);
        mergeSort(a, mid + 1, end);
        merge(a, start, mid, end);
    }

}

int main() {
    int arr[] = {17, 2, 10, 56, 3, 1, 48, 19, 45, 5};
    int n = sizeof (arr) / sizeof (arr[0]);
    mergeSort(arr, 0, n - 1);
    printArray(arr, n);
}

