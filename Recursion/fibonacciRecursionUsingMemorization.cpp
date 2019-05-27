/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Priyanka
 *
 * Created on May 27, 2019, 7:12 AM
 */

#include <iostream>
using namespace std;

int fibonacci(int a,int arr[])
{
    if(a<=1) return a;
    else
    {
        if(arr[a]!=-1)
        {
            cout<<"Retreiving fibonacci of "<<a<<endl;
             return arr[a];
        }
        else
        {
            cout<<"Storing fibonacci of "<<a<<endl;
            arr[a]=fibonacci(a-1,arr)+fibonacci(a-2,arr);
            return arr[a];
        }
       
        
    }
}
int main() {

    int arr[51];
    for(int i=0;i<51;i++)
    {
        arr[i]=-1;
    }
    cout<<fibonacci(7,arr);
}

