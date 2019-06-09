/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Priyanka
 *
 * Created on June 7, 2019, 9:52 PM
 */

#include <iostream>
using namespace std;
void printArray(int *array[], int size)
{ 
 	int j;
	for (j = 0; j < size; j++)
	{
 	cout<<" "<< array[j];
 	}
 	cout<<endl;
}
void insertSort(int a[],int n)
{
    
    for(int i=0;i<n;i++)
    {
        int j=i,key;
        while(j>0 && a[j-1]>a[j])
        {
            key = a[j];
            a[j]=a[j+1];
            a[j+1]=key;
            j--;
            
        }
       
    }
    	cout<< "Sorted Array: ";
	// print the sorted array
	printArray(a, n);
}

// function to print the given array 


using namespace std;
int main() {

    int a[]={17,2,10,56,2,1,48,19,45,5};
    insertSort(a,10);
}

