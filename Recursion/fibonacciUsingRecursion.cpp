/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Priyanka
 *
 * Created on May 27, 2019, 7:02 AM
 */

#include <iostream>
using namespace std;

int fibonacci(int a)
{
    if(a<=1) return a;
    else
    {
        cout<<"Calculating fibonacci of "<<a<<endl;
        return fibonacci(a-1)+fibonacci(a-2);
        
    }
}
using namespace std;
int main() {
    int m=8;
    cout<< fibonacci(8);
}

