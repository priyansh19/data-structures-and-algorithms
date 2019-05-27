/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Priyanka
 *
 * Created on May 27, 2019, 3:13 PM
 */

#include <iostream>
using namespace std;
//For exp(x,n)
exp(int x,int n)
{
    if(n==0){ return 1;}

    else if(n%2==0)
    {
        int y=exp(x,n/2);
        return y*y;
    }
    else
    {
        return x*exp(x,n-1);
    }
}
int main() 
{

    cout<<"exp(4,3)= "<<exp(4,3)<<endl;
     cout<<"exp(3,3)= "<<exp(3,3);
    return 0;
}

