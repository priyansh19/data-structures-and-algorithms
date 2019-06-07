/* 
 * File:   main.cpp
 * Author: Priyanka
 *
 * Created on June 7, 2019, 9:50 PM
 */
#include <bits/stdc++.h> 
#include <iostream>
using namespace std;
const int MAX = 4;

int findPeakElement(int a[][MAX], int row, int col, int mid) {

    //Find the global maxima in the mid column
    int max = 0;
    for (int i = 1; i < row; i++) {
        if (a[i][mid] > a[max][mid]) {
            max = i;
        }
    }

    //Compare a[max][mid] with adjacent column elements
    if ((mid == 0 || a[max][mid] >= a[max][mid - 1]) && (mid == col - 1 || a[max][mid] >= a[max][mid + 1])) {
        return a[max][mid];
    } else if (mid > 0 && (a[max][mid] < a[max][mid - 1])) {
        return findPeakElement(a, row, col, mid - ceil((double) mid / 2));
    } else if (mid > 0 && (a[max][mid] < a[max][mid + 1])) {
        return findPeakElement(a, row, col, mid + ceil((double) mid / 2));
    }

}

int findPeak(int a[][MAX], int row, int col) {
    return findPeakElement(a, row, col, col / 2);
}

int main() {
    //Input a matrix
    int arr[][MAX] = {
        { 10, 8, 10, 10},
        { 14, 13, 12, 11},
        { 15, 9, 11, 21},
        { 16, 17, 19, 20}
    };
    int r = 4, c = 4;
    cout << "The peak element is " << findPeak(arr, r, c);

}

