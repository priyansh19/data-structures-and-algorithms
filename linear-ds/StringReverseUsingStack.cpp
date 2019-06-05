/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Priyanka
 *
 * Created on June 1, 2019, 10:48 AM
 */

//String reversal is not very efficient through stack since time and space complexity - both are O(n)

#include <iostream>
#include<stack>
#include<cstring>
using namespace std;

/*
 * 
 */

void printList(stack <int> s)
{
    while(!s.empty())
    {
        cout<<" "<<s.top();
        s.pop();
    }
    cout<<endl;
}

void reverseString(char *c)
{
    stack <char> s;
    for(int i=0;i<strlen(c);i++)
    {
        s.push(c[i]);
    }
    for(int i=0;i<strlen(c);i++)
    {
        c[i]=s.top();
        s.pop();
    }
    
}

int main() {

    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    printList(s);
    
    //String reversal using STack
    char c[]="Hey! How have you been";
    //22 is the length
    reverseString(c);
    cout<<c;
    
}

