/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Priyanka
 *
 * Created on May 27, 2019, 7:08 AM
 */

#include <iostream>

using namespace std;
int main() {

    int m=8;
    int a=0;
    int b=1;int c;
    for(int i=2 ;i<=8;i++)
    {
        c=a+b;
        a=b;
        b=c;
    }
    cout<<c;
}

