/* 
 * File:   main.cpp
 * Author: Priyanka
 *
 * Created on June 9, 2019, 4:35 AM
 */

#include <iostream>
using namespace std;
void printArray(int array[], int size)
{ 
 	int j;
	for (j = 0; j < size; j++)
	{
 	cout<<" "<< array[j];
 	}
 	cout<<endl;
}
void insertSort(int a[],int n,int i)
{
    int j,key;
    if(i<n)
    {
       j=i;
       while(j>0 && a[j-1]>a[j])
       {
           key=a[j];
           a[j]=a[j-1];
           a[j-1]=key;
           j--;           
       }
     
       insertSort(a,n,i+1);
    }
    
}

int main()
{
 int a[]={17,2,10,56,3,1,48,19,45,5};
 insertSort(a,10,0);
 printArray(a,10);
    
}

